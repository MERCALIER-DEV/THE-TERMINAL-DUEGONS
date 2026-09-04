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
// situacion 1
    auto titulo = Renderer([&] {
        return hbox({
            text("Vercion: " + num_vercion),
            filler(),
            text("THE TERMINAL DUNGEON"),
            filler(),
            text("Nivel 1: Entrada a la mazmorra"),
        }) | border;
    });

    std::vector<std::string> opciones = {
        "Irte sin entrar a la mazmorra",
        "Entrar a la mazmorra",
    };

    int opcion_sit_1 = 0;

    MenuOption opciones_config;
    opciones_config.on_enter = [&] {
        pantalla.ExitLoopClosure()();
        if (opcion_sit_1 == 1) {
            
        } else if (opcion_sit_1 == 0) {
                
        }
    };

    auto menu = Menu(&opciones, &opcion_sit_1, opciones_config);

    auto decripcion_sit_1 = Renderer([&] {
        return vbox({
            text("Te encuentras frente a la entrada de la mazmorra, un lugar oscuro y peligroso."),
            text("¿Qué deseas hacer?"),
        }) | border;
    });

    auto menu_renderer = Renderer(menu,[&] {
        return vbox({
            titulo->Render(),
            decripcion_sit_1->Render(),
            menu->Render(),
            
        });
    });

    pantalla.Loop(menu_renderer);
// final de la situacion 1
}
