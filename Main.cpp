#include "nivel1.h"
#include "nivel2.h"
#include "nivel3.h"
#include "nivel4.h"
#include "nivel5.h"
#include <iostream>
#include <string>
#include <vector>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/component/component.hpp>

int main(){

    
    
          
    bool juego_activo = true;

    while (juego_activo)
    {
        if(jugar_nivel1())
        {

        }else
        {
            return 0;
        }
    }
/*
        if(jugar_nivel2())
        {

        }else
        {
            return 0;
        }

        if(jugar_nivel3())
        {

        }else
        {
            return 0;
        }

        if(jugar_nivel4())
        {

        }else
        {
            return 0;
        }

        if(jugar_nivel5())
        {

        }else
        {
            return 0;
        }

    */
    
return 0;
}