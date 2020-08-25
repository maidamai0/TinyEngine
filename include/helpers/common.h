#pragma once

#include <functional>
#include <string>
#include <initializer_list>

using Handle = std::function<void()>;
using slist = std::initializer_list<std::string>;

#ifndef ROOT
#define ROOT "./"
#endif

std::string full_path(std::string&& name) {
    return std::string(ROOT) + name;
}