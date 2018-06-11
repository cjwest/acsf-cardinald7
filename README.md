# [ACSF Cardinal D7 Stack](https://github.com/SU-SWS/acsf-cardinald7)
##### Version: 7.x-1.x

[Changelog.txt](CHANGELOG.md)

Cardinal D7 Stack for Acquia Site Factory including all of our installation profiles as previously found on sites.stanford.edu.

The strategy behind this repository is to have the collection of installation
profiles collectively define the 'stack' rather than the other way around. Installation profiles can define in their composer.json files their dependencies and composer will sort out conflicts or common values and put everything in sites/all that is a common asset. All installation profiles will have access to everything in sites all so it is an opt-out approach to snowflakes.

TLDR; Local Installation
---

* Please note that `composer install` can take several minutes.

- `git clone git@github.com:SU-SWS/acsf-cardinald7.git`
- `cd acsf-cardinald7`
- `cp lando/example.env .env`
- `cp lando/example.lando.yml .lando.yml`
- (Uncomment the lines related to Behat testing in `lando.yml` if you wish to run Behat tests with Lando)
- `composer install`
- `composer init-lando`
- `lando start`
- `lando si` or `lando drush si [install profile name]`
- `lando drush uli`

Open the browser to your Lando localhost port or if you have the .sws domain set up: http://cardinald7.sws/

Site Factory Installation
---
- You may install one of these profiles through the administrative interface or
- You may navigate to /install.php and install through the Drupal UI.
- If you have your drush aliases installed and working you may use those to install.

### Git Subtree workflow

What is a subtree? https://www.atlassian.com/blog/git/alternatives-to-git-submodule-git-subtree

There are several subtrees in this project. You can see them by running:

```
git log | grep git-subtree-dir | tr -d ' ' | cut -d ":" -f2 | sort | uniq
```

Check out this article for more help: https://stackoverflow.com/questions/16641057/how-can-i-list-the-git-subtrees-on-the-root

*Pulling the latest from a subtree in to this project:*
- git subtree pull --prefix=docroot/profiles/[profile_name] --squash git@github.com:SU-SWS/[profile_name].git 7.x-6.x

*Pushing updates back up to the subtree:*
- git subtree push --prefix=docroot/profiles/[profile_name] --squash git@github.com:SU-SWS/[profile_name].git 7.x-6.x

# File Structure

## Where do I put...?

### Modules & themes for ACSF only
 - Ideally they would be tracked by composer.json but that might not make sense as they may only be required for this repository. That is ok, you can directly add and commit the module or theme to docroot/sites/all/modules/custom or docroot/sites/all/themes/custom and the preserve path composer plugin will not delete them on the next composer update or composer install.
### Modules & themes for everyone
 - composer.json or in to one of the preserved paths directly. See composer.json for a list of the preserved paths.
### Modules & themes specific to an installation profile
 - If an installation profile needs a specific version of a module or theme that is different from what is in sites/all you can opt-out by placing a different version in the profile's module or theme directory.
### Installation profiles
 - Add them as a subtree split with a composer.json file so that they can be included in the project root's composer.json file.
 - If it doesn't make sense for a subtree split the `docroot/profile` is under the preserve path and will keep your custom profile.
### Patches for modules
 - Composer can patch modules. This is the preferred way to patch modules.
### Patching Drupal core
 - Drupal core and composer are not good fellows. When patching core please create and place a patch in the `/patches` directory.
 - Edit `/scripts/updates/apply-patches.sh` to apply the patch.
 - Core is patched every time `composer update` or `composer install` is ran by a composer script hook.
### Drupal Scaffolding
 - Not used in Drupal 7.

## Where is?

### SAML Configuration
 - `/simplesamlphp/config/*`
### SSL Certs
 - `/simplesamlphp/cert/*``
### Patches For Core
 - `/patches`
### Drush plugins and aliases
 - `/drush`
### Lando Config and Environment Variables.
 - `/.env`
 - `/.lando.yml`

# How the heck?

## Do I update the composer packages
 - `composer update` should do the trick. Be patient. This take a while.
 - If prompted to re-install a package because of a missing .git repo answer yes
## Does composer figure out what is in the 'stack'
 - Each profile defines their own set of dependencies in a composer.json file. This project includes and merges all of those dependencies in to one big composer.json file and then executes the update or install.
 - When a conflict comes up between versions in the profiles composer will complain and give the developer a chance to adjust versions in the correct place.
## Does RA fit in to this?
 Because RA will only commit directly to Acquia infrastructure they will create new commits directly on their remote. If that commit is valid and you want to pull those updates in to this project you can. If RA changes a major version or changes a version of a module in a profile, the developer will have to push the code back upstream to the subtree.
## Do I get my working changes back up to the installation profiles?
 - Commit the changes with a good commit message to this repository and then push up using `git subtree push`
 - eg: `git subtree push --prefix=docroot/profiles/stanford_sites_jumpstart --squash git@github.com:SU-SWS/stanford_sites_jumpstart.git 7.x-6.x`
## Do I run behat tests?
 - TBD
## Do I find out what branch or tag a subtree is using?
 - I can't find documentation on this. For now, all subtrees are on 7.x-6.x except the stanford profile which is on 7.x-3.x
 - I have manually created a .gittrees file which is supposed to contain all of the information about the subtree.
## Do I add a new subtree
 - example: `git subtree add --prefix docroot/profiles/[profile_name] git@github.com:SU-SWS/[profile_name] 7.x-6.x --squash`
 - Then you can add the new profile's composer.json to the merge-plugin/require section in composer.json (line 115 roughly)
## Do I install an installation profile on the Factory
 - You can do so through the Factory UI.
 - You can do so through the Drupal UI at install.php
 - You can do so through drush using `drush si`
## Do I install diseval.so on ACSF?
 - TBD

# Notable items: READ THESE!

- Patched core to force the paranoia module to always be on. NO MATTER WHAT.
- Patched core to alter the importance of profile modules and themes. Instead of being less important than the stuff in sites/all a patch alters this behaviour and makes them more prominent. This allows for opt-out of stack behaviour
- Composer uses a mix of patches, preserve path, and merge plugins to accomplish what is in this repo. Please get familiar with them.
- Unlike other build systems, Acquia requires that all items be tracked in the repository and that is why you see both composer and have the items tracked.
- Diseval is installed on ACSF and to be conscious of the repurcussions of that on your development.
- Libraries use the 'package' type and this has repurcussions. Please see the highlighted notes at: https://getcomposer.org/doc/05-repositories.md#package-2
