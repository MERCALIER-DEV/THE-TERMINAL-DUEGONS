#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>
#include "sit1_1.h"
#include "cabesera.h"
#include "cajas_dialogo.h"

using namespace ftxui;

enum class estadosit1_1{
   vivo,
   escapo,
   muerto1,
   muerto2,
   salir,
};

bool sit1_1(){
   /* ***********************************************************************************************************************************************************
   empiesa la sit1_1 ********************************************************************************************************************************************
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
   estadosit1_1 estado_actual = estadosit1_1::vivo;

   std::vector<std::string> opcines = {
       "Entrar al vestibulo oscuro",
       "Irte de este lugar",
   };
   int seleccion = 0;

   screen.Loop(crear_dialogo(opcines, seleccion, {
       paragraph("Estas en el vestibulo oscuro despues de un largo viaje,pensando en si realemente tenias que ir en lugar tan peligroso, ahora debes tomar una decision si irte de este sitio o entrar."),
   }, [&] {
       if (seleccion == 0) {
           estado_actual = estadosit1_1::vivo;
       } else if (seleccion == 1) {
           estado_actual = estadosit1_1::escapo;
       }
       screen.ExitLoopClosure()();
   }));

   // lo primero a evaluar en caso de haya elegido la opcion correcta
   if (estado_actual == estadosit1_1::vivo) {
       return true;
   }

   // si eligio irse ********************************************************************************************************************************
   //************************************************************************************************************************************************ */
   if (estado_actual == estadosit1_1::escapo) {
       auto screen_esp = ScreenInteractive::Fullscreen();
       std::vector<std::string> opcines_esp = {
           "Enfrentar al troll con tu espada y tu escudo",
           "Evadir al troll y correr hacia la salida",
       };
       int seleccion_esp = 0;

       screen_esp.Loop(crear_dialogo(opcines_esp, seleccion_esp, {
           paragraph("Decidiste ir te de este lugar, pero en tu huida te encuentras con un troll que te quiere matar por tu cobardia, como respondes"),
       }, [&] {
           if (seleccion_esp == 0) {
               estado_actual = estadosit1_1::muerto1;
           } else if (seleccion_esp == 1) {
               estado_actual = estadosit1_1::muerto2;
           }
           screen_esp.ExitLoopClosure()();
       }));
   }

   // si eligio 0 se ejucuta esta rama
   if (estado_actual == estadosit1_1::muerto1) {
       auto screen0 = ScreenInteractive::Fullscreen();
       std::vector<std::string> opcines0 = { "Salir" };
       int seleccion0 = 0;

       screen0.Loop(crear_dialogo(opcines0, seleccion0, {
           paragraph("Decidiste enfrentar al troll con tu espada y tu escudo, pero el troll era demasiado fuerte y te mato, ahora estas muerto."),
       }, [&] {
           if (seleccion0 == 0) {
               estado_actual = estadosit1_1::salir;
           }
           screen0.ExitLoopClosure()();
       }));

       if (estado_actual == estadosit1_1::salir)
           return false;
   // si eligio 1 se ejecuta esta rama
   } else if (estado_actual == estadosit1_1::muerto2) {
       auto screen1 = ScreenInteractive::Fullscreen();
       std::vector<std::string> opcines1 = { "Salir" };
       int seleccion1 = 0;

       screen1.Loop(crear_dialogo(opcines1, seleccion1, {
           paragraph("Decidiste evadir al troll y correr hacia la salida, pero el troll te alcanzo y te mato, ahora estas muerto."),
       }, [&] {
           if (seleccion1 == 0) {
               estado_actual = estadosit1_1::salir;
           }
           screen1.ExitLoopClosure()();
       }));

       if (estado_actual == estadosit1_1::salir)
           return false;
   }

   return false;
}