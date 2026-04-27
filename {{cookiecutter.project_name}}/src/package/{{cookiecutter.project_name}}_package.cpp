#include "{{cookiecutter.project_name}}_package.h"

#include "settings_module.h"

using namespace godot;

void {{cookiecutter.project_name}}Package::load_modules()
{
    add_module<SettingsModule>();
}

void {{cookiecutter.project_name}}Package::initialize_{{cookiecutter.project_name}}_package(godot::ModuleInitializationLevel p_level)
{
    if (p_level != godot::MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

    load_modules();
    
    godot::print_line("{{cookiecutter.project_name}}Package: modules registered");
}

void {{cookiecutter.project_name}}Package::deload_modules()
{
}

void {{cookiecutter.project_name}}Package::uninit_{{cookiecutter.project_name}}_package(godot::ModuleInitializationLevel p_level) {
	if (p_level != godot::MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

    deload_modules();

    godot::print_line("{{cookiecutter.project_name}}Package: modules unregistered");
}
