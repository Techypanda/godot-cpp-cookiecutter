#include <godot_cpp/classes/project_settings.hpp>
#include <godot_cpp/classes/file_access.hpp>
#include <godot_cpp/classes/resource_loader.hpp>

#include "scene_settings.h"

constexpr char TITLESCREEN_SCENE[] = "{{cookiecutter.project_name}}/scene_settings/titlescreen_scene";
constexpr char GAMEWORLD_SCENE[] = "{{cookiecutter.project_name}}/scene_settings/gameworld_scene";

void register_setting(
	const godot::String& p_name,
	const godot::Variant& p_value,
	bool p_needs_restart,
	godot::PropertyHint p_hint,
	const godot::String& p_hint_string
) {
	godot::ProjectSettings* project_settings = godot::ProjectSettings::get_singleton();

	if (!project_settings->has_setting(p_name)) {
		project_settings->set(p_name, p_value);
	}

	godot::Dictionary property_info;
	property_info["name"] = p_name;
	property_info["type"] = p_value.get_type();
	property_info["hint"] = p_hint;
	property_info["hint_string"] = p_hint_string;

	project_settings->add_property_info(property_info);
	project_settings->set_initial_value(p_name, p_value);
	project_settings->set_restart_if_changed(p_name, p_needs_restart);

	static int32_t order = 0;
	project_settings->set_order(p_name, order++);
}

template<const char* str>
godot::String get_scene()
{
    godot::String path = godot::ProjectSettings::get_singleton()->get_setting_with_override(str);
    if (path.is_empty())
    {
        godot::print_error(str, " not set in project settings");
        return "";
    }

    return path;
}

void godot::SceneSettings::register_settings()
{
    ProjectSettings* project_settings = ProjectSettings::get_singleton();
    
    register_setting(TITLESCREEN_SCENE, "", false, PropertyHint::PROPERTY_HINT_FILE, "*.tscn,*.scn,*.res");
    register_setting(GAMEWORLD_SCENE, "", false, PropertyHint::PROPERTY_HINT_FILE, "*.tscn,*.scn,*.res");
}

godot::String godot::SceneSettings::get_game_world()
{
    return get_scene<GAMEWORLD_SCENE>();
}

godot::String godot::SceneSettings::get_titlescreen()
{
    return get_scene<TITLESCREEN_SCENE>();
}