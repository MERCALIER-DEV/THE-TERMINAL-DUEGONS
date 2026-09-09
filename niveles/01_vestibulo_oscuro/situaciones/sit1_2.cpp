#include <iostream>
#include <string>
#include <vector>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>
#include "sit1_2.h"
#include "num_vercion.h"

using namespace ftxui;

enum class estadosit1_2{
        vivo,
        pelio,
        pasillo_seguro,
        saludo,
    };

bool sit1_2(){

   auto screen = ScreenInteractive::Fullscreen();

    auto cabesera = hbox({
        text("Version: " + num_vercion) | flex,
        text("THE TERMINAL DUEGONS") | flex,
        text("nivel 1: El vestibulo oscuro") | flex,  
    })  |border;

    auto descripcion = hbox({
        paragraph("Entras con valentia y miedo al vestibulo oscuro de la mazmorra recordando la razon por la que estas aqui de todas formas no hay vuelta atras, al entrar ves un guardia de la mazmorra un pasillo seguro y otro que parece tener trampas, que vas hacer?."),
    }) | flex | border;

    estadosit1_2 estado_actual = estadosit1_2::vivo;
   
    std::vector<std::string> opcines = {
        "Peliar con el guardia",
        "Recorrer el pasillo seguro",
        "Recorrer el pasillo que parece que tiene trampas",
        "Saludar al guardia",
    };
    int seleccion = 0;
    MenuOption menu_options;
    menu_options.on_enter = [&] {
        if (seleccion == 0) {
            estado_actual = estadosit1_2::pelio;
     
        } else if (seleccion == 1) {
            estado_actual = estadosit1_2::pasillo_seguro;
            
        } else if (seleccion == 2){
             estado_actual = estadosit1_2::vivo;
        } else if (seleccion == 3){
             estado_actual = estadosit1_2::saludo;
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

   return true; 
}