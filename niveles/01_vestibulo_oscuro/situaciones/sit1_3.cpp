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
    // estados normales o primarios (son las estdos que por si solos no definen el final del jigador y solo uno de ellos es el corrrecto al aplicar el estado vivo)

    vivo,
    exploro,
    puerta_hierro,
    pasillo_der,
    pasillo_izq,
    puerta_der,
    // puerta_izq, este estado es vivo por que ese es el correcto

    // ramificaciones de puerta de hierro
    pelear_d,
    pelear_b,
    pelear_a,


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
    ***********************************************************************************************************************************************
     deciones principales ************************************************************************************************************************ */

     if(estado_actual3 == estadosit1_3::exploro){
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
            estado_actual3 = estadosit1_3::puerta_hierro;
        }

        else if (seleccion_e = 1)
        {
            estado_actual3 = estadosit1_3::pasillo_izq;
        }
        
         else if (seleccion_e = 2)
        {
            estado_actual3 = estadosit1_3::pasillo_der;
        }

         else if (seleccion_e = 3)
        {
            estado_actual3 = estadosit1_3::puerta_der;
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
    }

    if(estado_actual3 == estadosit1_3::vivo) return true;

    /*****************************************************************************************************************************************************************
    *****************************************************************************************************************************************************************
    ramificaciones al pasar por la puerta de hierro ****************************************************************************************************************** */
     if(estado_actual3 == estadosit1_3::puerta_hierro)
     {

    auto screen_ph = ScreenInteractive::Fullscreen();

    auto descripcion_ph = hbox({
        paragraph("pasas por la puerta de hierro es bastante grande y hay un pasillo y lo recorres sientes peligro cerca poco despues aparecen monstruos de mazmorra hay un duende una bruja y una araña discutiemdo quien te va a maatar ya que los 3 te consideran muy debil incluso 1vs1, que vas a hacer?")
    });
   
    std::vector<std::string> opcines_ph = {
        "Pelear con el duende",
        "Pelear con la bruja",
        "Pelear con la araña",
    };
    int seleccion_ph = 0;
    MenuOption menu_options_ph;
    menu_options_ph.on_enter = [&] {
        if (seleccion_ph == 0)
        {
            estado_actual3 = estadosit1_3::pelear_d;
        }
        else if (seleccion_ph == 1)
        {
            estado_actual3 = estadosit1_3::pelear_b;
        }
        else if (seleccion_ph == 2)
        {
            estado_actual3 = estadosit1_3::pelear_a;
        }
        
        screen_ph.ExitLoopClosure()();
    };

    auto menu_ph = Menu(&opcines_ph, &seleccion_ph, menu_options_ph);

    auto renderer_ph = Renderer(menu_ph, [&]() {
        return vbox({
            cabesera1,
           hbox({ menu_ph->Render() | center | border,
            descripcion_ph,
             }) | flex | border, 
        });
    });
    screen_ph.Loop(renderer_ph);
    }



 return true;   
}