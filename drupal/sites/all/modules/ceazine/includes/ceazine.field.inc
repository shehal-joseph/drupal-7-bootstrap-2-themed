<?php
/**
 * @file
 * ceazine.field.inc
 */

/**
 * Create/delete custom fields function.
 */
function ceazine_manage_fields($action) {
  $fields = array();

#  // Exported field: 'node-ceazine-body'.
#  $fields['node-ceazine-body'] = array(
#    'field_config' => array(
#      'active' => '1',
#      'cardinality' => '1',
#      'deleted' => '0',
#      'entity_types' => array(
#        0 => 'node',
#      ),
#      'field_name' => 'body',
#      'foreign keys' => array(
#        'format' => array(
#          'columns' => array(
#            'format' => 'format',
#          ),
#          'table' => 'filter_format',
#        ),
#      ),
#      'indexes' => array(
#        'format' => array(
#          0 => 'format',
#        ),
#      ),
#      'locked' => '0',
#      'module' => 'text',
#      'settings' => array(),
#      'translatable' => '0',
#      'type' => 'text_with_summary',
#    ),
#    'field_instance' => array(
#      'bundle' => 'ceazine',
#      'default_value' => NULL,
#      'deleted' => '0',
#      'description' => '',
#      'display' => array(
#        'default' => array(
#          'label' => 'hidden',
#          'module' => 'text',
#          'settings' => array(),
#          'type' => 'text_default',
#          'weight' => '0',
#        ),
#        'teaser' => array(
#          'label' => 'hidden',
#          'module' => 'text',
#          'settings' => array(
#            'trim_length' => 600,
#          ),
#          'type' => 'text_summary_or_trimmed',
#          'weight' => '0',
#        ),
#      ),
#      'entity_type' => 'node',
#      'field_name' => 'body',
#      'label' => 'Body',
#      'required' => FALSE,
#      'settings' => array(
#        'display_summary' => TRUE,
#        'text_processing' => 1,
#        'user_register_form' => FALSE,
#      ),
#      'widget' => array(
#        'module' => 'text',
#        'settings' => array(
#          'rows' => 20,
#          'summary_rows' => 5,
#        ),
#        'type' => 'text_textarea_with_summary',
#        'weight' => '31',
#      ),
#    ),
#  );

  // Exported field: 'node-ceazine-field_ceazine_pdf_file'.
  $fields['node-ceazine-field_ceazine_pdf_file'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_ceazine_pdf_file',
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => '0',
      'module' => 'file',
      'settings' => array(
        'display_default' => 0,
        'display_field' => 0,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'file',
    ),
    'field_instance' => array(
      'bundle' => 'ceazine',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'file',
          'settings' => array(),
          'type' => 'file_default',
          'weight' => '2',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'file',
          'settings' => array(),
          'type' => 'file_default',
          'weight' => '2',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_ceazine_pdf_file',
      'label' => 'PDF File',
      'required' => 1,
      'settings' => array(
        'description_field' => 0,
        'file_directory' => 'ceaZine',
        'file_extensions' => 'pdf',
        'max_filesize' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'pdf_to_image',
        'settings' => array(
          'pdf_to_image' => array(
            'density' => '100x100',
            'extra_args' => '',
            'hide_imagefield' => 1,
            'target_field' => 'field_ceazine_pdf_images',
          ),
          'progress_indicator' => NULL,
        ),
        'type' => 'pdf_to_image',
        'weight' => '33',
      ),
    ),
  );

  // Exported field: 'node-ceazine-field_ceazine_pdf_images'.
  $fields['node-ceazine-field_ceazine_pdf_images'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '-1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_ceazine_pdf_images',
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => '0',
      'module' => 'image',
      'settings' => array(
        'default_image' => 0,
        'uri_scheme' => 'public',
      ),
      'translatable' => '0',
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'ceazine',
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'ceazine',
          'settings' => array(
            'ceazine_image_style' => '',
          ),
          'type' => 'ceazine',
          'weight' => '1',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'ceazine',
          'settings' => array(
            'ceazine_image_style' => '',
          ),
          'type' => 'ceazine',
          'weight' => '1',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_ceazine_pdf_images',
      'label' => 'PDF Images',
      'required' => 0,
      'settings' => array(
        'alt_field' => 0,
        'default_image' => 0,
        'file_directory' => 'ceazine',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '',
        'max_resolution' => '',
        'min_resolution' => '',
        'title_field' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'image',
        'settings' => array(
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'bar',
        ),
        'type' => 'image_image',
        'weight' => '32',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Body');
  t('PDF File');
  t('PDF Images');

  if ( $action == 'create' ){
  	foreach( $fields as $key=>$field ){
			$result = field_create_field($field['field_config']);
			if ( !$result ){
			  ceazine_install_error(t('Error creating field @field', array('@field'=>$field['field_config']['field_name'])));
			}
			$result = field_create_instance($field['field_instance']);
			if ( !$result ){
			  ceazine_install_error(t('Error creating instance of field @field', array('@field'=>$field['field_config']['field_name'])));
			}
		}
  }
  else{
		foreach ( $fields as $key=>$field ) {
		  if ( !field_delete_field($field['field_config']['field_name']) ){
		    ceazine_install_error(t('Error removing field @field', array('@field'=>$field['field_config']['field_name'])));
		  }
		}
		$instances = field_info_instances('node', 'ceazine');
		foreach ($instances as $instance_name => $instance) {
		  if ( !field_delete_instance($instance) ){
		    ceazine_install_error(t('Error removing instance @instance', array('@instance'=>$instance)));
		  }
		}
  }
}
