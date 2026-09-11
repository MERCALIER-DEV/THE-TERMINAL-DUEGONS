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

        // ramificaciones muerte de pelea

        muerte_c,
        muerte_r,
        muerte_d,
        muerte_d1,

        // ramificaciones de pasillo seguro

        caminando,
        observar_bien,
        devolver,

        // ramificacines de muerte de caminando

        muerte_ca,

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
        "Hacer un giro con la espada",
        
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
    /* aqui termima la ramificacion si el jugador decide pelear con el guardia y hacer un contra ataque*************************************************************************************************************************************************** */ 
    /* *************************************************************************************************************************************************** */
    //y la ramificacion en caso de defensa****************************************************************************************************************************************************/
    if(estado_actual2 == estadosit1_2::defensa){

        auto screen_defensa = ScreenInteractive::Fullscreen();

    auto cabesera_defensa = hbox({
        text("Version: " + num_vercion) | flex,
        text("THE TERMINAL DUEGONS") | flex,
        text("nivel 1: El vestibulo oscuro") | flex,  
    })  |border;

    auto descripcion_defensa = hbox({
        paragraph("Estas a punto de defenderte, como lo vas a hacer?"),
    }) | flex | border;
   
    std::vector<std::string> opcines_defensa = {
        "usar un escudo para bloquear su alabarda",
        "tomar distancia y mantener una postura defensiva",
    };
    int seleccion_defensa = 0;

    MenuOption menu_options_defensa;
    menu_options_defensa.on_enter = [&] {
        if (seleccion_defensa == 0) {
            estado_actual2 = estadosit1_2::muerte_d;
     
        } else if (seleccion_defensa == 1) {
            estado_actual2 = estadosit1_2::muerte_d1;
            
        }
        screen_defensa.ExitLoopClosure()();
    };

    auto menu_defensa = Menu(&opcines_defensa, &seleccion_defensa, menu_options_defensa);

    auto renderer_defensa = Renderer(menu_defensa, [&]() {
        return vbox({
            cabesera_defensa,
           hbox({ menu_defensa->Render() | center | border,
            descripcion_defensa,
             }) | flex | border, 
        });
    });
    screen_defensa.Loop(renderer_defensa);
    }
    //****************************************************************************************************************************
    // ramificacion en caso de muerte por defensa con escudo***********************************************************************************************
    if(estado_actual2 == estadosit1_2::muerte_d){

        auto screen_md = ScreenInteractive::Fullscreen();

    auto cabesera_md = hbox({
        text("Version: " + num_vercion) | flex,
        text("THE TERMINAL DUEGONS") | flex,
        text("nivel 1: El vestibulo oscuro") | flex,  
    })  |border;

    auto descripcion_md = hbox({
        paragraph("A pesar de tu defensa, el guardia atraveso tu escudo con su alabarda y te clava en el pecho y mueres."),
    }) | flex | border;
   
    std::vector<std::string> opcines_md = {
        "Salir",
    };
    int seleccion_md = 0;

    MenuOption menu_options_md;
    menu_options_md.on_enter = [&] {
        if (seleccion_md == 0) {
            estado_actual2 = estadosit1_2::salir;
     
        } 
        screen_md.ExitLoopClosure()();
    };

    auto menu_md = Menu(&opcines_md, &seleccion_md, menu_options_md);

    auto renderer_md = Renderer(menu_md, [&]() {
        return vbox({
            cabesera_md,
           hbox({ menu_md->Render() | center | border,
            descripcion_md,
             }) | flex | border, 
        });
    });
    screen_md.Loop(renderer_md);
    if(estado_actual2 == estadosit1_2::salir) return false;
    }
    //****************************************************************************************************************************
    // ramificacion en caso de muerte por defensa con distanciamiento***********************************************************************************************
    if(estado_actual2 == estadosit1_2::muerte_d1){

        auto screen_md1 = ScreenInteractive::Fullscreen();

    auto cabesera_md1 = hbox({
        text("Version: " + num_vercion) | flex,
        text("THE TERMINAL DUEGONS") | flex,
        text("nivel 1: El vestibulo oscuro") | flex,  
    })  |border;

    auto descripcion_md1 = hbox({
        paragraph("A pesar de estar a distancia, el guardia lanza su alabarda y te atraviesa el pecho y mueres."),
    }) | flex | border;
   
    std::vector<std::string> opcines_md1 = {
        "Salir",
        
    };
    int seleccion_md1 = 0;

    MenuOption menu_options_md1;
    menu_options_md1.on_enter = [&] {
        if (seleccion_md1 == 0) {
            estado_actual2 = estadosit1_2::salir;
     
        } 
        screen_md1.ExitLoopClosure()();
    };

    auto menu_md1 = Menu(&opcines_md1, &seleccion_md1, menu_options_md1);

    auto renderer_md1 = Renderer(menu_md1, [&]() {
        return vbox({
            cabesera_md1,
           hbox({ menu_md1->Render() | center | border,
            descripcion_md1,
             }) | flex | border, 
        });
    });
    screen_md1.Loop(renderer_md1);
    if(estado_actual2 == estadosit1_2::salir) return false;
    }
    /* aqui termina la ramificacion si el jugador decide pelear con el guardia y hacer una defensa cualquiera*************************************************************************************************************************************************** */
    /******************************************************************************************************************************************************************************************************************************************************************* */
    /*y empieza la siguiente ramificacion de si el jugador decide atacar su rodilla*/
    if(estado_actual2 == estadosit1_2::rodilla){

        auto screen_rodilla = ScreenInteractive::Fullscreen();

    auto cabesera_rodilla = hbox({
        text("Version: " + num_vercion) | flex,
        text("THE TERMINAL DUEGONS") | flex,
        text("nivel 1: El vestibulo oscuro") | flex,  
    })  |border;

    auto descripcion_rodilla = hbox({
        paragraph("Estas a punto de atacar su rodilla, como lo vas a hacer?"),
    }) | flex | border;
   
    std::vector<std::string> opcines_rodilla = {
        "hacer una estocada a su rodilla",
        "hacer un corte  limpio a su rodilla",
        
    };
    int seleccion_rodilla = 0;

    MenuOption menu_options_rodilla;
    menu_options_rodilla.on_enter = [&] {
        if (seleccion_rodilla == 0) {
            estado_actual2 = estadosit1_2::muerte_r;
     
        } else if (seleccion_rodilla == 1) {
            estado_actual2 = estadosit1_2::muerte_r;
            
        }
        screen_rodilla.ExitLoopClosure()();
    };

    auto menu_rodilla = Menu(&opcines_rodilla, &seleccion_rodilla, menu_options_rodilla);

    auto renderer_rodilla = Renderer(menu_rodilla, [&]() {
        return vbox({
            cabesera_rodilla,
           hbox({ menu_rodilla->Render() | center | border,
            descripcion_rodilla,
             }) | flex | border, 
        });
    });
    screen_rodilla.Loop(renderer_rodilla);
    }
    /************************************************************************************************************************************ */
    /* ramificacion de muerte al atacar su rodilla************************************************************************************************/
    if(estado_actual2 == estadosit1_2::muerte_r){

        auto screen_mr = ScreenInteractive::Fullscreen();

    auto cabesera_mr = hbox({
        text("Version: " + num_vercion) | flex,
        text("THE TERMINAL DUEGONS") | flex,
        text("nivel 1: El vestibulo oscuro") | flex,  
    })  |border;

    auto descripcion_mr = hbox({
        paragraph("Te acercas al guardia para peliar con el, estando mas cerca ves que tiene una alabarda y una exelente armadura, el mismo se percata de tu presencia y apunta su arma hacia a ti, Que vas hacer?. "),
    }) | flex | border;
   
    std::vector<std::string> opcines_mr = {
        "hacer un contrataque despues de bloquear su alabarda",
        "mantener una postura defensiva",
        "atacar una fraja de su rodilla que la armadura no alcansa a cubrir",
    };
    int seleccion_mr = 0;

    MenuOption menu_options_mr;
    menu_options_mr.on_enter = [&] {
        if (seleccion_mr == 0) {
            estado_actual2 = estadosit1_2::contrataque;
     
        } 
        screen_mr.ExitLoopClosure()();
    };

    auto menu_mr = Menu(&opcines_mr, &seleccion_mr, menu_options_mr);

    auto renderer_mr = Renderer(menu_mr, [&]() {
        return vbox({
            cabesera_mr,
           hbox({ menu_mr->Render() | center | border,
            descripcion_mr,
             }) | flex | border, 
        });
    });
    screen_mr.Loop(renderer_mr);
    if(estado_actual2 == estadosit1_2::salir) return false;
    }
    //****************************************************************************************************************************************** */
    /*terminada las ramificacines de pelea ********************************************************************************************************/
    /*empiesa las ramificasiones de recorer el pasillo seguro**********************************************************************************************************************/

    if(estado_actual2 == estadosit1_2::pasillo_seguro){

        auto screen_ps = ScreenInteractive::Fullscreen();

    auto cabesera_ps = hbox({
        text("Version: " + num_vercion) | flex,
        text("THE TERMINAL DUEGONS") | flex,
        text("nivel 1: El vestibulo oscuro") | flex,  
    })  |border;

    auto descripcion_ps = hbox({
        paragraph("decides ir con sigilo por el pasillo seguro, ha pasado un rato, precientes peligro con tu instinto, que vas a hacer?"),
    }) | flex | border;
   
    std::vector<std::string> opcines_ps = {
        "Seguir caminando",
        "Observar muy bien al piso al caminar",
        "Devolverte por el pasillo",
    };
    int seleccion_ps = 0;

    MenuOption menu_options_ps;
    menu_options_ps.on_enter = [&] {
        if (seleccion_ps == 0) {
            estado_actual2 = estadosit1_2::caminando;
     
        } else if (seleccion_ps == 1) {
            estado_actual2 = estadosit1_2::observar_bien;
            
        } else if (seleccion_ps == 2){
             estado_actual2 = estadosit1_2::devolver;

        } 
        screen_ps.ExitLoopClosure()();
    };

    auto menu_ps = Menu(&opcines_ps, &seleccion_ps, menu_options_ps);

    auto renderer_ps = Renderer(menu_ps, [&]() {
        return vbox({
            cabesera_ps,
           hbox({ menu_ps->Render() | center | border,
            descripcion_ps,
             }) | flex | border, 
        });
    });
    screen_ps.Loop(renderer_ps);
    }
    /* ****************************************************************************************************************************************************** 
    se empisan las ramificaciones de esa caminar por el pasillo seguro *********************************************************************************** 
    ramificacion en caso de seguir caminando************************************************************************************************************** */

    if(estado_actual2 == estadosit1_2::caminando){

        auto screen_c = ScreenInteractive::Fullscreen();

    auto cabesera_c = hbox({
        text("Version: " + num_vercion) | flex,
        text("THE TERMINAL DUEGONS") | flex,
        text("nivel 1: El vestibulo oscuro") | flex,  
    })  |border;

    auto descripcion_c = hbox({
        paragraph("sigues caminando por el pasillo, tu instito te sigue diciendo que hay peligro y es mas fuerte que antes, que vas hacer?"),
    }) | flex | border;
   
    std::vector<std::string> opcines_c = {
        "Seguir caminando",
        "caminar con cautela",
    };
    int seleccion_c = 0;

    MenuOption menu_options_c;
    menu_options_c.on_enter = [&] {
        if (seleccion_c == 0) {
            estado_actual2 = estadosit1_2::muerte_ca;
     
        } else if (seleccion_c == 1) {
            estado_actual2 = estadosit1_2::muerte_ca;
            
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
    /************************************************************************************************************************************* 
     muerte al seguir caminando *******************************************************************************************************************/
     if(estado_actual2 == estadosit1_2::muerte_ca){

        auto screen_mca = ScreenInteractive::Fullscreen();

    auto cabesera_mca = hbox({
        text("Version: " + num_vercion) | flex,
        text("THE TERMINAL DUEGONS") | flex,
        text("nivel 1: El vestibulo oscuro") | flex,  
    })  |border;

    auto descripcion_mca = hbox({
        paragraph("Te acercas al guardia para peliar con el, estando mas cerca ves que tiene una alabarda y una exelente armadura, el mismo se percata de tu presencia y apunta su arma hacia a ti, Que vas hacer?. "),
    }) | flex | border;
   
    std::vector<std::string> opcines_mca = {
        "hacer un contrataque despues de bloquear su alabarda",
        "mantener una postura defensiva",
        "atacar una fraja de su rodilla que la armadura no alcansa a cubrir",
    };
    int seleccion_mca = 0;

    MenuOption menu_options_mca;
    menu_options_mca.on_enter = [&] {
        if (seleccion_mca == 0) {
            estado_actual2 = estadosit1_2::contrataque;
     
        } else if (seleccion_mca == 1) {
            estado_actual2 = estadosit1_2::defensa;
            
        } else if (seleccion_mca == 2){
             estado_actual2 = estadosit1_2::rodilla;

        } 
        screen_mca.ExitLoopClosure()();
    };

    auto menu_mca = Menu(&opcines_mca, &seleccion_mca, menu_options_mca);

    auto renderer_mca = Renderer(menu_mca, [&]() {
        return vbox({
            cabesera_mca,
           hbox({ menu_mca->render() | center | border,
            descripcion_mca,
             }) | flex | border, 
        });
    });
    screen_mca.Loop(renderer_mca);
    }
   return true; 
}
