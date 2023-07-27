/**
 * @file NPC.cpp
 * @author Agustin Soares y Mario Gil
 * @brief Practica 6 EDA-GIM: Implementacion de la clase NPC
 * @version 1.0
 * @date 2022-11-28
 *
 */

#include "NPC.h"
#include "personaje.h"

#include <vector>
#include <string>
#include <queue>

#include <fstream>
#include <sstream>
#include <iostream>

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

    f_in.open("data/" + FICH_DATOS);
        if (!f_in) cout << "Error al abrir el fichero. " << endl;
        else
        {
            ///< Nos quitamos la cabecera del documento
            getline(f_in,cabecera);
            while(f_in >> p)
            {
                atacantes.push_back(p);
                monticulo.push(ParDato(p.GetAggro(),p.GetNombre()));
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
    while (!monticulo.empty())
        monticulo.pop();
    for(int i = 0; i < atacantes.size(); i ++)
    {
        atacantes[i].AvanzarCiclo();
        monticulo.push(ParDato(atacantes[i].GetAggro(),atacantes[i].GetNombre()));
    }

}

/**
 * @brief Actualizar la informacion de los personajes atacantes en un nuevo ciclo de juego
 */
string NPC::Atacar()
{
    /* Debe devolver el nombre del personaje al que se ataca en este ciclo
    del juego, que será el personaje con mayor aggro, seleccionado adecuadamente del montículo.
    Además, la vida del NPC se reducirá tanto como indique el aggro del personaje atacado*/

    ///< A la vida del NPC le ponemos la vida que tenia menos la que le quita el jugador con mas aggro
    NPC::SetVida(GetVida()-monticulo.top().first);

    ///< El top es el personaje con mas aggro y devuelve la segunda posicion que es su nombre :P 
    return monticulo.top().second;
}