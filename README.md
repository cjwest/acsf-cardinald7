# [ACSF Cardinal D7 Stack](https://github.com/SU-SWS/acsf-cardinald7)
##### Version: 7.x-1.x

[Changelog.txt](CHANGELOG.md)

Cardinal D7 Stack for Acquia Site Factory including all of our installation profiles as previously found on sites.stanford.edu.

The strategy behind this repository is to have the collection of installation
profiles collectively define the 'stack' rather than the other way around. Installation profiles can define in their composer.json files their dependencies and composer will sort out conflicts or common values and put everything in sites/all that is a common asset.

TLDR; Local Installation
---

- git clone git@github.com:SU-SWS/acsf-cardinald7.git
- cd acsf-cardinald7
- composer install
- composer init-lando
- lando start
- lando si or lando drush si [install profile name]

Site Factory Installation
---
-


Contribution / Collaboration
---

### Git Subtree workflow

- TBD

# File Structure

## Where do I put...?

### Modules & themes for ACSF only
 - TBD
### Modules & themes for everyone
 - TBD
### Modules & themes specific to an installation profile
 - TBD
### Installation profiles
 - TBD
### Patches for modules
 - TBD
### Drupal core
 - TBD
### Drupal Scaffolding
 - TBD

## Where is?

### SAML Configuration
 - TBD
### SSL Certs
 - TBD
### Patches
 - TBD
### Drush plugins
 - TBD
### Lando Environment Variables
 - TBD

# How the heck?

## Do I update the composer packages
 - `composer update` should do the trick
 - If prompted to re-install a package because of a missing .git repo answer yes
## Does RA fit in to this mess?
 - TBD
## Does composer figure out what to put in to sites/all?
 - TBD
## Do I get my working changes back up to the installation profiles?
 - TBD
## Do I run behat tests?
 - TBD
