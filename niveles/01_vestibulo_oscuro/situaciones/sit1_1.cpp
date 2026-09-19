#include <iostream>
#include <string>
#include <vector>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>
#include "sit1_1.h"
#include "cabesera.h"
#include "num_vercion.h"
using namespace ftxui;

enum class estadosit1_1{
        vivo,
        escapo,
        muerto1,
        muerto2,
        salir,
    };

bool sit1_1(){

    auto screen = ScreenInteractive::Fullscreen();

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
            cabesera1,
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

     // se evalua al jugador para eligir la muerte apropiada segun sus decisiones    
    }else if  (estado_actual == estadosit1_1::escapo){
        auto screen_esp = ScreenInteractive::Fullscreen();

    auto descripcion_esp = hbox({
        paragraph("Decidiste ir te de este lugar, pero en tu huida te encuentras con un troll que te quiere matar por tu cobardia, como respondes"),
    }) | flex | border;
   // para que el jugador eliga su rama de muerte
    std::vector<std::string> opcines_esp = {
        "Enfrentar al troll con tu espada y tu escudo",
        "Evadir al troll y correr hacia la salida",
    };
    int seleccion_esp = 0;
    MenuOption menu_options_esp;
    menu_options_esp.on_enter = [&] {
        if (seleccion_esp == 0) {
            estado_actual = estadosit1_1::muerto1;
            
        } else if (seleccion_esp == 1) {
            estado_actual = estadosit1_1::muerto2;   
        }
        screen_esp.ExitLoopClosure()();
    };

    auto menu_esp = Menu(&opcines_esp, &seleccion_esp, menu_options_esp);

    auto renderer_esp = Renderer(menu_esp, [&]() {
        return vbox({
            cabesera1,
           hbox({ menu_esp->Render() | center | border,
            descripcion_esp,
             }) | flex | border, 
        });
    });
    screen_esp.Loop(renderer_esp);

    // si eligio 0 se ejucuta esta rama
    }if (estado_actual == estadosit1_1::muerto1) {
        auto screen0 = ScreenInteractive::Fullscreen();

    auto descripcion0 = hbox({
        paragraph("Decidiste enfrentar al troll con tu espada y tu escudo, pero el troll era demasiado fuerte y te mato, ahora estas muerto."),
    }) | flex | border;

     std::vector<std::string> opcines0 = {
        "Salir", 
    };
    int seleccion0 = 0;
    MenuOption menu_options0;
    menu_options0.on_enter = [&] {
        if (seleccion0 == 0) {
            estado_actual = estadosit1_1::salir;
        }
        screen0.ExitLoopClosure()();
    };

    auto menu0 = Menu(&opcines0, &seleccion0, menu_options0);

    auto renderer0 = Renderer(menu0, [&]() {
        return vbox({
            cabesera1,
           hbox({ menu0->Render() | center | border,
            descripcion0,
             }) | flex | border, 
        });
    });
    screen0.Loop(renderer0);
    if(estado_actual == estadosit1_1::salir)return false;
    
    // si eligio 1 se ejecuta esta rama
    }else if (estado_actual == estadosit1_1::muerto2) {
        auto screen1 = ScreenInteractive::Fullscreen();

    auto descripcion1 = hbox({
        paragraph("Decidiste evadir al troll y correr hacia la salida, pero el troll te alcanzo y te mato, ahora estas muerto."),
    }) | flex | border;

     std::vector<std::string> opcines1 = {
        "Salir", 
    };
    int seleccion1 = 0;
    MenuOption menu_options1;
    menu_options1.on_enter = [&] {
        if (seleccion1 == 0) {
            estado_actual = estadosit1_1::salir;
        }
        screen1.ExitLoopClosure()();
    };

    auto menu1 = Menu(&opcines1, &seleccion1, menu_options1);

     auto renderer1 = Renderer(menu1, [&]() {
        return vbox({
            cabesera1,
           hbox({ menu1->Render() | center | border,
            descripcion1,
             }) | flex | border, 
        });
    });
    
    screen1.Loop(renderer1);
    if(estado_actual == estadosit1_1::salir)return false;
    }
    return false;
}