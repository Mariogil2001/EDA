/*
 * @file Punto2d.cpp
 * @brief Material de la Practica 1 de EDA (GIM).
 * 
 * Implementacion de la clase Punto2d
 *
 * @author Jesus Albert
 * @date 07/09/2022
 * @version 1.0
 */

#include <iostream>
#include <math.h>
#include "punto2d.h"

using namespace std;

/** 
 * Diferencia maxima que se considera cero al comparar dos reales
 */
const float CERO = 0.0001;

/**
 * @brief Construir un Punto2d con un valor inicial para x e y
 * @param [in] a valor inicial de x
 * @param [in] b valor inicial de y
 */
Punto2d::Punto2d(float a, float b) 
{
    this->x = a;
    this->y = b;
} 

/**
* @brief Asignar nuevos valores al modulo y al argumento del Punto2d.
* @param [in] a Nuevo valor de x
* @param [in] b Nuevo valor de y
*/
void Punto2d::Set(float a, float b)
{
    this->x = a;
    this->y = b;  
}

/**
* @brief Obtener la coordenada x del Punto2d
* @return coordenada x
*/
float Punto2d::GetX() const 
{
    return this->x;
}

/**
* @brief Obtener la coordenada y del Punto2d
* @return coordenada y
*/
float Punto2d::GetY() const 
{
    return this->x;
}

/**
* @brief Desplazar un Punto2d.
* @param [in] dx Desplazamiento en X
* @param [in] dy Desplazamiento en Y
*/
void Punto2d::Desplazar(float dx, float dy)
{
    this->x += dx;
    this->y += dy;
}

/**
* @brief Rotar un Punto2d respecto al origen
* @param [in] a angulo de rotacion en radianes
*/
void Punto2d::Rotar(float a)
{
    float xb, yb;
    xb = this->x*cos(a) - this->y*sin(a);
    yb = this->x*sin(a) + this->y*cos(a);
    this->Set(xb,yb);
}

/**
* @brief Comparar dos puntos e indicar si son iguales (estan en la misma ubicacion).
* @param [in] a Primer elemento de la comparación.
* @param [in] b Segundo elemento de la comparación.
* @retval true a y b son iguales
* @retval false a y b son diferentes
*/
bool operator==(const Punto2d a, const Punto2d b)
{
    bool eq = false;
    if ( (fabs(a.x - b.x) < CERO) && (fabs(a.y - b.y) < CERO) )
        eq = true;
    return eq;
}

/**
* @brief Imprimir un Punto2d.
*/
ostream& operator<<(ostream& s, const Punto2d c)
{
    s << "(" << c.x << "," << c.y << ")";
    return s;
} 

