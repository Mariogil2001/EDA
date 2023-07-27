/**
 * @file estado.h
 * @brief Material de la Practica 4 de EDA (GIM).
 * 
 * Archivo de cabecera de la clase Estado
 * Representa un estado con una ubicación espacial 2D (x,y) + un ángulo de orientación
 *
 * @author Jesus Albert
 * @date 27/10/2021
 * @version 1.0
 */

#ifndef _ESTADO_H_
#define _ESTADO_H_

#include <iostream>
using namespace std;

/**
 * @brief Clase Estado que define el estado del dibujo (coordenadas y angulo de orientacion):
 * Donde estamos ubicados en el espacio (x,y) y con que orientacion.
 * 
 */
class Estado
{

    public:   
        //Crea un estado inicializando todos los atributos a cero.
        Estado();
        //Crea un estado inicializando a valores concretos.
        Estado(double,double,double);
        //Obtiene la coordenada x.
        double GetX();
        //Obtiene la coordenada y.
        double GetY();
        //Obtiene el angulo.
        double GetAngulo();
        //Establece la posición y orientación 
        void SetEstado(double,double,double);
        //Desplazar punto una determinada distancia, en función del ángulo
        void Desplazar(double);
        //Girar ángulo de orientación
        void Girar(double);
        //Operador salida
        friend ostream& operator<<(ostream&, Estado);
    
    private:
        double x,y; ///< Coordenadas actuales
        double angulo;  ///< Ángulo en radianes
};

#endif
