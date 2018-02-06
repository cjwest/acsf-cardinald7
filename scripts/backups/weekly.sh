#!/bin/bash
# Run `bash weekly.sh`
set -Ee
source includes/common.inc

# ###################################################
# VARIABLES
# ###################################################

# Available environment var examples:
#
# [HOME] => /home/cardinalsites
# [AH_SITE_GROUP] => cardinalsites
# [AH_SITE_NAME] => cardinalsites01live
# [AH_SITE_ENVIRONMENT] => 01live
# [AH_NON_PRODUCTION] => 1

STACK="cardinald7"
STACKDOMAIN="cardinalsites"
BACKUPDIR="/mnt/gfs/home/$STACK/$AH_SITE_ENVIRONMENT/backups/on-demand"
DAILYBACKUPDIR="$BACKUPDIR/daily"
WEEKLYBACKUPDIR="$BACKUPDIR/weekly"
DOCROOT="/var/www/html/$STACK.$AH_SITE_ENVIRONMENT/docroot"
SITELISTPATH="/mnt/files/$STACK$AH_SITE_ENVIRONMENT/files-private/sites.json"
TODAYSDATE=$(date +%Y%m%d)
NUMBEROFBACKUPSTOKEEP=5

# $SITELISTPATH holds information about all the sites. We manipulate it with
# grep to get a list of all *.stanford.edu sites.
SITES=`grep -o -P "[\w_-]*(\.$STACKDOMAIN)?.stanford.edu" $SITELISTPATH`

bak_rotate() {
  # Copy selected backup assets into a YYYYMMDD directory
  cp $DAILYBACKUPDIR/*.0.sql $WEEKLYBACKUPDIR/$TODAYSDATE/
  cp $DAILYBACKUPDIR/*.0.tar.gz $WEEKLYBACKUPDIR/$TODAYSDATE/

  # Rotate out the old
  NUMBEROFBACKUPSTOKEEP=$1
  WEEKLYBACKUPDIR=$2

  i=$1
  while [ $i -gt -1 ]
  do
    OLDER=$i
    NEWER=$[$i-1]
    NEWERPATH=$WEEKLYBACKUPDIR/weekly-archive.$NEWER.tar.gz
    OLDERPATH=$WEEKLYBACKUPDIR/weekly-archive.$OLDER.tar.gz

    # DB.
    if [ -f $NEWERPATH ]
    then
      mv $NEWERPATH $OLDERPATH
    fi

    # Iterate.
    i=$[$i-1]
  done

  # Remove the oldest backup. We start counting at 0 therefore we can just use the total.
  rm -f $WEEKLYBACKUPDIR/weekly-archive.$NUMBEROFBACKUPSTOKEEP.tar.gz

  # Create a tarball and put it at backups/on-demand/weekly/weekly-archive.0.tar.gz
  cd $WEEKLYBACKUPDIR
  tar -czf $WEEKLYBACKUPDIR/weekly-archive.0.tar.gz $TODAYSDATE/*

}

# ###################################################
# INIT • EXEC • START • GO
# ###################################################

# Create a YYYYMMDD directory. This also ensures that our weekly backup directory exists.
mkdir -p $WEEKLYBACKUPDIR/$TODAYSDATE

{ # try
  bak_rotate $NUMBEROFBACKUPSTOKEEP $WEEKLYBACKUPDIR &&
  bak_log_success "Weekly archive" $TODAYSDATE
} || { # catch
  bak_log_fail "Weekly archive" $TODAYSDATE
}

# Clean up.
rm -fr $WEEKLYBACKUPDIR/$TODAYSDATE
