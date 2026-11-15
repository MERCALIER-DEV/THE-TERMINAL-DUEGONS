#include <iostream>
#include <string>
#include <vector>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>
#include "sit1_4.h"
#include "cabesera.h"
#include "cajas_dialogo.h"

   enum class estadosit1_4{
      vivo,

      //estados base 

      no_tomar_anillo,


      salir,
   };

bool sit1_4(){

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

    auto screen = ScreenInteractive::Fullscreen();
    estadosit1_4 estado_actual = estadosit1_4::vivo;

    /* ************************************************************************************************************************************
    ******************************************************************************************************************************************
    inicio de la sit1_4 */
    if (estado_actual == estadosit1_4::vivo) {
        std::vector<std::string> opcines = {
            "tomar el anillo",
            "continuar sin el anillo",
        };
        int seleccion = 0;

        screen.Loop(crear_dialogo(opcines, seleccion, {
            paragraph("atraviesas la puerta izquierda, en ella hay un largo pasillo encuentras el cuerpo de otro aventurero esta tan viejo que solo quedan lo huesos el cadaver tiene un anillo no sabes para que pueda servir tal objeto, que vas hacer?"),
        }, [&] {
            if (seleccion == 0) {
                estado_actual = estadosit1_4::vivo;
            } else if (seleccion == 1) {
                estado_actual = estadosit1_4::no_tomar_anillo;
            }
            screen.ExitLoopClosure()();
        }));
    }


   return true; 
}