<?php
/**
 * @file
 * Plugin style for radix_views_grid_plugin_style.
 */

/**
 * Class to define a style plugin handler.
 */
class RadixViewsGridPluginStyle extends views_plugin_style {
//  /**
//   * Definition.
//   */
//  public function option_definition() {
//    $options = parent::option_definition();
//    $options['alignment'] = array('default' => 'horizontal');
//    $options['columns'] = array('default' => 2);
//    return $options;
//  }
//
//  /**
//   * Form.
//   */
//  function options_form(&$form, &$form_state) {
//    parent::options_form($form, $form_state);
//
//    $form['alignment'] = array(
//      '#type' => 'radios',
//      '#title' => t('Alignment'),
//      '#options' => array(
//        'horizontal' => t('Horizontal'),
//        'vertical' => t('Vertical'),
//      ),
//      '#description' => t('Horizontal alignment will place items starting in the upper left and moving right.
//      Vertical alignment will place items starting in the upper left and moving down.'),
//      '#default_value' => $this->options['alignment'],
//    );
//
//    $options = array(1, 2, 3, 4, 6, 12);
//
//    $form['columns'] = array(
//      '#type' => 'select',
//      '#title' => t('Number of columns'),
//      '#options' => array_combine($options, $options),
//      '#required' => TRUE,
//      '#default_value' => $this->options['columns'],
//    );
//  }

  /**
   * Set default options
   */
  function options(&$options) {
    parent::options($options);
    $options['views_group_col_class'] = array('default' => 'col-md-12');
    $options['views_row_col_class'] = array('default' => 'col-md-12');
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    if (!empty($form['grouping'])) {
      $form['views_group_col_class'] = array(
        '#type' => 'textfield',
        '#title' => t('Group column class'),
        '#description' => t('The grid class to use for the group. Example: col-xs-12, col-md-6, col-lg-4.'),
        '#options' => array_combine($options, $options),
        '#required' => TRUE,
        '#default_value' => $this->options['views_group_col_class'],
      );
    } else {
      $form['views_group_col_class'] = array(
        '#type' => 'hidden',
        '#value' => $this->options['views_group_col_class']['default'],
      );
    }

    $form['views_row_col_class'] = array(
      '#type' => 'textfield',
      '#title' => t('Column class'),
      '#description' => t('The grid class to use for each views result. Example col-xs-12, col-md-6, col-lg-4.'),
      '#options' => array_combine($options, $options),
      '#required' => TRUE,
      '#default_value' => $this->options['views_row_col_class'],
    );
  }
}
