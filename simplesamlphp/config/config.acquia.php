<?php

/**
 * Defines Acquia account specific options in $ah_options keys.
 *
 *   - 'database_name': Should be the Acquia Cloud workflow database name which
 *     will store SAML session information.set
 *     You can use any database that you have defined in your workflow.
 *     Use the database "role" without the stage ("dev", "stage", "test", etc.)
 *   - 'session_store': Define the session storage service to use in each
 *     Acquia environment ("memcache" or "database").
 */
$ah_options = array(
  'database_name' => $_ENV['AH_SITE_GROUP'],
  'session_store' => array(
    '02live' => 'database',
    '02test' => 'database',
    '02dev'  => 'database',
  ),
);

$ah_options['env'] = getenv('AH_SITE_ENVIRONMENT');

/**
 * Get session storage configuration defined by Acquia.
 *
 * @param array $config
 *   Current configuration.
 * @param array $ah_options
 *   Acquia account specific options.
 *
 * @return array
 *   Updated configuration.
 */
if (!function_exists('acquia_session_store_config')) {
  function acquia_session_store_config(array $config, array $ah_options) {
    if ($ah_options['session_store'][$ah_options['env']] == 'memcache') {
      $config = mc_session_store($config);
    }
    elseif ($ah_options['session_store'][$ah_options['env']] == 'database') {
      $config = sql_session_store($config, $ah_options['database_name']);
    }

    return $config;
  }
}

/**
 * Get logging configuration defined by Acquia.
 *
 * @param array $config
 *   Current configuration.
 *
 * @return array
 *   Updated configuration.
 */
if (!function_exists('acquia_logging_config')) {
  function acquia_logging_config(array $config) {
    $config['logging.handler'] = 'file';
    $config['loggingdir'] = dirname(getenv('ACQUIA_HOSTING_DRUPAL_LOG'));
    $config['logging.logfile'] = 'simplesamlphp-' . date('Ymd') . '.log';

    return $config;
  }
}

/**
 * Get memcache session storage config.
 *
 * @param array $config
 *   Current configuration.
 *
 * @return array
 *   Updated configuration.
 */
if (!function_exists('mc_session_store')) {
  function mc_session_store(array $config) {
    $config['store.type'] = 'memcache';
    $config['memcache_store.servers'] = mc_info();
    $config['memcache_store.prefix'] = $ah_options['database_name'];

    return $config;
  }
}

/**
 * Get memcache information.
 *
 * @return array
 *   Memcache server pool information.
 */
if (!function_exists('mc_info')) {
  function mc_info() {
    $creds_json = file_get_contents('/var/www/site-php/' . getenv('AH_SITE_NAME') . '/creds.json');
    $creds = json_decode($creds_json, TRUE);
    $mc_server = array();
    $mc_pool = array();
    foreach ($creds['memcached_servers'] as $fqdn) {
      $mc_server['hostname'] = preg_replace('/:.*?$/', '', $fqdn);
      array_push($mc_pool, $mc_server);
    }

    return array($mc_pool);
  }
}

/**
 * Set SQL database session storage.
 *
 * @param array $config
 *   Current configuration.
 * @param string $database_name
 *   The name of a MySQL database.
 *
 * @return array
 *   Updated configuration.
 */
if (!function_exists('sql_session_store')) {
  function sql_session_store(array $config, $database_name) {
    $creds = db_info($database_name);
    $config['store.type'] = 'sql';
    $config['store.sql.dsn'] = sprintf('mysql:host=%s;port=%s;dbname=%s', $creds['host'], $creds['port'], $creds['name']);
    $config['store.sql.username'] = $creds['user'];
    $config['store.sql.password'] = $creds['pass'];
    $config['store.sql.prefix'] = 'simplesaml';

    return $config;
  }
}

/**
 * Get SQL database information.
 *
 * @param string $db_name
 *   The name of a MySQL database.
 *
 * @return array
 *   Database information.
 */
if (!function_exists('db_info')) {
  function db_info($db_name) {
    $creds_json = file_get_contents('/var/www/site-php/' . getenv('AH_SITE_NAME') . '/creds.json');
    $databases = json_decode($creds_json, TRUE);
    $db = $databases['databases'][$db_name];
    $db['host'] = ($host = ah_db_current_host($db['db_cluster_id'])) ? $host : key($db['db_url_ha']);

    return $db;
  }
}

/**
 * Get the SQL database current host.
 *
 * @param string $db_cluster_id
 *   The MySQL database cluster id.
 *
 * @return string
 *   The database host to use if found else empty.
 */
if (!function_exists('ah_db_current_host')) {
  function ah_db_current_host($db_cluster_id) {
    require_once '/usr/share/php/Net/DNS2_wrapper.php';
    try {
      $resolver = new \Net_DNS2_Resolver([
        'nameservers' => [
          '127.0.0.1',
          'dns-master',
        ],
      ]);
      $response = $resolver->query("cluster-{$db_cluster_id}.mysql", 'CNAME');
      $cached_id = $response->answer[0]->cname;
    }
    catch (\Net_DNS2_Exception $e) {
      $cached_id = '';
    }

    return $cached_id;
  }
}

// Set log and temp location, as specified by Acquia.
$config['tempdir'] = '/mnt/tmp/' . $_ENV['AH_SITE_NAME'];
$config['logging.handler'] = 'file';
$config['loggingdir'] = $config['tempdir'];
$config['logging.logfile'] = 'simplesamlphp-' . date("Ymd") . '.log';

// GO.
$config = acquia_logging_config($config);
$config = acquia_session_store_config($config, $ah_options);
