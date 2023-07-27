/*
 * @file Estado.h
 * @brief Material de la Practica 4 de EDA (GIM).
 * 
 * Implementacion de la clase Estado
 *
 * @author Jesus Albert
 * @date 27/10/2021
 * @version 1.0
 */

#include "estado.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;

/**
 * @brief Constructor de Estado, inicializando todos los atributos a cero.
 * 
 */
Estado::Estado():
x(0.0), y(0.0), angulo(0.0)
{}

/**
 * @brief Constructor de Estado, inicializando a valores concretos.
 * 
 * @param a coord. x
 * @param b coord. y
 * @param c angulo
 */
Estado::Estado(double a, double b, double c)
:x(a), y(b), angulo(c) 
{}

/**
 * @brief Devuelve coordenada x 
 * 
 * @return double 
 */
double Estado::GetX()
{
    return x;
}

/**
 * @brief Devuelve coordenada y 
 * 
 * @return double 
 */
double Estado::GetY()
{
    return y;
}

/**
 * @brief Devuelve el angulo
 * 
 * @return double 
 */
double Estado::GetAngulo()
{
    return angulo;    
}

/**
 * @brief Establece todos los atributos del estado
 * 
 * @param a nueva coord. x
 * @param b nueva coord. y
 * @param c nuevo angulo
 */
void Estado::SetEstado(double a, double b, double c)
{
    x = a;
    y = b;
    angulo = c;
}

/**
 * @brief Desplazar el punto una cierta distancia segun el angulo de orientacion
 * 
 * @param dist distancia a desplazar
 */
void Estado::Desplazar(double dist)
{
    x += dist * cos(angulo);
    y += dist * sin(angulo);
}

/**
 * @brief Girar el angulo
 * 
 * @param giro rotacion a realizar
 */
void Estado::Girar(double giro)
{
    angulo += giro;
}

/**
 * @brief Operador salida, muestra los datos del estado
 * 
 * @param f flujo de salida
 * @param e estado a mostrar
 */
ostream& operator<<(ostream& f, Estado e)
{
    f << "(" << e.x << "," << e.y << ";" << e.angulo << ")";
    return f;
}
