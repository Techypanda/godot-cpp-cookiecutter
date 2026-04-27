#include <godot_cpp/core/class_db.hpp>

#include "settings_module.h"

#include "scene_settings.h"

void godot::SettingsModule::register_module()
{
    SceneSettings::register_settings();
}

void godot::SettingsModule::unregister_module()
{
}