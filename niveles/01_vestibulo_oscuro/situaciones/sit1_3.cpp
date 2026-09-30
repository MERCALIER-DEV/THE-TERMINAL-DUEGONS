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
#include "sit1_3.h"
#include "cabesera.h"
#include "cajas_dialogo.h"

using namespace ftxui;

enum class estadosit1_3{
    // estados normales o primarios (son las estdos que por si solos no definen el final del jigador y solo uno de ellos es el corrrecto al aplicar el estado vivo)
    vivo,
    exploro,
    puerta_hierro,
    pasillo_der,
    pasillo_izq,
    puerta_der,

    // ramificaciones de puerta de hierro
    pelear_d,
    pelear_b,
    pelear_a,

    // ramificaines de muerte de puerta de hierro
    muerte_pd,
    muerte_pb,
    muerte_pa,

    //ramificaciones de pasillo_der
    devolverse,
    seguir,

    // ramificasiones de muerte de pasillo_der
    huir,
    atk_duende,

    //ramificaciones de pasillo_izq

    seguir_izq,
    devolverse_izq,

    // ramifiaciones de muerte de pasillo izquierdo

    muerte_puerta_h_simple,
    muerte_puerta_hueca,
    muerte_puerta_cercana,
    muerte_seguir,

    // ramificaciones de puerta derecha

    revisar_armeria,
    devolter_armeria,
    puerta_armeria,
    pasillo_armeria,

    salir,
};

bool sit1_3(){
    /* ***********************************************************************************************************************************************************
    empiesa la sit1_3 ********************************************************************************************************************************************
    ************************************************************************************************************************************************************** */
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

    auto screen3 = ScreenInteractive::Fullscreen();
    estadosit1_3 estado_actual3 = estadosit1_3::vivo;

    std::vector<std::string> opcines3 = { "Explorar la sala" };
    int seleccion3 = 0;

    screen3.Loop(crear_dialogo(opcines3, seleccion3, {
        paragraph("Pasaste por el pasillo con trampas, extrañamente se sentia seguro de atravesar, te encuentras en un sala amplia de ladrillos viejos y rotos parece una  zona segura de momento, que vas a hacer?"),
    }, [&] {
        if (seleccion3 == 0) {
            estado_actual3 = estadosit1_3::exploro;
        }
        screen3.ExitLoopClosure()();
    }));

    /* *******************************************************************************************************************************************
    ***********************************************************************************************************************************************
     deciones principales ************************************************************************************************************************ */
    if (estado_actual3 == estadosit1_3::exploro) {
        auto screen_e = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_e = {
            "Ir por la puerta grande de hierro",
            "ir por el pasillo que esta a tu izquierda",
            "ir por el pasillo que esta a la derecha",
            "ir por la puerta comun de madera de la derecha",
            "ir por la puerta comun de madera de la izquierda",
        };
        int seleccion_e = 0;

        screen_e.Loop(crear_dialogo(opcines_e, seleccion_e, {
            paragraph("exploras la sala, es bastante grande se ven muchas estatuas antiguas y de dioses, parece que esto no siempre fue una mazmorra, puede que haya sido un templo o castillo para algo grande, pero hay que tomar algun camino para seguir avansando por la mazmorra, encuentras varios caminos, cual recorres"),
        }, [&] {
            if (seleccion_e == 0) {
                estado_actual3 = estadosit1_3::puerta_hierro;
            } else if (seleccion_e == 1) {
                estado_actual3 = estadosit1_3::pasillo_izq;
            } else if (seleccion_e == 2) {
                estado_actual3 = estadosit1_3::pasillo_der;
            } else if (seleccion_e == 3) {
                estado_actual3 = estadosit1_3::puerta_der;
            } else if (seleccion_e == 4) {
                estado_actual3 = estadosit1_3::vivo;
            }
            screen_e.ExitLoopClosure()();
        }));
    }

    if (estado_actual3 == estadosit1_3::vivo) return true;

    /*****************************************************************************************************************************************************************
    *****************************************************************************************************************************************************************
    ramificaciones al pasar por la puerta de hierro ****************************************************************************************************************** */
    if (estado_actual3 == estadosit1_3::puerta_hierro) {
        auto screen_ph = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_ph = {
            "Pelear con el duende",
            "Pelear con la bruja",
            "Pelear con la araña",
        };
        int seleccion_ph = 0;

        screen_ph.Loop(crear_dialogo(opcines_ph, seleccion_ph, {
            paragraph("pasas por la puerta de hierro es bastante grande y hay un pasillo y lo recorres sientes peligro cerca poco despues aparecen monstruos de mazmorra hay un duende una bruja y una araña discutiemdo quien te va a maatar ya que los 3 te consideran muy debil incluso 1vs1, que vas a hacer?"),
        }, [&] {
            if (seleccion_ph == 0) {
                estado_actual3 = estadosit1_3::pelear_d;
            } else if (seleccion_ph == 1) {
                estado_actual3 = estadosit1_3::pelear_b;
            } else if (seleccion_ph == 2) {
                estado_actual3 = estadosit1_3::pelear_a;
            }
            screen_ph.ExitLoopClosure()();
        }));
    }

    /* ******************************************************************************************************************************************************************* 
    ramicacion en caso de pelear con el duende ****************************************************************************************************************************************************** */
    if (estado_actual3 == estadosit1_3::pelear_d) {
        auto screen_pd = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_pd = {
            "permancer con tu espada y escudo al frente",
            "solo atacar al duende",
            "defenderte hasta un contraataque o desgaste ",
        };
        int seleccion_pd = 0;

        screen_pd.Loop(crear_dialogo(opcines_pd, seleccion_pd, {
            paragraph("dices con voz alta voy a pelear con el duende se siente imponencia en la atmosfera, el duende da un paso adelante saca su daga y sonrie de forma espantosa, los demas monstruos se van a otra parte, que vas hacer"),
        }, [&] {
            if (seleccion_pd == 0 || seleccion_pd == 1 || seleccion_pd == 2) {
                estado_actual3 = estadosit1_3::muerte_pd;
            }
            screen_pd.ExitLoopClosure()();
        }));
    }

    /* ****************************************************************************************************************************************************************************** 
    ramificacion de muerte al pelear con el duende*********************************************************************************************************************************** */
    if (estado_actual3 == estadosit1_3::muerte_pd) {
        auto screen_mpd = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_mpd = { "Salir" };
        int seleccion_mpd = 0;

        screen_mpd.Loop(crear_dialogo(opcines_mpd, seleccion_mpd, {
            paragraph("inicia la pelea el duende es rapido con su daga lo buen es que haces buen parry a sus ataques pero derrepente el duende cansado retrosede y saca otra daga y te ataca mas rapido que antes haste que en una de esas te acierta su daga en tu pecho y aunque inteste quitartela el dolor te entumese y te clava su otra daga en tu clavicula y mueres"),
        }, [&] {
            if (seleccion_mpd == 0) {
                estado_actual3 = estadosit1_3::salir;
            }
            screen_mpd.ExitLoopClosure()();
        }));
        if (estado_actual3 == estadosit1_3::salir) return 0;
    }

    /* ********************************************************************************************************************************************
    Ramificaion al pelear con la bruja******************************************************************************************************************************** */
    if (estado_actual3 == estadosit1_3::pelear_b) {
        auto screen_pb = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_pb = {
            "permancer con tu espada y escudo al frente",
            "solo atacar a la bruja",
            "defenderte hasta poder realizar un contraataque ",
        };
        int seleccion_pb = 0;

        screen_pb.Loop(crear_dialogo(opcines_pb, seleccion_pb, {
            paragraph("dices con voz alta voy a pelear con la bruja se siente imponencia en la atmosfera, la bruja da un paso adelante saca una pocima extraña, los demas monstruos se van a otra parte, que vas hacer"),
        }, [&] {
            if (seleccion_pb == 0 || seleccion_pb == 1 || seleccion_pb == 2) {
                estado_actual3 = estadosit1_3::muerte_pb;
            }
            screen_pb.ExitLoopClosure()();
        }));
    }

    /* ***************************************************************************************************************************************************************
    ramificacion muerte al pelear con bruja ************************************************************************************************************************** */
    if (estado_actual3 == estadosit1_3::muerte_pb) {
        auto screen_mpb = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_mpb = { "Salir" };
        int seleccion_mpb = 0;

        screen_mpb.Loop(crear_dialogo(opcines_mpb, seleccion_mpb, {
            paragraph("inicia la pelea, la bruja te lanza pociones sin parar algunas de acido otras de daño, logras evadir muchas, pero la bruja toma mucha distancia repentinamente y lanza un frasco distinto, es un gas lacrimojeno te deja muy segado y no ves nada en eso, siente que algo que te impacta en la cabesa y se rompe es acido cayecdo sobre ti y mueres."),
        }, [&] {
            if (seleccion_mpb == 0) {
                estado_actual3 = estadosit1_3::salir;
            }
            screen_mpb.ExitLoopClosure()();
        }));
        if (estado_actual3 == estadosit1_3::salir) return 0;
    }

    /* **************************************************************************************************************************************************************** 
    ramificacion de pelea con araña************************************************************************************************************************************ */
    if (estado_actual3 == estadosit1_3::pelear_a) {
        auto screen_pa = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_pa = {
            "permancer con tu espada y escudo al frente",
            "solo atacar a la araña",
            "defenderte hasta poder realizar un contraataque ",
        };
        int seleccion_pa = 0;

        screen_pa.Loop(crear_dialogo(opcines_pa, seleccion_pa, {
            paragraph("dices con voz alta voy a pelear con la araña se siente imponencia en la atmosfera, la araña da un paso adelante ase un sonido intimidante, los demas monstruos se van a otra parte, que vas hacer"),
        }, [&] {
            if (seleccion_pa == 0 || seleccion_pa == 1 || seleccion_pa == 2) {
                estado_actual3 = estadosit1_3::muerte_pa;
            }
            screen_pa.ExitLoopClosure()();
        }));
    }

    /* ************************************************************************************************************************************************************** 
    ramificacion muerte al pelear con araña ************************************************************************************************************************* */
    if (estado_actual3 == estadosit1_3::muerte_pa) {
        auto screen_mpa = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_mpa = { "Salir" };
        int seleccion_mpa = 0;

        screen_mpa.Loop(crear_dialogo(opcines_mpa, seleccion_mpa, {
            paragraph("inicia la pelea, la araña enviste de frente, usas tu escudo y la hases retroceder te ruge de forma intimidadte y vuelve a embestir con mas fuerza que la anterior despues la araña sube por las paredes hasta el techo te enviste fuertemente y aunque logras poner tu escudo se rompe y la araña te tiene en el piso hasta que te muerde la cara y mueres."),
        }, [&] {
            if (seleccion_mpa == 0) {
                estado_actual3 = estadosit1_3::salir;
            }
            screen_mpa.ExitLoopClosure()();
        }));
        if (estado_actual3 == estadosit1_3::salir) return false;
    }

    /* ****************************************************************************************************************************************************************************** 
    *********************************************************************************************************************************************************************************
    empiensa las ramificaciones de pasillo der ************************************************************************************************************************************** */
    if (estado_actual3 == estadosit1_3::pasillo_der) {
        auto screen_p_der = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_p_der = {
            "Devolverte por el pasillo",
            "Seguir por el mismo",
        };
        int seleccion_p_der = 0;

        screen_p_der.Loop(crear_dialogo(opcines_p_der, seleccion_p_der, {
            paragraph("Recorres el pasillo derecho, es amplio y largo, encuentras otra sala amplia, que vas a hacer? "),
        }, [&] {
            if (seleccion_p_der == 0) {
                estado_actual3 = estadosit1_3::devolverse;
            } else if (seleccion_p_der == 1) {
                estado_actual3 = estadosit1_3::seguir;
            }
            screen_p_der.ExitLoopClosure()();
        }));
    }

    /* ****************************************************************************************************************************************** 
    ramificacion de pasillo derecho devolverse ************************************************************************************************** */
    if (estado_actual3 == estadosit1_3::devolverse) {
        auto screen_devo = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_devo = {
            "huir",
            "atacarlo",
        };
        int seleccion_devo = 0;

        screen_devo.Loop(crear_dialogo(opcines_devo, seleccion_devo, {
            paragraph("decides de volverte, te encuentras con un duende que quiere matarte que vas a hacer? "),
        }, [&] {
            if (seleccion_devo == 0) {
                estado_actual3 = estadosit1_3::huir;
            } else if (seleccion_devo == 1) {
                estado_actual3 = estadosit1_3::atk_duende;
            }
            screen_devo.ExitLoopClosure()();
        }));
    }

    /* ******************************************************************************************************************************
    ramificacion muerte pasillo derecho al huir ************************************************************************************* */
    if (estado_actual3 == estadosit1_3::huir) {
        auto screen_h = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_h = { "Salir" };
        int seleccion_h = 0;

        screen_h.Loop(crear_dialogo(opcines_h, seleccion_h, {
            paragraph("decides huir, el duende te persigue pero al entrar en la sala amplia pisas una trampa de avalancha y mueres (y el duede se rie de ti)"),
        }, [&] {
            if (seleccion_h == 0) {
                estado_actual3 = estadosit1_3::salir;
            }
            screen_h.ExitLoopClosure()();
        }));
        if (estado_actual3 == estadosit1_3::salir) return false;
    }

    /* *************************************************************************************************************************************
    ramificacion muerte en caso de atacar al duende **************************************************************************************** */
    if (estado_actual3 == estadosit1_3::atk_duende) {
        auto screen_atk_duende = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_atk_duende = { "Salir" };
        int seleccion_atk_duende = 0;

        screen_atk_duende.Loop(crear_dialogo(opcines_atk_duende, seleccion_atk_duende, {
            paragraph("decides atacar al duende, pero resulto ser que el duende es mas agil que tu y pesar de que bloqueas varios de sus ataques encuentra un punto debil y te clava su daga ahi y mueres. (y el duede se rie de ti)"),
        }, [&] {
            if (seleccion_atk_duende == 0) {
                estado_actual3 = estadosit1_3::salir;
            }
            screen_atk_duende.ExitLoopClosure()();
        }));
        if (estado_actual3 == estadosit1_3::salir) return false;
    }

    /* *********************************************************************************************************************************** 
    ramificacion muerte de pasillo derecho en caso de seguir ***************************************************************************** */
    if (estado_actual3 == estadosit1_3::seguir) {
        auto screen_p_der = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_p_der = { "Salir" };
        int seleccion_p_der = 0;

        screen_p_der.Loop(crear_dialogo(opcines_p_der, seleccion_p_der, {
            paragraph("decides seguir por esa sala, pero al entrar en la sala amplia pisas una trampa de avalancha y mueres. "),
        }, [&] {
            if (seleccion_p_der == 0) {
                estado_actual3 = estadosit1_3::salir;
            }
            screen_p_der.ExitLoopClosure()();
        }));
        if (estado_actual3 == estadosit1_3::salir) return false;
    }

    /* ********************************************************************************************************************************************
    ***********************************************************************************************************************************************
    ramificaciones de pasillo izquierdo *********************************************************************************************************** */
    
    if (estado_actual3 == estadosit1_3::pasillo_izq) {
        auto screen_p_izq = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_p_izq = {
            "seguir por el pasillo",
            "devolverte",
        };
        int seleccion_p_izq = 0;

        screen_p_izq.Loop(crear_dialogo(opcines_p_izq, seleccion_p_izq, {
            paragraph("Recorres el pasillo izquierdo, no hay mucho que ver solo otro pasillo aun que este es particularmente largo. que vas a hacer?"),
        }, [&] {
            if (seleccion_p_izq == 0) {
                estado_actual3 = estadosit1_3::seguir_izq;
            } else if (seleccion_p_izq == 1) {
                estado_actual3 = estadosit1_3::devolverse_izq;
            }
            screen_p_izq.ExitLoopClosure()();
        }));
    }

    /* ***************************************************************************************************************************************
    ramificaciones al seguir por pasillo_izq ************************************************************************************************* */

    if (estado_actual3 == estadosit1_3::seguir_izq) {
        auto screen_seg_izq = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_seg_izq = {
            "Ir por la puerta de hierro simple",
            "Ir por el hueco donde se ve el marco de una puerta",
            "Ir por la puerta mas cercana a ti",
            "seguir por mas por le pasillo"
        };
        int seleccion_seg_izq = 0;

        screen_seg_izq.Loop(crear_dialogo(opcines_seg_izq, seleccion_seg_izq, {
            paragraph("Recorres el pasillo izquierdo aun mas, encuentras varia puertas viejas y el pasillo todavia se extiende mas. que vas hacer?"),
        }, [&] {
            if (seleccion_seg_izq == 0) {
                estado_actual3 = estadosit1_3::muerte_puerta_h_simple;
            } else if (seleccion_seg_izq == 1) {
                estado_actual3 = estadosit1_3::muerte_puerta_hueca;
            }else if (seleccion_seg_izq == 2) {
                estado_actual3 = estadosit1_3::muerte_puerta_cercana;
            }else if (seleccion_seg_izq == 3) {
                estado_actual3 = estadosit1_3::muerte_seguir;
            }
            screen_seg_izq.ExitLoopClosure()();
        }));
    }
    
    /* *************************************************************************************************************************************************
    ramificaciones muerte de pasillo izquierdo ************************************************************************************** */

    /* ***********************************************************************************************************************************************************
    ramificacion en caso de puerta_h_simple ********************************************************************************************************************** */

    if (estado_actual3 == estadosit1_3::muerte_puerta_h_simple) {
        auto screenm_m_p_h_s = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcinesm_m_p_h_s = {"Salir",};
        int seleccionm_m_p_h_s = 0;

        screenm_m_p_h_s.Loop(crear_dialogo(opcinesm_m_p_h_s, seleccionm_m_p_h_s, {
            paragraph("resulta que por esa puerta de hierro habia un mago de fuego que te lanzo una bola de fuego antes de que pudieras defenderte y mueres."),
        }, [&] {
            if (seleccionm_m_p_h_s == 0) {
                estado_actual3 = estadosit1_3::salir;
            } 
            screenm_m_p_h_s.ExitLoopClosure()();
        }));
    }

    /* **************************************************************************************************************************************************************
    ramificacion muerte en caso de puerta_hueca***************************************************************************************************************************************************************** */

    if (estado_actual3 == estadosit1_3::muerte_puerta_hueca) {
        auto screen_m_p_hu = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_m_p_hu = {"Salir",};
        int seleccion_m_p_hu = 0;

        screen_m_p_hu.Loop(crear_dialogo(opcines_m_p_hu, seleccion_m_p_hu, {
            paragraph("resulta que por esa puerta hueca la puerta no era lo unico hueco sino tambien el piso caes por el mismo y mueres."),
        }, [&] {
            if (seleccion_m_p_hu == 0) {
                estado_actual3 = estadosit1_3::salir;
            } 
            screen_m_p_hu.ExitLoopClosure()();
        }));
    }

    /* *********************************************************************************************************************************************
    ramificacion muerte puerta cercana ************************************************************************************************************* */

    if (estado_actual3 == estadosit1_3::muerte_puerta_cercana) {
        auto screen_m_p_cer = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_m_p_cer = {"Salir",};
        int seleccion_m_p_cer = 0;

        screen_m_p_cer.Loop(crear_dialogo(opcines_m_p_cer, seleccion_m_p_cer, {
            paragraph("resulta que por esa puerta cercana en realidad era un trampa conectada a un mecanismo de fuego que disparaba un rayo incinerador justo a tu espalda y mueres"),
        }, [&] {
            if (seleccion_m_p_cer == 0) {
                estado_actual3 = estadosit1_3::salir;
            } 
            screen_m_p_cer.ExitLoopClosure()();
        }));
    }

    /* ******************************************************************************************************************************************************************************************
    Muerte al seguir por el pasillo****************************************************************************************************************************************************************** */

    if (estado_actual3 == estadosit1_3::muerte_seguir) {
        auto screen_m_seg = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_m_seg = {"Salir",};
        int seleccion_m_seg = 0;

        screen_m_seg.Loop(crear_dialogo(opcines_m_seg, seleccion_m_seg, {
            paragraph("Sigues mas adelante por ese pasillo ignorando las demas puertas, escuchas ruidos en el techo pero antes de poder hacer algo resulta que una araña te ataca por sopresa desde el techo y mueres"),
        }, [&] {
            if (seleccion_m_seg == 0) {
                estado_actual3 = estadosit1_3::salir;
            } 
            screen_m_seg.ExitLoopClosure()();
        }));
    }
    /* ***************************************************************************************************************************************************************
    muerte al devolter por el pasillo ******************************************************************************************************************************** */

    if (estado_actual3 == estadosit1_3::devolverse_izq) {
        auto screen_m_devo = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_m_devo = {"Salir",};
        int seleccion_m_devo = 0;

        screen_m_devo.Loop(crear_dialogo(opcines_m_devo, seleccion_m_devo, {
            paragraph("desides devolverte del pasillo, escuchas ruidos en el techo pero antes de poder hacer algo resulta que una araña te ataca por sopresa desde el techo y mueres"),
        }, [&] {
            if (seleccion_m_devo == 0) {
                estado_actual3 = estadosit1_3::salir;
            } 
            screen_m_devo.ExitLoopClosure()();
        }));
    }

    /* ***********************************************************************************************************************************************************
    **************************************************************************************************************************************************************
    ramificaciones de puerta comun de madera derecha************************************************************************************************************** */

    if (estado_actual3 == estadosit1_3::puerta_der) {
        auto screen_pu_der = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_pu_der = {
            "revisar armeria",
            "devolterte en busca de otro camino",
            "ir por la puerta de la armeria",
            "ir por el pasillo de la armeria",
        };
        int seleccion_pu_der = 0;

        screen_pu_der.Loop(crear_dialogo(opcines_pu_der, seleccion_pu_der, {
            paragraph("atraviesas esa puerta entras en algun tipo de armeria extraña, aun que todas esas armas estan demaciado viejas como para usarse, tambien hay varias puertas y pasillos que vas a hacer  que vas hacer?"),
        }, [&] {
            if (seleccion_pu_der == 0) {
                estado_actual3 = estadosit1_3::revisar_armeria;
            } else if (seleccion_pu_der == 1) {
                estado_actual3 = estadosit1_3::devolter_armeria;
            }else if (seleccion_pu_der == 2) {
                estado_actual3 = estadosit1_3::puerta_armeria;
            }else if (seleccion_pu_der == 3) {
                estado_actual3 = estadosit1_3::pasillo_armeria;
            }
            screen_pu_der.ExitLoopClosure()();

        }));
    }
    /* ************************************************************************************************************************************************************************************************ 
    ramificacion al revisar armeria ******************************************************************************************************************************************************************* */

    if (estado_actual3 == estadosit1_3::revisar_armeria) {
        auto screen_pu_der = ScreenInteractive::Fullscreen();
        std::vector<std::string> opcines_pu_der = {
            "revisar armeria",
            "devolterte en busca de otro camino", //acomodar
            "ir por la puerta de la armeria",
            "ir por el pasillo de la armeria",
        };
        int seleccion_pu_der = 0;

        screen_pu_der.Loop(crear_dialogo(opcines_pu_der, seleccion_pu_der, {
            paragraph("atraviesas esa puerta entras en algun tipo de armeria extraña, aun que todas esas armas estan demaciado viejas como para usarse, tambien hay varias puertas y pasillos que vas a hacer  que vas hacer?"),
        }, [&] {
            if (seleccion_pu_der == 0) {
                estado_actual3 = estadosit1_3::revisar_armeria;
            } else if (seleccion_pu_der == 1) {
                estado_actual3 = estadosit1_3::devolter_armeria;
            }else if (seleccion_pu_der == 2) {
                estado_actual3 = estadosit1_3::puerta_armeria;
            }else if (seleccion_pu_der == 3) {
                estado_actual3 = estadosit1_3::pasillo_armeria;
            }
            screen_pu_der.ExitLoopClosure()();

        }));
    }
    return false;
}