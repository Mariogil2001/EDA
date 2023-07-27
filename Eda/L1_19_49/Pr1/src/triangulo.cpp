/*
 * @file triangulo.cpp
 * @brief Material de la Practica 1 de EDA (GIM).
 *
 * Implementacion de la clase Triangulo
 *
 * @author Mario Gil Domingo
 * @author Agustin Maria Soares
 * @date 06/10/2022
 * @version 1.0
 */

#include <iostream>
#include <math.h>
#include "triangulo.h"
#include <cassert>

using namespace std;


/**
 * @brief Construir un triangulo con un valor inicial para cada vertice.
 */
Triangulo::Triangulo()
{
    vert[0].Set(0.0,1.0);
    vert[1].Set(2.0,0.0);
    vert[2].Set(1.0,2.0);
    
    assert(Invariante());
}

/**
 * @brief Asignar nuevos valores a los puntos del vertice 0.
 * @param [in] Punto2d Punto con los valores nuevos.
 */
void Triangulo::SetV0(Punto2d p)
{
    vert[0] = p;

    assert(Invariante());
}

/**
 * @brief Asigna nuevos valores a los puntos del vertice 1.
 * 
 * @param [in] Punto2d p Punto con los nuevos valores.
 */

void Triangulo::SetV1(Punto2d p)
{
    vert[1] = p;

    assert(Invariante());
}

/**
 * @brief Asigna nuevos valores a los puntos del vertice 2.
 * 
 * @param [in] Punto2d p Punto con los nuevos valores.
 */

void Triangulo::SetV2(Punto2d p)
{
    vert[2] = p;

    assert(Invariante());
}

/*
 * 
 */
/**
 * @brief Desplazar un Triangulo, indicando:
 * desplazamiento en X
 * desplazamiento en Y
 * 
 * @param [in] x Coordenada con el valor a desplazar.
 * @param [in] y Coordenada con el valor a desplazar.
 */

void Triangulo::Desplazar(float x, float y)
{
    vert[0].Desplazar(x,y);
    vert[1].Desplazar(x,y);
    vert[2].Desplazar(x,y);

    assert(Invariante());
}

/*
 * @brief Rotar (respecto al origen) un Triangulo un angulo en radianes
 *
 * @param [in] x float con el grado de rotacion de la figura
 */
void Triangulo::Rotar(float x)
{
    vert[0].Rotar(x);
    vert[1].Rotar(x);
    vert[2].Rotar(x);

    assert(Invariante());
}

/*
 * Comparar dos triangulos e indicar si son iguales (estan en la misma ubicacion).
 */
bool operator==(const Triangulo t1, const Triangulo t2)
{
    bool iguales = false;
    int i, j;

    for(i = 0; i < 3; i++)
    {
        if (t1.vert[i] == t2.vert[i])
            j++;
    }

    if (j == 3)
        iguales = true;

    return iguales;
}

/*
 * Imprimir los vertices del Triangulo
 */
ostream &operator<<(ostream & out, const Triangulo t)
{
    int i;
    for(i = 0; i < 3; i++)
        out << t.vert[i];

    return out;    
}
