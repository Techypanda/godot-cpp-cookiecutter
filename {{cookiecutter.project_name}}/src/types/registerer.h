#pragma once

#include <concepts>

template <class T>
concept Registerable = requires
{
    { T::register_module() } -> std::same_as<void>;
};

template <class T>
concept Unregisterable = requires
{
    { T::unregister_module() } -> std::same_as<void>;
};