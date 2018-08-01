#!/bin/bash
# patch --no-backup-if-mismatch -p1 < patches/enforce-paranoia.patch
# patch --no-backup-if-mismatch -p1 < patches/core-profile-module-importance-max.patch
patch -Ns -r "" --no-backup-if-mismatch -p1 < patches/saml.htaccess.patch
patch -Ns -r "" --no-backup-if-mismatch -p1 < patches/combined.common.inc.patch
exit 0;
