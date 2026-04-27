#pragma once

#include <godot_cpp/classes/packed_scene.hpp>

namespace godot
{
    class SceneSettings
    {
    public:
        static void register_settings();

        static godot::String get_game_world(); 
        static godot::String get_titlescreen();
    };
}