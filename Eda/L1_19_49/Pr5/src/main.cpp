/**
 * @file main.cpp
 * @author Agustin Soares y Mario Gil
 * @brief Implementacion de la Practica 5
 * @version 1.0
 * @date 2022-11-13
 *
 */

#include <stdexcept>
#include <string>
#include <iostream>
#include <fstream>
#include "arbolbinario.h"

using namespace std;

const string F_ENTRADA = "data/arbolDecision.txt";

void GenerarArbol(ifstream & f, ArbolB &a);
void DeducirPersonaje(ArbolB &);

int main()
{
    ifstream f;
    ArbolB arbol;

    f.open(F_ENTRADA);
    if (!f)
        cerr << "Error al arbir fichero" << endl;
    else
        GenerarArbol (f, arbol);
    
    f.close();

//  arbol.Imprimir();

    cout << "\n Juego Quien es Quien" << endl;
    cout << "#######################" << endl << endl;
    DeducirPersonaje (arbol);

    return 0;
}

/**
 * @brief Generar el arbol de decision a partir de los datos del archivo f
 *
 * @param f archivo con los datos del arbol, debe estar previamente abierto
 * @param a arbol generado
 */
void GenerarArbol(ifstream &f, ArbolB &a)
{
    string contenido;
    ArbolB i;
    ArbolB d;

    getline(f, contenido);
    
    if (contenido != ".")
    {
        GenerarArbol(f, i);
        GenerarArbol(f, d);
        a.Plantar(contenido, i, d);
    }
}

/**
 * @brief Deduce el personaje elejido por el usuario
 *
 * @param arbol arbol generado
 */
void DeducirPersonaje(ArbolB & arbol)
{
    char respuesta;
    ArbolB subI, subD;
    subI = arbol.Subarb_izq();
    subD = arbol.Subarb_der();

    if (subI.Vacio() && subD.Vacio())
    {
        cout << "El personaje es " << arbol.Raiz() << endl;
    }
    else
    {
        cout << "Pregunta (S/N): " << arbol.Raiz() << endl;
        cin >> respuesta;
        if (respuesta == 'N' || respuesta == 'n')
        {
            arbol = arbol.Subarb_izq();
            DeducirPersonaje(arbol);
        }
        else if (respuesta == 'S' || respuesta == 's')
        {
            arbol = arbol.Subarb_der();
            DeducirPersonaje(arbol);
        } 
    }
}