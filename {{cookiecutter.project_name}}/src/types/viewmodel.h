#pragma once

#include <concepts>

template <class T>
concept ViewModel = requires (T a)
{
    { a.Initialize() } -> std::convertible_to<void>;
};
