/**
 * @file Triangulo.h
 * @brief Material de la Practica 1 de EDA (GIM).
 * 
 * Archivo de cabecera de la clase Triangulo
 *
 * @author Jesus Albert
 * @date 07/09/2022
 * @version 1.0
 */
 
#ifndef _TRIANGULO_H
#define _TRIANGULO_H

#include <iostream>
#include "punto2d.h"
#include <cassert>

using namespace std;

/**
 * Clase Triangulo
 * @brief Representacion de un triangulo (2D)
 * 
 */
class Triangulo
{
    public:
        /*
        * Crear un Triangulo por defecto
        */
        Triangulo();
        /*
         * Establecer punto del vertice 0
         */
        void SetV0 (Punto2d);
        /*
         * Establecer punto del vertice 1
         */
        void SetV1 (Punto2d);
        /*
         * Establecer punto del vertice 2
         */
        void SetV2 (Punto2d);
        /*
        * Desplazar un Triangulo, indicando:
        * desplazamiento en X
        * desplazamiento en Y
        */
        void Desplazar(float, float);

        /*
        * Rotar (respecto al origen) un Triangulo un angulo en radianes
        */
        void Rotar(float);

        /*
        * Comparar dos triangulos e indicar si son iguales (estan en la misma ubicacion).
        */
        friend bool operator==(const Triangulo, const Triangulo);
        
        /*
        * Imprimir los vecrtices del Triangulo
        */
        friend ostream& operator<<(ostream&, const Triangulo);
        
    private:
        Punto2d vert[3]; // Los 3 vertices del triangulo
        
        /*
        * Invariante de la clase triangulo
        */
      
    bool Invariante() const
    {
        bool dev = true;
        unsigned int i;
    
        if (vert[0] == vert[1] || vert[1] == vert[2] || vert[0] == vert[2])
            dev = false;
        
        for (i = 0; i < 3 && dev == true; i++)
        {
            if (0 > vert[i].GetX() || vert[i].GetX() > 1920)
                dev = false;
            if (0 > vert[i].GetY() || vert[i].GetY() > 1080)
                dev = false;
        }

        return dev;
    }
};

#endif