/**
 * @file personaje.cpp
 * @author Jesus Albert
 * @brief Practica 6 EDA-GIM: Implementacion de la clase Personaje
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "personaje.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

/**
 * @brief Construir un nuevo Personaje: aggro = 0, ciclo = -1 (antes de empezar)
 * 
 */
Personaje::Personaje()
:nombre("<Sin nombre>"), aggro(0), ciclo(-1)
{}

/**
 * @brief Establecer el nombre del Personaje
 * 
 * @param n nuevo nombre
 */
void Personaje::SetNombre(string n)
{
    this->nombre = n;
}

/**
 * @brief Establecer el nivel aggro del Personaje
 * 
 * @param a nuevo aggro
 */
void Personaje::SetAggro(int a)
{
    if ( a < 0 ) //no hay aggro negativo
        this->aggro = 0;
    else
        this->aggro = a;
}

/**
 * @brief Consultar el nombre del Personaje
 * 
 * @return string 
 */
string Personaje::GetNombre()
{
    return this->nombre;
}

/**
 * @brief Consultar el aggro del Personaje
 * 
 * @return int 
 */
int Personaje::GetAggro()
{
    return this->aggro;
}

/**
 * @brief Evolucionar al siguiente ciclo del juego. 
 * Se modifica el aggro de acuerdo con los incrementos establecidos para cada ciclo.
 * 
 */
void Personaje::AvanzarCiclo()
{
    this->ciclo++;
    //el numero de ciclo no puede superar el numero de incrementos registrados
    if ( this->ciclo < (int) this->varaggro.size() )
        this->aggro += this->varaggro[this->ciclo];
}

/**
 * @brief Operador de entrada para leer los datos del Personaje desde un flujo de entrada
 * 
 * @param f_in Flujo de entrada
 * @param p Personaje cuyos datos se leen (modificado)
 * @return ifstream& 
 */
ifstream& operator>> (ifstream& f_in, Personaje& p)
{
    vector<int> v;

    if ( f_in )
    {
        string linea;
        string x; //elemento extraido de linea

        if ( getline(f_in,linea) )
        {
            stringstream aux(linea); //stream en memoria para leer como un archivo con getline
            
            getline(aux, p.nombre, ';');
            getline(aux, x, ';');
            p.aggro = stoi(x);
            while ( getline(aux, x, ';') )
                v.push_back(stoi(x)); //incorporar al final del vector    
            p.varaggro = v;
        }
    }
    return f_in;
}

