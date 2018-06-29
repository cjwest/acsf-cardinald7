#[Stanford Conference](https://github.com/SU-SWS/stanford_conference)
##### Version: 7.x-1.0-beta2

Maintainers: [jbickar](https://github.com/jbickar), [sherakama](https://github.com/sherakama)

[Changelog.txt](CHANGELOG.txt)

This module delivers a lightweight conference scheduling and display functionality. It includes two content types: Conference Overview and Conference Session. An Agenda page view is populated automatically when a Conference Session is entity referenced to a Conference Overview.

There is also a view at /conferences that lists all Conferences in reverse chronological order.

Installation
---

Install this module like any other module. [See Drupal Documentation](https://drupal.org/documentation/install/modules-themes/modules-7)

For issues with the wrong theme being loaded please review this patch:
https://www.drupal.org/files/issues/subpathauto-1814516-42.patch

Configuration
---

* Add a "well" class to the Contact block on the Conference Overview page.
* Add a "well" class to the Link to Overview sidebar block on the Agenda page.
* Configure Permissions as desired.

Troubleshooting
---

If you are experiencing issues with this module try reverting the feature first. If you are still experiencing issues try posting an issue on the GitHub issues page.

For issues with the wrong theme being loaded please review this patch:
https://www.drupal.org/files/issues/subpathauto-1814516-42.patch

Contribution / Collaboration
---

You are welcome to contribute functionality, bug fixes, or documentation to this module. If you would like to suggest a fix or new functionality you may add a new issue to the GitHub issue queue or you may fork this repository and submit a pull request. For more help please see [GitHub's article on fork, branch, and pull requests](https://help.github.com/articles/using-pull-requests)
