<?php

/**
 * @file
 *   drush integration for easing.
 */

/**
 * The Easing plugin URI.
 */
define('EASING_DOWNLOAD_URI', 'http://gsgd.co.uk/sandbox/jquery/easing/jquery.easing.1.3.js');

/**
 * Implementation of hook_drush_command().
 *
 * In this hook, you specify which commands your
 * drush module makes available, what it does and
 * description.
 *
 * Notice how this structure closely resembles how
 * you define menu hooks.
 *
 * See `drush topic docs-commands` for a list of recognized keys.
 *
 * @return
 *   An associative array describing your command(s).
 */
function easing_drush_command() {
  $items = array();

  // the key in the $items array is the name of the command.
  $items['easing-plugin'] = array(
    'callback' => 'drush_easing_plugin',
    'description' => dt("Downloads the Easing plugin."),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH, // No bootstrap.
    'arguments' => array(
      'path' => dt('Optional. A path where to install the Easing plugin. If omitted Drush will use the default location.'),
    ),
    'aliases' => array('easingplugin'),
  );

  return $items;
}

/**
 * Implementation of hook_drush_help().
 *
 * This function is called whenever a drush user calls
 * 'drush help <name-of-your-command>'
 *
 * @param
 *   A string with the help section (prepend with 'drush:')
 *
 * @return
 *   A string with the help text for your command.
 */
function easing_drush_help($section) {
  switch ($section) {
    case 'drush:easing-plugin':
      return dt("Downloads the Easing plugin from colorpowered.com, default location is sites/all/libraries.");
  }
}

/**
 * Implements drush_MODULE_post_pm_enable().
 */
// function drush_easing_post_pm_enable() {
//   $modules = func_get_args();
//   if (in_array('easing', $modules)) {
//     drush_easing_plugin();
//   }
// }

/**
 * Command to download the Easing plugin.
 */
function drush_easing_plugin() {
  $filename = 'jquery.easing.1.3.js';
  $dirname = 'easing';
  if (!drush_shell_exec('type unzip')) {
    return drush_set_error(dt('Missing dependency: unzip. Install it before using this command.'));
  }

  $args = func_get_args();
  if (!empty($args[0])) {
    $path = $args[0];
  }
  else {
    $path = 'sites/all/libraries';
  }

  // Create the path if it does not exist.
  if (!is_dir($path)) {
    drush_op('mkdir', $path);
    drush_log(dt('Directory @path was created', array('@path' => $path)), 'notice');
  }

  // Create the plugin path if it does not exist.
  if (!is_dir("$path/$dirname")) {
    drush_op('mkdir', "$path/$dirname");
    drush_log(dt('Directory @dirname was created', array('@dirname' => $dirname)), 'notice');
  }

  // Set the directory to the download location.
  $olddir = getcwd();
  chdir("$path/$dirname");

  // Remove any existing Easing plugin directory
  if (is_dir($dirname)) {
    drush_log(dt('A existing Easing plugin was overwritten at @path', array('@path' => $path)), 'notice');
  }
  // Remove any existing Easing plugin zip archive
  if (is_file($filename)) {
    drush_op('unlink', $filename);
  }

  // Download the zip archive
  if (!drush_shell_exec('wget ' . EASING_DOWNLOAD_URI)) {
    drush_shell_exec('curl -O ' . EASING_DOWNLOAD_URI);
  }

  // Set working directory back to the previous working directory.
  chdir($olddir);

  if (is_dir($path . '/' . $dirname)) {
    drush_log(dt('Easing plugin has been downloaded to @path', array('@path' => $path)), 'success');
  }
  else {
    drush_log(dt('Drush was unable to download the Easing plugin to @path', array('@path' => "$path/$dirname")), 'error');
  }
}
