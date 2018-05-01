<?php

/**
 * Local Database Defaults For Lando.
 */
$databases = array(
  'default' =>
  array(
    'default' =>
    array(
      'database' => getenv('DB_NAME') ?? 'drupal',
      'username' => getenv('DB_USER') ?? 'drupal',
      'password' => getenv('DB_PASSWORD') ?? 'drupal',
      'host' => getenv('DB_HOST') ?? 'database',
      'port' => getenv('DB_PORT') ?? 3306,
      'driver' => 'mysql',
      'prefix' => '',
    ),
  ),
);
