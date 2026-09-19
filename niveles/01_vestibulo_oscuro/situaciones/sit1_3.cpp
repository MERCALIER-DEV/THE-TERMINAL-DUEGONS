#include <iostream>
#include <string>
#include <vector>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>
#include "sit1_3.h"
#include "cabesera.h"

using namespace ftxui;

enum class estadosit1_3{
    // estados normales
    vivo,
    exploro,

};

bool sit1_3(){
    /* ***********************************************************************************************************************************************************
    empiesa la sit1_3 ********************************************************************************************************************************************
    ************************************************************************************************************************************************************** */
    auto screen3 = ScreenInteractive::Fullscreen();

    auto descripcion3 = hbox({
        paragraph("Pasaste por el pasillo con trampas, extrañamente se sentia seguro de atravesar, te encuentras en un sala amplia de ladrillos viejos y rotos parece una  zona segura de momento, que vas a hacer?")
    });

    estadosit1_3 estado_actual3 = estadosit1_3::vivo;
   
    std::vector<std::string> opcines3 = {
        "Explorar la sala",
    };
    int seleccion3 = 0;
    MenuOption menu_options3;
    menu_options3.on_enter = [&] {
        if (seleccion3 == 0) {
            estado_actual3 = estadosit1_3::exploro;
        } 
        screen3.ExitLoopClosure()();
    };

    auto menu3 = Menu(&opcines3, &seleccion3, menu_options3);

    auto renderer3 = Renderer(menu3, [&]() {
        return vbox({
            cabesera1,
           hbox({ menu3->Render() | center | border,
            descripcion3,
             }) | flex | border, 
        });
    });
    screen3.Loop(renderer3);
    /* *******************************************************************************************************************************************
     deciones principales ************************************************************************************************************************ */

     auto screen_e = ScreenInteractive::Fullscreen();

    auto descripcion_e = hbox({
        paragraph("exploras la sala, es bastante grande se ven muchas estatuas antiguas y de dioses, parece que esto no siempre fue una mazmorra, puede que haya sido un templo o castillo para algo grande, pero hay que tomar algun camino para seguir avansando por la mazmorra, encuentras varios caminos, cual recorres")
    });
   
    std::vector<std::string> opcines_e = {
        "Ir por la puerta grande de hierro",
        "ir por el pasillo que esta a tu izquierda",
        "ir por el pasillo que esta a la derecha",
        "ir por la puerta comun de madera de la derecha",
        "ir por la puerta comun de madera de la izquierda",
    };
    int seleccion_e = 0;
    MenuOption menu_options_e;
    menu_options_e.on_enter = [&] {

        if (seleccion_e == 0) 
        {
            estado_actual3 = estadosit1_3::vivo;
        }

        else if (seleccion_e = 1)
        {
            estado_actual3 = estadosit1_3::vivo;
        }
        
         else if (seleccion_e = 2)
        {
            estado_actual3 = estadosit1_3::vivo;
        }

         else if (seleccion_e = 3)
        {
            estado_actual3 = estadosit1_3::vivo;
        }

         else if (seleccion_e = 4)
        {
            estado_actual3 = estadosit1_3::vivo;
        }

        screen_e.ExitLoopClosure()();
    };

    auto menu_e = Menu(&opcines_e, &seleccion_e, menu_options_e);

    auto renderer_e = Renderer(menu_e, [&]() {
        return vbox({
            cabesera1,
           hbox({ menu_e->Render() | center | border,
            descripcion_e,
             }) | flex | border, 
        });
    });
    screen_e.Loop(renderer_e);

    if(estado_actual3 == estadosit1_3::vivo) return true;

 return true;   
}