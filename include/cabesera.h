#pragma once

#include <ftxui/screen/screen.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>
#include "num_vercion.h"

using namespace ftxui;

 inline auto cabesera1 = hbox({
        text("Version: " + num_vercion) | flex,
        text("THE TERMINAL DUEGONS") | flex,
        text("nivel 1: El vestibulo oscuro") | flex,  
    })  |border;

 inline auto cabesera2 = hbox({
        text("Version: " + num_vercion) | flex,
        text("THE TERMINAL DUEGONS") | flex,
        text("nivel 2: Corredores") | flex,  
    })  |border;

 inline auto cabesera3 = hbox({
        text("Version: " + num_vercion) | flex,
        text("THE TERMINAL DUEGONS") | flex,
        text("nivel 3: Profundidades") | flex,  
    })  |border;

inline auto cabesera4 = hbox({
        text("Version: " + num_vercion) | flex,
        text("THE TERMINAL DUEGONS") | flex,
        text("nivel 4: Calabozo retorcido") | flex,  
    })  |border;

inline auto cabesera5 = hbox({
        text("Version: " + num_vercion) | flex,
        text("THE TERMINAL DUEGONS") | flex,
        text("nivel 5: Trono Terminal") | flex,  
    })  |border;