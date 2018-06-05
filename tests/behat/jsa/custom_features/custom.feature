Feature: Custom Feature
  In order to ensure that the Jumpstart website custom content is visible
  As an end user
  I want to check for the existence of page and block content

  @live
  Scenario: Viewing a featured image on the About page
    Given I am on "about"
    Then I should see "Arcade on the Quad" in the "Content Body" region
