#include <iostream>
#include <string>
#include <vector>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>
#include "sit1_1.h"
#include "num_vercion.h"
using namespace ftxui;
bool sit1_1(){

    auto pantalla = ScreenInteractive::TerminalOutput();

    auto cabesera = hbox({
        text("Version: " + num_vercion) | flex,
        text("THE TERMINAL DUEGONS") | flex,
        text("nivel 1: El vestibulo oscuro") | flex,  
    })  |border;

    pantalla.Loop(Renderer ([&] {
        return cabesera;
    }));

    return true;
}
