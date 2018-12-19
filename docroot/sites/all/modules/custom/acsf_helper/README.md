# [ACSF Helper Module](https://github.com/SU-SWS/acsf-cardinald7)
##### Version: 7.x-1.x

Changelog: [Changelog.md](CHANGELOG.md)

Description
---

The ACSF Helper module adjusts items so that sites can run in the ACSF environment.

Functionality
---

This module provides the following functionality:

1. Removes the circular dependency on `acsf_openid`. We don't need an ACSF authentication module; we brought our own.
2. Unsets the form elements at `admin/modules` for a number of modules that we don't want end users enabling.
3. Implements a redirect from `sites/default/files/*` to `sites/g/files/<acsf_site_id>/f/*`.
4. Modifies the `hook_form_alter()` implementations so that Paranoia has the last word.
5. Redirects to the UIT Stanford Sites service page for 404s on the sites.stanford.edu and people.stanford.edu sites.
6. Forces a site to load through its canonical URL (if set).

#### Force Loading through the Canonical URL

1. Run `drush vset acsf_helper_force_canonical_url 1` to enable this functionality
2. Run `drush vset acsf_helper_canonical_url <hostname.stanford.edu>`
3. Clear Drupal and Varnish caches

You can run `drush vset acsf_helper_force_canonical_url 0` and clear caches to disable this functionality.

Installation
---

Install this module like any other module. [See Drupal Documentation](https://drupal.org/documentation/install/modules-themes/modules-7)

Configuration
---

Nothing special needed.


Contribution / Collaboration
---

You are welcome to contribute functionality, bug fixes, or documentation to this module. If you would like to suggest a fix or new functionality you may add a new issue to the GitHub issue queue or you may fork this repository and submit a pull request. For more help please see [GitHub's article on fork, branch, and pull requests](https://help.github.com/articles/using-pull-requests)
