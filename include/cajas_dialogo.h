#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>
#include "cabesera.h"

using namespace ftxui;

class cajas_dialogo
{
public:

    Elements textos;
   
   auto texto_sit(){

    auto dialogo = hbox({ flexbox(textos)}) | flex | border;
    return dialogo;
   }
   

    Component menu_sit(const std::string& opc1, const std::string& opc2, int& seleccion, std::function<void()> al_enter){
        std::vector<std::string> opc = {opc1, opc2}

        MenuOption options;
        options.on_enter = al_enter
        
        options.entries_option.transform = [](EntryState state){
            if(state.focused){
                return text("> [" + state.label + " ]") | bold;
            } else {

             return text("   " + state.label ) ;

            }
       };

       return Menu(&opc, &seleccion, options);
    }
   
};

