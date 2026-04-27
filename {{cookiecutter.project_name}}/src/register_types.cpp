#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#include "register_types.h"

#include "package/{{ cookiecutter.project_name }}_package.h"

using namespace godot;

extern "C" {
// Initialization.
GDExtensionBool GDE_EXPORT {{ cookiecutter.project_name }}_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

	init_obj.register_initializer({{ cookiecutter.project_name }}Package::initialize_{{ cookiecutter.project_name }}_package);
	init_obj.register_terminator({{ cookiecutter.project_name }}Package::uninit_{{ cookiecutter.project_name }}_package);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}