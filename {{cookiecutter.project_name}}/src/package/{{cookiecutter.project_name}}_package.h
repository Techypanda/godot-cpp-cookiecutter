#pragma once

#include <functional>
#include <vector>
#include <godot_cpp/core/class_db.hpp>
#include "types/registerer.h"

namespace godot
{
    class {{cookiecutter.project_name}}Package final
    {
    public:
        template <Registerable T>
        static void add_module()
        {
            T::register_module();
        }

        template <Unregisterable T>
        static void remove_module()
        {
            T::unregister_module();
        }

        static void load_modules();
        static void deload_modules();
        static void initialize_{{cookiecutter.project_name}}_package(godot::ModuleInitializationLevel p_level);
        static void uninit_{{cookiecutter.project_name}}_package(godot::ModuleInitializationLevel p_level);
    };
}