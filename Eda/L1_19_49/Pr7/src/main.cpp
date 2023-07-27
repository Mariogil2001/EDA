/**
 * @file main.cpp
 * @author Agustin Soares y Mario Gil
 * @brief Practica 6 EDA-GIM: Programa principal
 * @version 1.0
 * @date 2022-12-06
 *
 */

#include "NPC.h"
#include "personaje.h"
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    int ciclo = -1;
    /* Debe crear un personaje NPC cuyo nombre sea “Dragon de fuego” y que tenga un nivel de
    vida inicial igual a 1000.0*/
    NPC drac;
    drac.SetNombre("Dragon de fuego");
    drac.SetVida(1000.0);
    /* Se deben cargar como personajes “atacantes” de este NPC los incluidos en el archivo
    “datos.csv”.*/
    drac.CargarAtacantes();

    ///< Cabecera de la salida por pantalla
    cout << drac.GetNombre() << endl;
    cout << "vida = " << drac.GetVida() << endl;
   
   while (ciclo <= 20 && drac.GetVida() > 1)
   {
        cout << "------------------" << endl;
        ///< Mostrar el numero de ciclo en el que se encuentra la simulacion.
        cout << "Ciclo = " << ciclo << endl;
        ///< Atacar al personaje de mayor aggro y mostrar su nombre en pantalla.
        drac.Atacar();
        ///< Mostrar el nivel de vida del NPC tras el ataque.
        cout << "Vida NPC = " << drac.GetVida() << endl;
        /* Si el nivel de vida resulta inferior a 1 se debe mostrar un mensaje que indique el NPC
        se ha quedado “Sin vida” y la simulación debe finalizar sin concluir todos los ciclos
        previstos.*/
        if (drac.GetVida() < 1)
            cout << drac.GetNombre() << " Sin Vida " << endl;
        drac.ActualizarCiclo();   
        ciclo++;
        ///< Hacemos un while porque si muere el NPC podemos salir de ahi
        cout << "------------------" << endl;        
   }


}