#include "entrada_a_la_mazmorra.h"
#include <iostream>
#include <string>
#include <vector>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>

using namespace ftxui;


bool entrada_a_la_mazmorra()

{

auto pantalla = ScreenInteractive::TerminalOutput();

    std::vector<std::string> las_opciones = {
        "1. ver una carita feliz",
        "2. ver una carita triste",
        "3. ver una carita aburrida"
    };
    int seleccion = 0;

    auto menu = Menu(&las_opciones, &seleccion);

    // Conectamos el componente 'menu' al Renderer
    auto mi_pantalla = Renderer(menu, [&] {
        // 1. Evaluamos la selección actual para elegir la carita
        std::string carita = "";
        switch (seleccion) {
            case 0:  carita = "  :)"; break;
            case 1:  carita = "  :("; break;
            case 2:  carita = "  :|"; break;
            default: carita = "  ?";  break;
        }

        // 2. Dibujamos las opciones a la izquierda y la carita a la derecha
        return window(
            text(" INTERACTIVO ") | bold,
            hbox({
                vbox({
                    text("que quieres ver:"),
                    separator(),
                    menu->Render()
                }),
                separator(),
                // Renderizamos la carita dinámica
                vbox({
                    text("RESULTADO:") | dim,
                    text(carita) | color(Color::Yellow) | bold
                }) | center
            })
        ) | border;
    });

    pantalla.Loop(mi_pantalla);







    return true;
}