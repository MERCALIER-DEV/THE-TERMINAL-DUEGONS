#include "niveles/Entrada_a_la_mazmorra/entrada_a_la_mazmorra.h"
#include "niveles/Pisos inferiore/Pisos_inferiores.h"
#include "niveles/Sala de jefe de la mazmorra/Sala_de_jefe_de_la_mazmorra.h"
#include "niveles/Sala del tesoro/Sala_del_tesoro.h"
#include "niveles/Zona de pasillos/Zona_de_pasillos.h"
#include<iostream>

int main(){

    bool juego_activo = true;

    while (juego_activo)
    {
        if(entrada_a_la_mazmorra())
        {

        }else
        {
            return 0;
        }

        if(Zona_de_pasillos())
        {

        }else
        {
            return 0;
        }

        if(Pisos_inferiore())
        {

        }else
        {
            return 0;
        }

        if(Sala_del_tesoro())
        {

        }else
        {
            return 0;
        }

        if(Sala_de_jefe_de_la_mazmorra())
        {

        }else
        {
            return 0;
        }
        

    return 0;
    }
}