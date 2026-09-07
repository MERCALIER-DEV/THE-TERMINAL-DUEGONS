#include <iostream>
#include <string>
#include <vector>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>
#include "sit1_1.h"
#include "sit1_2.h"
#include "num_vercion.h"
using namespace ftxui;

enum class estadosit1_1{
        vivo,
        escapo,
        muerto1,
        muerto2,
    };

bool sit1_1(){

    auto screen = ScreenInteractive::Fullscreen();

    auto cabesera = hbox({
        text("Version: " + num_vercion) | flex,
        text("THE TERMINAL DUEGONS") | flex,
        text("nivel 1: El vestibulo oscuro") | flex,  
    })  |border;

    auto descripcion = hbox({
        paragraph("Estas en el vestibulo oscuro despues de un largo viaje,pensando en si realemente tenias que ir en lugar tan peligroso, ahora debes tomar una decision si irte de este sitio o entrar."),
    }) | flex | border;

    estadosit1_1 estado_actual = estadosit1_1::vivo;
   
    std::vector<std::string> opcines = {
        "Entrar al vestibulo oscuro",
        "Irte de este lugar",
    };
    int seleccion = 0;
    MenuOption menu_options;
    menu_options.on_enter = [&] {
        if (seleccion == 0) {
            estado_actual = estadosit1_1::vivo;
            
        } else if (seleccion == 1) {
            estado_actual = estadosit1_1::escapo;
            
        }
        screen.ExitLoopClosure()();
    };

    auto menu = Menu(&opcines, &seleccion, menu_options);

    auto renderer = Renderer(menu, [&]() {
        return vbox({
            cabesera,
           hbox({ menu->Render() | center | border,
            descripcion,
             }) | flex | border, 
        });
    });
    screen.Loop(renderer);

    if (estado_actual == estadosit1_1::vivo) {
         return true;
         // retorna true para indicar 
         // al jugador que ha pasado esa situacion y puede continuar con la historia
    }
    if (estado_actual == estadosit1_1::escapo) {
        auto screen = ScreenInteractive::Fullscreen();

    auto cabesera = hbox({
        text("Version: " + num_vercion) | flex,
        text("THE TERMINAL DUEGONS") | flex,
        text("nivel 1: El vestibulo oscuro") | flex,  
    })  |border;

    auto descripcion = hbox({
        paragraph("Decidiste ir te de este lugar, pero en tu huida te encuentras con un troll que te quiere matar por tu cobardia, como respondes"),
    }) | flex | border;

    estadosit1_1 estado_actual = estadosit1_1::vivo;
   
    std::vector<std::string> opcines = {
        "Enfrentar al troll con tu espada y tu escudo",
        "Evadir al troll y correr hacia la salida",
    };
    int seleccion = 0;
    MenuOption menu_options;
    menu_options.on_enter = [&] {
        if (seleccion == 0) {
            estado_actual = estadosit1_1::muerto1;
            
        } else if (seleccion == 1) {
            estado_actual = estadosit1_1::muerto2;   
        }
        screen.ExitLoopClosure()();
    };

    auto menu = Menu(&opcines, &seleccion, menu_options);

    auto renderer = Renderer(menu, [&]() {
        return vbox({
            cabesera,
           hbox({ menu->Render() | center | border,
            descripcion,
             }) | flex | border, 
        });
    });
    screen.Loop(renderer);
    }if (estado_actual == estadosit1_1::muerto1) {
        auto screen = ScreenInteractive::Fullscreen();
        auto cabesera = hbox({
        text("Version: " + num_vercion) | flex,
        text("THE TERMINAL DUEGONS") | flex,
        text("nivel 1: El vestibulo oscuro") | flex,  
    })  |border;

    auto descripcion = hbox({
        paragraph("Decidiste enfrentar al troll con tu espada y tu escudo, pero el troll era demasiado fuerte y te mato, ahora estas muerto."),
    }) | flex | border;

    auto renderer = Renderer(menu, [&]() {
        return vbox({
            cabesera,
           hbox({ 
            descripcion,
             }) | flex | border, 
        });
    });
    screen.Loop(renderer);
    return false;
    
    }if (estado_actual == estadosit1_1::muerto2) {
        auto screen = ScreenInteractive::Fullscreen();
        auto cabesera = hbox({
        text("Version: " + num_vercion) | flex,
        text("THE TERMINAL DUEGONS") | flex,
        text("nivel 1: El vestibulo oscuro") | flex,  
    })  |border;

    auto descripcion = hbox({
        paragraph("Decidiste evadir al troll y correr hacia la salida, pero el troll te alcanzo y te mato, ahora estas muerto."),
    }) | flex | border;
     auto renderer = Renderer(menu, [&]() {
        return vbox({
            cabesera,
           hbox({ 
            descripcion,
             }) | flex | border, 
        });
    });
    screen.Loop(renderer);
    return false;
    }

    return true;
}