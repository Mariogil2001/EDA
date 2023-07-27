/**
 * @file Punto2d.h
 * @brief Material de la Practica 1 de EDA (GIM).
 * 
 * Archivo de cabecera de la clase Punto2d
 *
 * @author Jesus Albert
 * @date 07/09/2022
 * @version 1.0
 */
 
#ifndef _PUNTO2D_H
#define _PUNTO2D_H

#include <iostream>
using namespace std;

/**
 * Clase Punto2d
 * @brief Representacion de puntos en un espacio 2D
 * 
 */
class Punto2d
{
    public:
    
        /**
         * @brief Crear un Punto2d inicializandolo a (0,0)
         * 
         */
        Punto2d()
        :x(0),y(0)
        {}
    
        /*
        * Crear un Punto2d con un valor inicial para las coordenadas x e y
        */
        Punto2d(float, float);
    
        /*
        * Establecer nuevos valores para las coordenadas del Punto2d.
        */
        void Set(float, float);
    
        /*
        * Obtener la coordenada x del Punto2d.
        */
        float GetX() const;
    
        /*
        * Obtener la coordenada y del Punto2d.
        */
        float GetY() const;
    
        /*
        * Desplazar un Punto2d, indicando:
        * desplazamiento en X
        * desplazamiento en Y
        */
        void Desplazar(float, float);
    
        /*
        * Rotar (respecto al origen) un Punto2d un angulo en radianes
        */
        void Rotar(float);
    
        /*
        * Comparar dos puntos e indicar si son iguales (estan en la misma ubicacion).
        */
        friend bool operator==(const Punto2d, const Punto2d);
        
        /*
        * Imprimir los datos del Punto2d
        */
        friend ostream& operator<<(ostream&, const Punto2d);
        
    private:
        float x; // Coordenada x del Punto2d
        float y; // Coordenada x del Punto2d
};

#endif
