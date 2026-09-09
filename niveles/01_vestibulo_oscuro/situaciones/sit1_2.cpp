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
        // estados normales
        vivo,
        pelio,
        pasillo_seguro,
        saludo,
        // ramificasines pelea
        contrataque,
        defensa,
        rodilla,
        muerte_c,
        muerte_r,
        muerte_d,

        salir,
    };

bool sit1_2(){
    //***************************************************************************************************************************************** */
    //Inicio de la situacion 2 ***********************************************************************************************************************
   auto screen2 = ScreenInteractive::Fullscreen();

    auto cabesera2 = hbox({
        text("Version: " + num_vercion) | flex,
        text("THE TERMINAL DUEGONS") | flex,
        text("nivel 1: El vestibulo oscuro") | flex,  
    })  |border;

    auto descripcion2 = hbox({
        paragraph("Entras con valentia y miedo al vestibulo oscuro de la mazmorra recordando la razon por la que estas aqui de todas formas no hay vuelta atras, al entrar ves un guardia de la mazmorra un pasillo seguro y otro que parece tener trampas, que vas hacer?."),
    }) | flex | border;

    estadosit1_2 estado_actual2 = estadosit1_2::vivo;
   
    std::vector<std::string> opcines2 = {
        "Peliar con el guardia",
        "Recorrer el pasillo seguro",
        "Recorrer el pasillo que parece que tiene trampas",
        "Saludar al guardia",
    };
    int seleccion2 = 0;
    MenuOption menu_options2;
    menu_options2.on_enter = [&] {
        if (seleccion2 == 0) {
            estado_actual2 = estadosit1_2::pelio;
     
        } else if (seleccion2 == 1) {
            estado_actual2 = estadosit1_2::pasillo_seguro;
            
        } else if (seleccion2 == 2){
             estado_actual2 = estadosit1_2::vivo;

        } else if (seleccion2 == 3){
             estado_actual2 = estadosit1_2::saludo;
        }
        screen2.ExitLoopClosure()();
    };

    auto menu2 = Menu(&opcines2, &seleccion2, menu_options2);

    auto renderer2 = Renderer(menu2, [&]() {
        return vbox({
            cabesera2,
           hbox({ menu2->Render() | center | border,
            descripcion2,
             }) | flex | border, 
        });
    });
    screen2.Loop(renderer2);
    
   // si eligio pelear ********************************************************************************************************************************
   //************************************************************************************************************************************************ */
    if(estado_actual2 == estadosit1_2::pelio){

        auto screen_pelio = ScreenInteractive::Fullscreen();

    auto cabesera_pelio = hbox({
        text("Version: " + num_vercion) | flex,
        text("THE TERMINAL DUEGONS") | flex,
        text("nivel 1: El vestibulo oscuro") | flex,  
    })  |border;

    auto descripcion_pelio = hbox({
        paragraph("Te acercas al guardia para peliar con el, estando mas cerca ves que tiene una alabarda y una exelente armadura, el mismo se percata de tu presencia y apunta su arma hacia a ti, Que vas hacer?. "),
    }) | flex | border;
   
    std::vector<std::string> opcines_pelio = {
        "hacer un contrataque despues de bloquear su alabarda",
        "mantener una postura defensiva",
        "atacar una fraja de su rodilla que la armadura no alcansa a cubrir",
    };
    int seleccion_pelio = 0;

    MenuOption menu_options_pelio;
    menu_options_pelio.on_enter = [&] {
        if (seleccion_pelio == 0) {
            estado_actual2 = estadosit1_2::contrataque;
     
        } else if (seleccion_pelio == 1) {
            estado_actual2 = estadosit1_2::defensa;
            
        } else if (seleccion_pelio == 2){
             estado_actual2 = estadosit1_2::rodilla;

        } 
        screen_pelio.ExitLoopClosure()();
    };

    auto menu_pelio = Menu(&opcines_pelio, &seleccion_pelio, menu_options_pelio);

    auto renderer_pelio = Renderer(menu_pelio, [&]() {
        return vbox({
            cabesera_pelio,
           hbox({ menu_pelio->Render() | center | border,
            descripcion_pelio,
             }) | flex | border, 
        });
    });
    screen_pelio.Loop(renderer_pelio);
    }

    //****************************************************************************************************************************
    // ramificacion de contraataque***********************************************************************************************
    if(estado_actual2 == estadosit1_2::contrataque){

            auto screen_c = ScreenInteractive::Fullscreen();

    auto cabesera_c = hbox({
        text("Version: " + num_vercion) | flex,
        text("THE TERMINAL DUEGONS") | flex,
        text("nivel 1: El vestibulo oscuro") | flex,  
    })  |border;

    auto descripcion_c = hbox({
        paragraph("Estas a punto de contraatacar, como lo vas a hacer?"),
    }) | flex | border;
   
    std::vector<std::string> opcines_c = {
        "Realizar un estocada",
        "Hacer un giro con la espado",
        
    };
    int seleccion_c = 0;

    MenuOption menu_options_c;
    menu_options_c.on_enter = [&] {
        if (seleccion_c == 0) {
            estado_actual2 = estadosit1_2::muerte_c;
     
        } else if (seleccion_c == 1) {
            estado_actual2 = estadosit1_2::muerte_c;
            
        } 
        screen_c.ExitLoopClosure()();
    };

    auto menu_c = Menu(&opcines_c, &seleccion_c, menu_options_c);

    auto renderer_c = Renderer(menu_c, [&]() {
        return vbox({
            cabesera_c,
           hbox({ menu_c->Render() | center | border,
            descripcion_c,
             }) | flex | border, 
        });
    });
    screen_c.Loop(renderer_c);
    }
    //fin contraataque para llevar a la muerte************************************************************************************
    //****************************************************************************************************************************
    if(estado_actual2 == estadosit1_2::muerte_c){

    auto screen_mc = ScreenInteractive::Fullscreen();

    auto cabesera_mc = hbox({
        text("Version: " + num_vercion) | flex,
        text("THE TERMINAL DUEGONS") | flex,
        text("nivel 1: El vestibulo oscuro") | flex,  
    })  |border;

    auto descripcion_mc = hbox({
        paragraph("A pesar de tu feroz contraataque, el guardia resulto muy poco herido y te clava su alabarda en tu cabeza y mueres."),
    }) | flex | border;
   
    std::vector<std::string> opcines_mc = {
        "Salir",   
    };
    int seleccion_mc = 0;

    MenuOption menu_options_mc;
    menu_options_mc.on_enter = [&] {
        if (seleccion_mc == 0) {
            estado_actual2 = estadosit1_2::salir;
     
        } 
        screen_mc.ExitLoopClosure()();
    };

    auto menu_mc = Menu(&opcines_mc, &seleccion_mc, menu_options_mc);

    auto renderer_mc = Renderer(menu_mc, [&]() {
        return vbox({
            cabesera_mc,
           hbox({ menu_mc->Render() | center | border,
            descripcion_mc,
             }) | flex | border, 
        });
    });
    screen_mc.Loop(renderer_mc);
    if(estado_actual2 == estadosit1_2::salir) return false;
    }
    /* aqui ter,ima la ramificacion si el jugador decide pelear con el guardia y hacer un contra ataque*************************************************************************************************************************************************** */ 
    /* *************************************************************************************************************************************************** */
   return true; 
}
