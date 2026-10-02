#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>
#include "sit1_2.h"
#include "num_vercion.h"
#include "cabesera.h"
#include "cajas_dialogo.h"

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
    muerte_ob,
    muerte_de,

    //ramificaciones de muerte saludando
    muerte_s,

    salir,
};

bool sit1_2(){
    //***************************************************************************************************************************************** */
    //Inicio de la situacion 2 ***********************************************************************************************************************
    auto crear_dialogo = [&](const std::vector<std::string>& opciones,
                            int& seleccion,
                            const Elements& contenido,
                            std::function<void()> accion) {
        auto caja = std::make_shared<cajas_dialogo>();
        caja->textos = contenido;
        auto menu = caja->menu_sit(opciones, seleccion, std::move(accion));

        return Renderer(menu, [caja, menu]() {
            return vbox({
                cabesera1,
                hbox({ menu->Render() | center | border, caja->texto_sit() }) | flex | border,
            });
        });
    };

    auto screen2 = ScreenInteractive::Fullscreen();
    estadosit1_2 estado_actual2 = estadosit1_2::vivo;

    std::vector<std::string> opcines2 = {
        "Peliar con el guardia",
        "Recorrer el pasillo seguro",
        "Recorrer el pasillo que parece que tiene trampas",
        "Saludar al guardia",
    };
    int seleccion2 = 0;

    screen2.Loop(crear_dialogo(opcines2, seleccion2, {
        paragraph("Entras con valentia y miedo al vestibulo oscuro de la mazmorra recordando la razon por la que estas aqui de todas formas no hay vuelta atras, al entrar ves un guardia de la mazmorra un pasillo seguro y otro que parece tener trampas, que vas hacer?."),
    }, [&] {
        if (seleccion2 == 0) {
            estado_actual2 = estadosit1_2::pelio;
        } else if (seleccion2 == 1) {
            estado_actual2 = estadosit1_2::pasillo_seguro;
        } else if (seleccion2 == 2) {
            estado_actual2 = estadosit1_2::vivo;
        } else if (seleccion2 == 3) {
            estado_actual2 = estadosit1_2::saludo;
        }
        screen2.ExitLoopClosure()();
    }));

    // lo primero a evaluar en caso de haya elegido la opcion correcta
    if (estado_actual2 == estadosit1_2::vivo) return true;
    
    // si eligio pelear ********************************************************************************************************************************
    //************************************************************************************************************************************************ */
    if (estado_actual2 == estadosit1_2::pelio) {
        auto screen_pelio = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_pelio = {
            "hacer un contrataque despues de bloquear su alabarda",
            "mantener una postura defensiva",
            "atacar una fraja de su rodilla que la armadura no alcansa a cubrir",
        };
        int seleccion_pelio = 0;

        screen_pelio.Loop(crear_dialogo(opcines_pelio, seleccion_pelio, {
            paragraph("Te acercas al guardia para peliar con el, estando mas cerca ves que tiene una alabarda y una exelente armadura, el mismo se percata de tu presencia y apunta su arma hacia a ti, Que vas hacer?. "),
        }, [&] {
            if (seleccion_pelio == 0) {
                estado_actual2 = estadosit1_2::contrataque;
            } else if (seleccion_pelio == 1) {
                estado_actual2 = estadosit1_2::defensa;
            } else if (seleccion_pelio == 2) {
                estado_actual2 = estadosit1_2::rodilla;
            }
            screen_pelio.ExitLoopClosure()();
        }));
    }

    //****************************************************************************************************************************
    // ramificacion de contraataque***********************************************************************************************
    if (estado_actual2 == estadosit1_2::contrataque) {
        auto screen_c = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_c = {
            "Realizar un estocada",
            "Hacer un giro con la espada",
        };
        int seleccion_c = 0;

        screen_c.Loop(crear_dialogo(opcines_c, seleccion_c, {
            paragraph("Estas a punto de contraatacar, como lo vas a hacer?"),
        }, [&] {
            if (seleccion_c == 0 || seleccion_c == 1) {
                estado_actual2 = estadosit1_2::muerte_c;
            }
            screen_c.ExitLoopClosure()();
        }));
    }

    //fin contraataque para llevar a la muerte************************************************************************************
    //****************************************************************************************************************************
    if (estado_actual2 == estadosit1_2::muerte_c) {
        auto screen_mc = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_mc = { "Salir" };
        int seleccion_mc = 0;

        screen_mc.Loop(crear_dialogo(opcines_mc, seleccion_mc, {
            paragraph("A pesar de tu feroz contraataque, el guardia resulto muy poco herido y te clava su alabarda en tu cabeza y mueres."),
        }, [&] {
            if (seleccion_mc == 0) {
                estado_actual2 = estadosit1_2::salir;
            }
            screen_mc.ExitLoopClosure()();
        }));
        if (estado_actual2 == estadosit1_2::salir) return false;
    }

    //y la ramificacion en caso de defensa****************************************************************************************************************************************************/
    if (estado_actual2 == estadosit1_2::defensa) {
        auto screen_defensa = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_defensa = {
            "usar un escudo para bloquear su alabarda",
            "tomar distancia y mantener una postura defensiva",
        };
        int seleccion_defensa = 0;

        screen_defensa.Loop(crear_dialogo(opcines_defensa, seleccion_defensa, {
            paragraph("Estas a punto de defenderte, como lo vas a hacer?"),
        }, [&] {
            if (seleccion_defensa == 0) {
                estado_actual2 = estadosit1_2::muerte_d;
            } else if (seleccion_defensa == 1) {
                estado_actual2 = estadosit1_2::muerte_d1;
            }
            screen_defensa.ExitLoopClosure()();
        }));
    }

    //****************************************************************************************************************************
    // ramificacion en caso de muerte por defensa con escudo***********************************************************************************************
    if (estado_actual2 == estadosit1_2::muerte_d) {
        auto screen_md = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_md = { "Salir" };
        int seleccion_md = 0;

        screen_md.Loop(crear_dialogo(opcines_md, seleccion_md, {
            paragraph("A pesar de tu defensa, el guardia atraveso tu escudo con su alabarda y te clava en el pecho y mueres."),
        }, [&] {
            if (seleccion_md == 0) {
                estado_actual2 = estadosit1_2::salir;
            }
            screen_md.ExitLoopClosure()();
        }));
        if (estado_actual2 == estadosit1_2::salir) return false;
    }

    //****************************************************************************************************************************
    // ramificacion en caso de muerte por defensa con distanciamiento***********************************************************************************************
    if (estado_actual2 == estadosit1_2::muerte_d1) {
        auto screen_md1 = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_md1 = { "Salir" };
        int seleccion_md1 = 0;

        screen_md1.Loop(crear_dialogo(opcines_md1, seleccion_md1, {
            paragraph("A pesar de estar a distancia, el guardia lanza su alabarda y te atraviesa el pecho y mueres."),
        }, [&] {
            if (seleccion_md1 == 0) {
                estado_actual2 = estadosit1_2::salir;
            }
            screen_md1.ExitLoopClosure()();
        }));
        if (estado_actual2 == estadosit1_2::salir) return false;
    }

    /* aqui termina la ramificacion si el jugador decide pelear con el guardia y hacer una defensa cualquiera*************************************************************************************************************************************************** */
    /******************************************************************************************************************************************************************************************************************************************************************* */
    /*y empieza la siguiente ramificacion de si el jugador decide atacar su rodilla*/
    if (estado_actual2 == estadosit1_2::rodilla) {
        auto screen_rodilla = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_rodilla = {
            "hacer una estocada a su rodilla",
            "hacer un corte  limpio a su rodilla",
        };
        int seleccion_rodilla = 0;

        screen_rodilla.Loop(crear_dialogo(opcines_rodilla, seleccion_rodilla, {
            paragraph("Estas a punto de atacar su rodilla, como lo vas a hacer?"),
        }, [&] {
            if (seleccion_rodilla == 0 || seleccion_rodilla == 1) {
                estado_actual2 = estadosit1_2::muerte_r;
            }
            screen_rodilla.ExitLoopClosure()();
        }));
    }

    /************************************************************************************************************************************ */
    /* ramificacion de muerte al atacar su rodilla************************************************************************************************/
    if (estado_actual2 == estadosit1_2::muerte_r) {
        auto screen_mr = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_mr = { "Salir" };
        int seleccion_mr = 0;

        screen_mr.Loop(crear_dialogo(opcines_mr, seleccion_mr, {
            paragraph("estas a punto de atacar su rodilla, pero el guardia ataca mas rapido que tu y mueres"),
        }, [&] {
            if (seleccion_mr == 0) {
                estado_actual2 = estadosit1_2::salir;
            }
            screen_mr.ExitLoopClosure()();
        }));
        if (estado_actual2 == estadosit1_2::salir) return false;
    }

    //****************************************************************************************************************************************** */
    /*terminada las ramificacines de pelea ********************************************************************************************************/
    /*empiesa las ramificasiones de recorer el pasillo seguro**********************************************************************************************************************/
    if (estado_actual2 == estadosit1_2::pasillo_seguro) {
        auto screen_ps = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_ps = {
            "Seguir caminando",
            "Observar muy bien al piso al caminar",
            "Devolverte por el pasillo",
        };
        int seleccion_ps = 0;

        screen_ps.Loop(crear_dialogo(opcines_ps, seleccion_ps, {
            paragraph("decides ir con sigilo por el pasillo seguro, ha pasado un rato, precientes peligro con tu instinto, que vas a hacer?"),
        }, [&] {
            if (seleccion_ps == 0) {
                estado_actual2 = estadosit1_2::caminando;
            } else if (seleccion_ps == 1) {
                estado_actual2 = estadosit1_2::observar_bien;
            } else if (seleccion_ps == 2) {
                estado_actual2 = estadosit1_2::devolver;
            }
            screen_ps.ExitLoopClosure()();
        }));
    }

    /* ****************************************************************************************************************************************************** 
    se empisan las ramificaciones de esa caminar por el pasillo seguro *********************************************************************************** 
    ramificacion en caso de seguir caminando************************************************************************************************************** */
    if (estado_actual2 == estadosit1_2::caminando) {
        auto screen_c = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_c = {
            "Seguir caminando",
            "caminar con cautela",
        };
        int seleccion_c = 0;

        screen_c.Loop(crear_dialogo(opcines_c, seleccion_c, {
            paragraph("sigues caminando por el pasillo, tu instito te sigue diciendo que hay peligro y es mas fuerte que antes, que vas hacer?"),
        }, [&] {
            if (seleccion_c == 0 || seleccion_c == 1) {
                estado_actual2 = estadosit1_2::muerte_ca;
            }
            screen_c.ExitLoopClosure()();
        }));
    }

    /************************************************************************************************************************************* 
     muerte al seguir caminando *******************************************************************************************************************/
    if (estado_actual2 == estadosit1_2::muerte_ca) {
        auto screen_mca = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_mca = { "Salir" };
        int seleccion_mca = 0;

        screen_mca.Loop(crear_dialogo(opcines_mca, seleccion_mca, {
            paragraph("despues de seguir caminando un rato mas resulta que pisas una trampa que dispara un dardo venenoso y te impacta en el pecho mueriendo."),
        }, [&] {
            if (seleccion_mca == 0) {
                estado_actual2 = estadosit1_2::salir;
            }
            screen_mca.ExitLoopClosure()();
        }));
        if (estado_actual2 == estadosit1_2::salir) return false;
    }

    /*********************************************************************************************************** */
    /*ramificacion en caso de caminar observando bien*******************************************************************************************************************/
    if (estado_actual2 == estadosit1_2::observar_bien) {
        auto screen_ob = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_ob = {
            "Caminar relajado",
            "seguir caminando con cautela",
        };
        int seleccion_ob = 0;

        screen_ob.Loop(crear_dialogo(opcines_ob, seleccion_ob, {
            paragraph("Caminas viendo al piso de forma detallada en busca de trampas para evitarlas, que vas a hacer?")
        }, [&] {
            if (seleccion_ob == 0 || seleccion_ob == 1) {
                estado_actual2 = estadosit1_2::muerte_ob;
            }
            screen_ob.ExitLoopClosure()();
        }));
    }

    /* ****************************************************************************************************************************************************** 
    muerte al observar con cautela o con relajo*********************************************************************************************************** */
    if (estado_actual2 == estadosit1_2::muerte_ob) {
        auto screen_mob = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_mob = { "salir" };
        int seleccion_mob = 0;

        screen_mob.Loop(crear_dialogo(opcines_mob, seleccion_mob, {
            paragraph("Caminas un rato mas, a pesar de observar bien el piso pisas una placa de precion que dispara un dardo venenoso y mueres"),
        }, [&] {
            if (seleccion_mob == 0) {
                estado_actual2 = estadosit1_2::salir;
            }
            screen_mob.ExitLoopClosure()();
        }));
        if (estado_actual2 == estadosit1_2::salir) return false;
    }

    /* ***************************************************************************************************************************************** 
    la ultima ramificacion de pasillo seguro devolverte ****************************************************************************************** */
    if (estado_actual2 == estadosit1_2::devolver) {
        auto screen_de = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_de = {
            "atacarlo de frente",
            "Huir de el",
            "defenderte y contraatacar",
        };
        int seleccion_de = 0;

        screen_de.Loop(crear_dialogo(opcines_de, seleccion_de, {
            paragraph("Desides devolverte por el mismo pasillo, derrepente te encuentras con el mismi guardia de hace rato y esta en posicion de ataque, que vas ha hacer?"),
        }, [&] {
            if (seleccion_de == 0 || seleccion_de == 1 || seleccion_de == 2) {
                estado_actual2 = estadosit1_2::muerte_de;
            }
            screen_de.ExitLoopClosure()();
        }));
    }

    /* **************************************************************************************************************** 
    muerte de la ramificacion de devolver ***************************************************************************** */
    if (estado_actual2 == estadosit1_2::muerte_de) {
        auto screen_mde = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_mde = { "Salir" };
        int seleccion_mde = 0;

        screen_mde.Loop(crear_dialogo(opcines_mde, seleccion_mde, {
            paragraph("El guardia recciona demacido rapido antes de que puedas hacer algo por salvarte y mueres"),
        }, [&] {
            if (seleccion_mde == 0) {
                estado_actual2 = estadosit1_2::salir;
            }
            screen_mde.ExitLoopClosure()();
        }));
        if (estado_actual2 == estadosit1_2::salir) return false;
    }

    /* ******************************************************************************************************************************************** 
     comiensa la ultima ramificacion la de saludar al guardia ********************************************************************************** 
     ********************************************************************************************************************************************* */
    if (estado_actual2 == estadosit1_2::saludo) {
        auto screen_s = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_s = {
            "defenderte con tu escudo",
            "atacar cuando este lo suficientemente cerca"
        };
        int seleccion_s = 0;

        screen_s.Loop(crear_dialogo(opcines_s, seleccion_s, {
            paragraph("Saludas al guardia, el mismo entra en alerta y corre con su alabarda apuntandote hacia tu pocion, que vas a hacer?"),
        }, [&] {
            if (seleccion_s == 0 || seleccion_s == 1) {
                estado_actual2 = estadosit1_2::muerte_s;
            }
            screen_s.ExitLoopClosure()();
        }));
    }

    /* ******************************************************************************************************************************************************************** 
    muerte de ramificacion de saludar ********************************************************************************************************************************** */
    if (estado_actual2 == estadosit1_2::muerte_s) {
        auto screen_ms = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_ms = { "salir" };
        int seleccion_ms = 0;

        screen_ms.Loop(crear_dialogo(opcines_ms, seleccion_ms, {
            paragraph("El guardia reacciona mas rapido antes de que hagas algo y te clava su alabarda en tu pecho y mueres (de verdad hay que ser muy pendejo para saludar a un tipo peligroso en un sitio peligroso)"),
        }, [&] {
            if (seleccion_ms == 0) {
                estado_actual2 = estadosit1_2::salir;
            }
            screen_ms.ExitLoopClosure()();
        }));
        if (estado_actual2 == estadosit1_2::salir) return false;
    }

    return true;
}
