// generated by Fast Light User Interface Designer (fluid) version 1.0302

#ifndef MainWindow_h
#define MainWindow_h
#include <FL/Fl.H>
#include "../MPluginScript/MPluginScript.h"
#include <FL/Fl_Double_Window.H>
extern void window_quit(Fl_Double_Window*, void*);
#include <FL/Fl_Menu_Bar.H>
extern void new_project_callback(Fl_Menu_*, void*);
extern void new_level_callback(Fl_Menu_*, void*);
extern void open_project_callback(Fl_Menu_*, void*);
extern void open_level_callback(Fl_Menu_*, void*);
extern void import_mesh_callback(Fl_Menu_*, void*);
extern void save_level_callback(Fl_Menu_*, long);
extern void quit_callback(Fl_Menu_*, void*);
extern void undo_callback(Fl_Menu_*, void*);
extern void redo_callback(Fl_Menu_*, void*);
extern void select_all_callback(Fl_Menu_*, void*);
extern void duplicate_object_callback(Fl_Menu_*, void*);
extern void delete_object_callback(Fl_Menu_*, void*);
extern void post_effects_setup_callback(Fl_Menu_*, void*);
extern void scene_setup_callback(Fl_Menu_*, void*);
extern void delete_scene_callback(Fl_Menu_*, void*);
extern void configuration_callback(Fl_Menu_*, void*);
extern void play_game_callback(Fl_Menu_*, void*);
extern void update_player_callback(Fl_Menu_*, void*);
extern void publish_callback(Fl_Menu_*, void*);
extern void add_mesh_callback(Fl_Menu_*, void*);
extern void add_light_callback(Fl_Menu_*, void*);
extern void add_text_callback(Fl_Menu_*, void*);
extern void add_camera_callback(Fl_Menu_*, void*);
extern void add_sound_callback(Fl_Menu_*, void*);
extern void add_scene_callback(Fl_Menu_*, void*);
extern void add_group_callback(Fl_Menu_*, void*);
extern void plugin_console_callback(Fl_Menu_*, void*);
extern void about_menu_callback(Fl_Menu_*, void*);
#include "GLBox.h"
#include "DnDTree.h"
extern void scene_tree_callback(DnDTree*, long);
#include <FL/Fl_Group.H>
#include <FL/Fl_Round_Button.H>
extern void set_edit_type(Fl_Round_Button*, long);
#include <FL/Fl_Choice.H>
#include <FL/Fl_Value_Input.H>
extern void rotation_speed_callback(Fl_Value_Input*, void*);
extern void translation_speed_callback(Fl_Value_Input*, void*);
#include <FL/Fl_Check_Button.H>
extern void ortho_callback(Fl_Check_Button*, void*);
extern void change_vue_callback(Fl_Menu_*, long);
#include <FL/Fl_Button.H>
extern void play_game_button_callback(Fl_Button*, void*);
extern void play_game_in_editor(Fl_Button*, void*);
extern void show_console_callback(Fl_Button*, void*);
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Input.H>
extern void edit_name_callback(Fl_Input*, void*);
extern void edit_object_callback(Fl_Value_Input*, long);
extern void edit_light_properties(Fl_Value_Input*, void*);
extern void choose_light_color(Fl_Button*, void*);
extern void edit_light_properties_chk_btn(Fl_Check_Button*, void*);
#include <FL/Fl_Clock.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Output.H>
extern void edit_object_chk_btn(Fl_Check_Button*, void*);
extern void edit_materials_callback(Fl_Button*, void*);
extern void edit_shape_callback(Fl_Menu_*, long);
extern void edit_object_properties(Fl_Value_Input*, void*);
extern void object_constraint_properties_callback(Fl_Button*, void*);
extern void edit_camera_properties(Fl_Value_Input*, void*);
extern void choose_camera_color(Fl_Button*, void*);
extern void edit_camera_properties_chk_btn(Fl_Check_Button*, void*);
extern void choose_fog_color(Fl_Button*, void*);
extern void edit_camera_skybox(Fl_Input*, void*);
extern void apply_editor_perspective(Fl_Button*, void*);
extern void set_editor_perspective(Fl_Button*, void*);
#include <FL/Fl_Text_Editor.H>
extern void edit_text_properties(Fl_Text_Editor*, void*);
extern void edit_text_properties(Fl_Input*, void*);
extern void text_find_font_callback(Fl_Button*, void*);
extern void edit_text_properties(Fl_Value_Input*, void*);
extern void text_alignment_callback(Fl_Menu_*, long);
extern void choose_text_color(Fl_Button*, void*);
extern void edit_sound_chk_btn(Fl_Check_Button*, void*);
extern void edit_sound_callback(Fl_Value_Input*, void*);
extern void new_scene_ok_callback(Fl_Button*, void*);
extern void new_scene_cancel_callback(Fl_Button*, void*);

class EditorWindow {
public:
  Fl_Double_Window* show_window();
  Fl_Menu_Bar *menu_bar;
  static unsigned char menu_menu_bar_i18n_done;
  static Fl_Menu_Item menu_menu_bar[];
  static Fl_Menu_Item *behavior_menu;
  GLBox *glbox;
  DnDTree *scene_tree;
  Fl_Group *edit_group;
  Fl_Choice *scenes_menu;
  Fl_Group *speed_group;
  Fl_Value_Input *rotation_speed;
  Fl_Value_Input *translation_speed;
  Fl_Check_Button *vue_ortho_button;
  static unsigned char menu__i18n_done;
  static Fl_Menu_Item menu_[];
  Fl_Input *name_edit;
  Fl_Value_Input *xpos_edit;
  Fl_Value_Input *ypos_edit;
  Fl_Value_Input *zpos_edit;
  Fl_Value_Input *xrot_edit;
  Fl_Value_Input *yrot_edit;
  Fl_Value_Input *zrot_edit;
  Fl_Value_Input *xscale_edit;
  Fl_Value_Input *yscale_edit;
  Fl_Value_Input *zscale_edit;
  Fl_Input *parent_edit;
  Fl_Tabs *special_tab;
  Fl_Scroll *behaviors_scroll;
  Fl_Double_Window* create_light_window();
  Fl_Double_Window *light_window_object;
  Fl_Value_Input *light_radius_edit;
  Fl_Value_Input *light_color_r;
  Fl_Value_Input *light_color_g;
  Fl_Value_Input *light_color_b;
  Fl_Value_Input *light_intensity_edit;
  Fl_Check_Button *light_spot_button;
  Fl_Value_Input *spot_angle_edit;
  Fl_Value_Input *light_spot_exponent;
  Fl_Check_Button *light_shadows_button;
  Fl_Value_Input *light_shadow_bias_edit;
  Fl_Value_Input *light_shadow_blur_edit;
  Fl_Value_Input *light_shadow_quality_edit;
  Fl_Double_Window* create_publish_window();
  Fl_Double_Window* create_object_window();
  Fl_Double_Window *object_embedded_window;
  Fl_Output *object_mesh_edit;
  Fl_Check_Button *object_invisible_button;
  Fl_Check_Button *object_shadow_button;
  Fl_Check_Button *object_occluder_button;
  Fl_Choice *object_shape_choice;
  static unsigned char menu_object_shape_choice_i18n_done;
  static Fl_Menu_Item menu_object_shape_choice[];
  Fl_Check_Button *object_ghost_button;
  Fl_Value_Input *object_mass_edit;
  Fl_Value_Input *object_fric_edit;
  Fl_Value_Input *object_rest_edit;
  Fl_Check_Button *object_physics_button;
  Fl_Value_Input *object_linear_damping_edit;
  Fl_Value_Input *object_angular_damping_edit;
  Fl_Value_Input *xlinear_edit;
  Fl_Value_Input *ylinear_edit;
  Fl_Value_Input *zlinear_edit;
  Fl_Value_Input *object_angular_factor_edit;
  Fl_Double_Window* create_camera_window();
  Fl_Value_Input *camera_color_r;
  Fl_Value_Input *camera_color_g;
  Fl_Value_Input *camera_color_b;
  Fl_Check_Button *camera_ortho_button;
  Fl_Value_Input *camera_fov_edit;
  Fl_Value_Input *camera_clipping_near_edit;
  Fl_Value_Input *camera_clipping_far_edit;
  Fl_Check_Button *camera_fog_button;
  Fl_Value_Input *camera_fog_distance_edit;
  Fl_Value_Input *fog_color_r;
  Fl_Value_Input *fog_color_g;
  Fl_Value_Input *fog_color_b;
  Fl_Input *camera_skybox_edit;
  Fl_Double_Window* create_text_window();
  Fl_Text_Editor *text_text_edit;
  Fl_Input *text_font_edit;
  Fl_Value_Input *text_size_edit;
  Fl_Choice *text_alignment_chooser;
  static unsigned char menu_text_alignment_chooser_i18n_done;
  static Fl_Menu_Item menu_text_alignment_chooser[];
  Fl_Value_Input *text_r;
  Fl_Value_Input *text_g;
  Fl_Value_Input *text_a;
  Fl_Value_Input *text_b;
  Fl_Double_Window* create_sound_window();
  Fl_Output *sound_file_edit;
  Fl_Check_Button *sound_loop_button;
  Fl_Value_Input *sound_pitch_edit;
  Fl_Value_Input *sound_gain_edit;
  Fl_Value_Input *sound_radius_edit;
  Fl_Value_Input *sound_rolloff_edit;
  Fl_Check_Button *sound_relative_button;
  /**
     Scene name to use when creating a new scene
  */
  std::string scene_name; 
  Fl_Double_Window* create_scene_window();
  Fl_Input *scene_name_input;
  MPluginScript* inputMethod; 
private:
  int systemColors[3]; 
public:
  int getSystemColor(int idx);
  bool m_deferredUiUpdate; 
};

class SceneSetupDlg {
public:
  static void ok_button_callback(Fl_Button* button, SceneSetupDlg* dlg);
  static void cancel_button_callback(Fl_Button* button, void*);
  static void find_file_callback(Fl_Button* button, void*);
  Fl_Double_Window* create_window();
  Fl_Input *scene_name_edit;
  Fl_Input *lua_script_edit;
  Fl_Value_Input *color_r;
  Fl_Value_Input *color_g;
  Fl_Value_Input *color_b;
  static void choose_light_color(Fl_Button* button, SceneSetupDlg* dlg);
  bool success; 
};
#include <FL/Fl_Text_Display.H>

class PlayerConsole {
public:
  Fl_Double_Window* create_window();
  Fl_Text_Display *output_edit;
  static void window_close_callback(Fl_Window* window, PlayerConsole* dlg);
  bool closed; 
  PlayerConsole();
};

class MaterialEditDlg {
  char object_name[256]; 
public:
  Fl_Double_Window* create_window(const char* name);
  Fl_Double_Window *window;
  Fl_Choice *materials_chooser;
  Fl_Value_Input *color_r;
  Fl_Value_Input *color_g;
  Fl_Value_Input *color_b;
  Fl_Value_Input *shininess_edit;
  Fl_Value_Input *opacity_edit;
  Fl_Value_Input *diffuse_r;
  Fl_Value_Input *diffuse_g;
  Fl_Value_Input *diffuse_b;
  Fl_Value_Input *specular_r;
  Fl_Value_Input *specular_g;
  Fl_Value_Input *specular_b;
  static void close_callback(Fl_Button* button, MaterialEditDlg* dlg);
  static void material_changed(Fl_Choice* choice, MaterialEditDlg* dlg);
  static void close_window_callback(Fl_Window* window, MaterialEditDlg* dlg);
  static void apply_callback(Fl_Button*, MaterialEditDlg* dlg);
  static void save_callback(Fl_Button*, MaterialEditDlg* dlg);
  static void choose_diffuse_color(Fl_Button* button, MaterialEditDlg* dlg);
  static void choose_specular_color(Fl_Button* button, MaterialEditDlg* dlg);
  static void choose_emit_color(Fl_Button* button, MaterialEditDlg* dlg);
};

class AboutDlg {
public:
  Fl_Double_Window* create_window();
  Fl_Box *editor_version_edit;
};

class PublishDlg {
  Fl_Window* window; 
public:
  Fl_Double_Window* create_window();
  Fl_Input *output_edit;
  Fl_Input *level_edit;
  static void publish_click(Fl_Button*, PublishDlg* dlg);
  static void cancel_click(Fl_Button*, PublishDlg* dlg);
  static void find_output_dir(Fl_Button*, PublishDlg* dlg);
  static void find_main_level(Fl_Button*, PublishDlg* dlg);
};
void new_scene_ok_callback(Fl_Button* button,void*);
void new_scene_cancel_callback(Fl_Button* button,void*);

class ConstraintPropertiesDlg {
  Fl_Window* win; 
public:
  Fl_Double_Window* create_window();
  Fl_Check_Button *enabled_button;
  Fl_Value_Input *xpivot_edit;
  Fl_Value_Input *ypivot_edit;
  Fl_Value_Input *zpivot_edit;
  Fl_Value_Input *xlinear_lower;
  Fl_Value_Input *ylinear_lower;
  Fl_Value_Input *zlinear_lower;
  Fl_Value_Input *xlinear_upper;
  Fl_Value_Input *ylinear_upper;
  Fl_Value_Input *zlinear_upper;
  Fl_Value_Input *xangular_lower;
  Fl_Value_Input *yangular_lower;
  Fl_Value_Input *zangular_lower;
  Fl_Value_Input *xangular_upper;
  Fl_Value_Input *yangular_upper;
  Fl_Value_Input *zangular_upper;
  Fl_Check_Button *parent_collision;
  Fl_Input *parent_input;
  static void enable_constraint_callback(Fl_Check_Button* button, ConstraintPropertiesDlg* dlg);
  static void close_callback(Fl_Button*, ConstraintPropertiesDlg* dlg);
  static void cancel_callback(Fl_Button*, ConstraintPropertiesDlg* dlg);
};
#include <FL/Fl_Browser.H>

class ConfigurationDlg {
  Fl_Text_Buffer text_buffer; 
public:
  Fl_Double_Window* create_window();
  Fl_Choice *theme_chooser;
  static unsigned char menu_theme_chooser_i18n_done;
  static Fl_Menu_Item menu_theme_chooser[];
  Fl_Value_Input *background_color_r;
  Fl_Value_Input *background_color_g;
  Fl_Value_Input *background_color_b;
  Fl_Value_Input *background2_color_r;
  Fl_Value_Input *background2_color_g;
  Fl_Value_Input *background2_color_b;
  Fl_Value_Input *foreground_color_r;
  Fl_Value_Input *foreground_color_g;
  Fl_Value_Input *foreground_color_b;
  Fl_Choice *lang_chooser;
  Fl_Choice *input_methods_choice;
  Fl_Browser *plugin_browser;
  Fl_Output *author_edit;
  Fl_Output *license_edit;
  Fl_Text_Display *description_edit;
  static void choose_background_color(Fl_Button*, ConfigurationDlg* dlg);
  static void choose_background2_color(Fl_Button*,ConfigurationDlg* dlg);
  static void choose_foreground_color(Fl_Button*,ConfigurationDlg* dlg);
  static void apply_settings_callback(Fl_Button*,ConfigurationDlg* dlg);
  static void setInputMethod(Fl_Menu_*, long idx);
  static void plugin_changed_callback(Fl_Browser*, ConfigurationDlg* dlg);
  static void reset_settings_callback(Fl_Button*,ConfigurationDlg* dlg);
};

class PostEffectsDlg {
public:
  Fl_Double_Window* create_window();
  Fl_Check_Button *use_post_effects;
  Fl_Value_Input *uniform_value;
  Fl_Browser *uniforms_browser;
  Fl_Button *add_uniform;
  Fl_Button *save_button;
  Fl_Button *load_button;
  Fl_Input *vert_shad_edit;
  Fl_Input *frag_shad_edit;
  Fl_Button *vert_btn;
  Fl_Button *frag_btn;
  Fl_Button *preview_btn;
  Fl_Value_Input *resolution_edit;
  static void uniform_select_callback(Fl_Browser* widget, PostEffectsDlg* dlg);
  static void find_vert_file_callback(Fl_Button* widget, PostEffectsDlg* dlg);
  static void find_frag_file_callback(Fl_Button* widget, PostEffectsDlg* dlg);
  static void preview_callback(Fl_Button* widget, PostEffectsDlg* dlg);
  static void use_post_effects_callback(Fl_Check_Button* widget, PostEffectsDlg* dlg);
  static void add_uniform_callback(Fl_Button*, PostEffectsDlg* dlg);
  Fl_Double_Window* new_uniform_window();
  Fl_Input *uniform_name_edit;
  Fl_Value_Input *uniform_value_edit;
  static void new_uniform_ok(Fl_Button* btn, PostEffectsDlg* dlg);
  static void new_uniform_cancel(Fl_Button* btn, PostEffectsDlg*);
  void update_uniform_list();
  static void update_uniform_float(Fl_Button* btn, PostEffectsDlg* dlg);
  static void save_profile_callback(Fl_Button* widget, PostEffectsDlg* dlg);
  static void load_profile_callback(Fl_Button* widget, PostEffectsDlg* dlg);
  static void update_resolution(Fl_Value_Input* value, PostEffectsDlg* dlg);
};

class WaitDlg {
public:
  Fl_Double_Window* create_window();
};
#endif
