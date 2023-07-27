/**
 * @file NPC.cpp
 * @author Mario Gil y Agustin Soares
 * @brief Practica 7 EDA-GIM: Implementacion de la clase NPC
 * @version 1.0
 * @date 2022-11-28
 *
 */

#include "NPC.h"

#include <vector>
#include <string>
#include <queue>

#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <sstream>
#include <iostream>

///< ctime y windows.h sirve para crear un numero aleatorio
#include <ctime>
#include <windows.h>

#include <utility>


using namespace std;

const string FICH_DATOS = "datos.csv";

/**
 * @brief Construir un nuevo NPC.
 */
NPC::NPC()
    : nombre("<Sin nombre>"), vida(0.0)
{
}

/**
 * @brief Construir un nuevo Personaje con valores del usuario.
 */
NPC::NPC(string nom, float vida)
    : nombre(nom), vida(vida)
{
}

/**
 * @brief Establecer el nombre del NPC
 *
 * @param n nuevo nombre
 */
void NPC::SetNombre(string n)
{
    this->nombre = n;
}

/**
 * @brief Establecer el nivel vida del NPC
 *
 * @param a nuevo vida
 */
void NPC::SetVida(float a)
{
    if (a < 0) // no hay aggro negativo
        this->vida = 0;
    else
        this->vida = a;
}

/**
 * @brief Consultar el nombre del NPC
 *
 * @return string
 */
string NPC::GetNombre()
{
    return this->nombre;
}

/**
 * @brief Consultar la vida del NPC
 *
 * @return float
 */
float NPC::GetVida()
{
    return this->vida;
}

/**
 * @brief Carga en la tabla memoria los datos contenidos en el archivo “memoria.csv”.
 * 
 * 
 */

void NPC::CargarMemoria()
{
    ifstream f_in;
    string cabecera, NPC, victorias, derrotas;
    Resultados resultado;
    f_in.open("data/memoria.csv");
        if (!f_in) cout << "Error al abrir el fichero." << endl;
        else
        {
            ///< Nos quitamos la cabecera del documento
            getline(f_in,cabecera);
            while(getline(f_in,NPC,';'))
            {
                getline(f_in,victorias,';');
                getline(f_in,derrotas);
                ///< La funcion stoi es string to int
                resultado.nvictorias = stoi(victorias);
                resultado.nderrotas = stoi(derrotas);

                memoria.insert(make_pair(NPC,resultado));                     
            }
        }  
}

/**
 * 
 * @brief La operación CargarAtacantes() debe rellenar el vector de personajes del NPC con los datos
 * incluidos en un archivo de entrada, con formato csv. En particular, del archivo “datos.csv”.
 * Se debe tener en cuenta que la primera línea es una cabecera y que cada una de las siguientes
 * líneas contiene la información de un personaje, que puede ser leída utilizando el operador de
 * entrada de la clase Personaje. Este proceso de carga debe rellenar el vector atacantes e
 * incorporar los datos de aggro y nombre a montículo para tener la información disponible para
 * empezar el juego.
 * 
 */
void NPC::CargarAtacantes()
{
    ifstream f_in;
    string cabecera;
    Personaje p;
    Resultados result;
    float priority;

    result.nvictorias = 0;
    result.nderrotas = 0;

    f_in.open("data/" + FICH_DATOS);
        if (!f_in) cout << "Error al abrir el fichero. " << endl;
        else
        {
            ///< Nos quitamos la cabecera del documento
            getline(f_in,cabecera);
            while(f_in >> p)
            {
                atacantes.insert(make_pair(p.GetNombre(),p));
                priority = Prioridad(p.GetAggro(),memoria[p.GetNombre()].nvictorias, memoria[p.GetNombre()].nderrotas) ;
                monticulo.push(ParDato(priority, p.GetNombre()));
 
                if(memoria.find(p.GetNombre()) == memoria.end())
                    memoria.insert(make_pair(p.GetNombre(),result));
            }   
        }
}

/**
 * @brief Actualizar la informacion de los personajes atacantes en un nuevo ciclo de juego
 */
void NPC::ActualizarCiclo()
{
    /* Debe AvanzarCiclo para todos los personajes del vector
    atacantes (esto actualizará el aggro de todos ellos) y también volver a generar montículo,
    que debe ser vaciado y vuelto a llenar con los datos actualizados*/
    unordered_map<string,Personaje>::iterator it;
    float priority;

    while (!monticulo.empty())
        monticulo.pop();
    for (it = atacantes.begin(); it != atacantes.end(); it ++)
    {
        it -> second.AvanzarCiclo();
        priority = Prioridad(it -> second.GetAggro(), memoria[it ->first].nvictorias,memoria[it ->first].nderrotas);
        monticulo.push(ParDato(priority, it -> second.GetNombre()));
    }


}

/**
 * @brief Actualizar la informacion de los personajes atacantes en un nuevo ciclo de juego
 * 
 * @return string del nombre del atacante
 */

string NPC::Atacar()
{
    int naleatorio, primero = 0;
    srand(time(NULL)); ///< Crea un numero aleatorio
    ///< variable = limite_inferior + rand() % (limite_superior + 1 - limite_inferior);
    naleatorio = 1 + rand() % 100; ///< Numero comprendido entre 1 y 100
    primero = monticulo.top().first;
    /* Las prioridades de los personajes podrían llegar a ser mayores que 100. En ese caso, antes 
    de determinar el resultado del combate, la prioridad se debe reducir al rango [1,100] */
    while(primero > 100)
        primero = primero / 10;
    /* Si el valor generado es menor o igual que la prioridad del 
      personaje en el montículo entonces el NPC habrá sido derrotado */
      cout << "Personaje atacado: " << monticulo.top().second;
      cout << " (" << primero << ")" << endl;
      cout << "aleat = " << naleatorio << endl;
    if(naleatorio <= primero)
    {
        ///< Se reducira la vida del NPC tanto como indique la prioridad del personaje
        NPC::SetVida(GetVida() - monticulo.top().first);
        ///< Actualizamos la memoria para registrar una derrota mas con este personaje
        memoria[monticulo.top().second].nderrotas++;
        cout << "Victoria :-)" << endl;
    }
    ///< Si no se cumple la condicion anterior, entonces el NPC habra ganado el combate
    else
    {
        ///< Incrementamos la vida del NPC tanto como indique la prioridad del personaje
        NPC::SetVida(GetVida() + monticulo.top().first);
        ///< Actualizamos la memoria para registrar una victoria mas con este personaje
        memoria[monticulo.top().second].nvictorias++;
        cout << "Derrota :-(" << endl;
    }
    ///< El top es el personaje con mas aggro y devuelve la segunda posicion que es su nombre 
    return monticulo.top().second;
}

/**
 * @brief Criterio para asignar prioridades en el monticulo para los personajes atacantes
 * 
 * @param aggro 
 * @param victorias 
 * @param derrotas 
 * @return float Prioridad del personaje
 */

float NPC::Prioridad (int aggro, int victorias, int derrotas)
{
    float prioridad;

    if (victorias == 0 && derrotas == 0)
        prioridad = aggro;
    else
        prioridad = aggro + victorias *(victorias - derrotas) / (victorias + derrotas);

    return prioridad;
}