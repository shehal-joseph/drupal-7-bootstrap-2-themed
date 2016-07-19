<?php
/**
 * @file
 * ceazine.content_type.inc
 */

/**
 * Create custom content type function.
 */
function ceazine_manage_custom_content_type(){
 $ceazine_custom_content = array(
  'type' => 'ceazine',
  'name' => t('ceaZine'),
  'base' => 'node_content',
  'description' => t('This is an node type for upload PDF documents, convert to images, and preview in a "booklet".'),
  'has_title' => '1',
  'title_label' => t('ceaZine'),
  'custom' => TRUE,
  );
  $content_type = node_type_set_defaults($ceazine_custom_content);
  $result = node_type_save($content_type);
  if ( $result != 1 ){
    ceazine_install_error(t('Error saving ceaZine node type'));
  }
}
