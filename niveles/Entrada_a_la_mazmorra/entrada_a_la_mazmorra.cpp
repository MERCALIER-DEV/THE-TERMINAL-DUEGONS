#include "entrada_a_la_mazmorra.h"
#include <iostream>
#include <string>
#include <vector>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>

using namespace ftxui;

bool muerte_sit_1();
bool muerte_sit_2();
bool entrada_a_la_mazmorra(){
    auto pantalla = ScreenInteractive::TerminalOutput();
// situacion 1
    auto titulo = Renderer([&] {
        return hbox({
            text("Vercion prototipo 0.1"),
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
             muerte_sit_1();   
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
// situacion 2
 auto pantalla = ScreenInteractive::TerminalOutput();

    auto titulo = Renderer([&] {
        return hbox({
            text("Vercion prototipo 0.1"),
            filler(),
            text("THE TERMINAL DUNGEON"),
            filler(),
            text("Nivel 1: Entrada a la mazmorra"),
        }) | border;
    });

    std::vector<std::string> opciones = {
        "Atacar al monstruo",
        "irte por un pasillo lateral",
        "Saludar al monstruo",
    };

    int opcion_sit_2 = 0;

    MenuOption opciones_config;
    opciones_config.on_enter = [&] {
        pantalla.ExitLoopClosure()();
        if (opcion_sit_2 == 0) {
            
        } else if (opcion_sit_2 == 1) {
            muerte_sit_2();
            
        }else if (opcion_sit_2 == 2) {
                
        }
    };

    auto menu = Menu(&opciones, &opcion_sit_2, opciones_config);

    auto decripcion_sit_2 = Renderer([&] {
        return vbox({
            text("Al entrar a la mazmorra, un monstruo esta patrullando, y hay un pasillo lateral que parece seguro."),
            text("¿Qué deseas hacer?"),
        }) | border;
    });

    auto menu_renderer = Renderer(menu,[&] {
        return vbox({
            titulo->Render(),
            decripcion_sit_2->Render(),
            menu->Render(),
            
        });
    });

    pantalla.Loop(menu_renderer);
    return true;
}    
bool muerte_sit_1(){
    auto pantalla = ScreenInteractive::TerminalOutput();

    auto titulo = Renderer([&] {
        return hbox({
            text("Vercion prototipo 0.1"),
            filler(),
            text("THE TERMINAL DUNGEON"),
            filler(),
            text("Nivel 1: Entrada a la mazmorra"),
        }) | border;
    });

    

    auto mensaje_muerte = Renderer([&] {
        return vbox({
            text("Por retirarte de la mazmorra, un monstruo aparece y te mata por cobarde."),
        }) | border;
    });

    

    pantalla.Loop(Renderer([&] {
        return vbox({
            titulo->Render(),
            mensaje_muerte->Render(),
        });
    }));
    return false;
}    
bool muerte_sit_2(){
    auto pantalla = ScreenInteractive::TerminalOutput();

    auto titulo = Renderer([&] {
        return hbox({
            text("Vercion prototipo 0.1"),
            filler(),
            text("THE TERMINAL DUNGEON"),
            filler(),
            text("Nivel 1: Entrada a la mazmorra"),
        }) | border;
    });

    

    auto mensaje_muerte = Renderer([&] {
        return vbox({
            text("Por retirarte de la mazmorra, un monstruo aparece y te mata por cobarde."),
        }) | border;
    });

    

    pantalla.Loop(Renderer([&] {
        return vbox({
            titulo->Render(),
            mensaje_muerte->Render(),
        });
    }));
    return false;
}






   
