/**
 * @file main.cpp
 * @brief Archivo principal de la Practica 4 de EDA (GIM).
 *
 * Generar curvas de Koch
 *
 * @author Agustin Soares y Mario Gil
 * @date 08/11/2021
 * @version 1.0
 */

/* Ordenes para gnuplot:
   reset session
   set size ratio -1
   plot "tarea1.txt" with vectors nohead
*/

#define _USE_MATH_DEFINES
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "estado.h"

using namespace std;

const string NOM_SALIDA = "data/"; //< Archivo de salida

unsigned int GeneraCurvaKoch(unsigned int nivel, double d, Estado &e, ofstream &f);
unsigned int GeneraCopoKoch(unsigned int nivel, double d, Estado& e, ofstream& f);
unsigned int GeneraAntiCurvaKoch(unsigned int nivel, double d, Estado &e, ofstream &f);
unsigned int GeneraAntiCopoKoch(unsigned int nivel, double d, Estado& e, ofstream& f);



int main()
{
    Estado e;
    ofstream f_out, f_copos;
    int nivel, tamanyo = 10;
    unsigned int segmentos = 0;

    e.SetEstado(75, 100, M_PI / 3);

    for (int i = 0; i <= 5; i++)
    {
        nivel = i;
        f_out.open(NOM_SALIDA + "koch" + to_string(i) +".txt" );
        f_copos.open(NOM_SALIDA + "antikoch" + to_string(i) +".txt" );

        if (!f_out)
            cerr << NOM_SALIDA << ": Error al abrir el archivo." << endl;
        else
        {
            segmentos = GeneraCopoKoch(nivel, tamanyo, e, f_out);

            f_out.close();
        }
         if (!f_copos)
            cerr << NOM_SALIDA << ": Error al abrir el archivo." << endl;
        else
        {
            segmentos = GeneraAntiCopoKoch(nivel,tamanyo,e,f_copos);

            f_copos.close();
        }

    }

    cout << "Nivel " << nivel << ": " << segmentos << " segmentos." << endl;

    return 0;
}

/**
 * @brief Funcion que genera la curva de Koch de un tamaño y nivel
 *
 * @param nivel [in] escala de detalle
 * @param d [in] tamaño de la forma
 * @param e [in] estado espacial
 * @param f [out] archivo de salida
 * @return número de segmentos generados por la curva
 */
unsigned int GeneraCurvaKoch(unsigned int nivel, double d, Estado &e, ofstream &f)
{
    unsigned int segmentos = 0;
    double dx , dy;
    if (nivel == 0)
    {
        dx = d*cos(e.GetAngulo());
        dy = d*sin(e.GetAngulo());
        f  << e.GetX() << "\t" << e.GetY() << "\t" << dx << "\t" << dy << endl;
        e.Desplazar(d);
        segmentos++;
    }
    else
    {
        GeneraCurvaKoch(nivel - 1 , d/3, e, f);
        e.Girar(M_PI / 3);
        GeneraCurvaKoch(nivel - 1, d / 3, e, f);
        e.Girar(-2 * M_PI / 3);        
        GeneraCurvaKoch(nivel - 1, d / 3, e, f);
        e.Girar(M_PI / 3);        
        GeneraCurvaKoch(nivel - 1, d / 3, e, f);
    } 

    return segmentos;
}

/**
* @brief Genera el copo de nieve de Koch formado por 3 curvas de Koch
*
* @param nivel [in] escala de detalle
* @param d [in] tamaño de la forma
* @param e [in] estado espacial
* @param f [out] archivo de salida
* @return número de segmentos generados por la figura
*/
unsigned int GeneraCopoKoch(unsigned int nivel, double d, Estado& e, ofstream& f)
{
    unsigned int segmentos = 0;
        segmentos += GeneraCurvaKoch(nivel , d, e, f);
        e.Girar(- 2 * M_PI / 3);
        segmentos += GeneraCurvaKoch(nivel, d, e, f);
        e.Girar(- 2 * M_PI / 3);  
        segmentos += GeneraCurvaKoch(nivel, d, e, f);
      
    return segmentos;
}



/**
 * @brief Funcion que genera la anti curva de Koch de un tamaño y nivel
 *
 * @param nivel [in] escala de detalle
 * @param d [in] tamaño de la forma
 * @param e [in] estado espacial
 * @param f [out] archivo de salida
 * @return número de segmentos generados por la curva
 */

unsigned int GeneraAntiCurvaKoch(unsigned int nivel, double d, Estado &e, ofstream &f)
{
    unsigned int segmentos = 0;
    double dx , dy;
    if (nivel == 0)
    {
        dx = d*cos(e.GetAngulo());
        dy = d*sin(e.GetAngulo());
        f  << e.GetX() << "\t" << e.GetY() << "\t" << dx << "\t" << dy << endl;
        e.Desplazar(d);
        segmentos++;
    }
    else
    {
        GeneraAntiCurvaKoch(nivel - 1 , d/3, e, f);
        e.Girar(- M_PI / 3);
        GeneraAntiCurvaKoch(nivel - 1, d / 3, e, f);
        e.Girar( 2 * M_PI / 3);        
        GeneraAntiCurvaKoch(nivel - 1, d / 3, e, f);
        e.Girar( - M_PI / 3);        
        GeneraAntiCurvaKoch(nivel - 1, d / 3, e, f);
    } 

    return segmentos;
}

/**
* @brief Genera el anti copo de nieve de Koch formado por 3 curvas de Koch
*
* @param nivel [in] escala de detalle
* @param d [in] tamaño de la forma
* @param e [in] estado espacial
* @param f [out] archivo de salida
* @return número de segmentos generados por la figura
*/
unsigned int GeneraAntiCopoKoch(unsigned int nivel, double d, Estado& e, ofstream& f)
{
    unsigned int segmentos = 0;
        segmentos += GeneraAntiCurvaKoch(nivel , d, e, f);
        e.Girar(- 2 * M_PI / 3);
        segmentos += GeneraAntiCurvaKoch(nivel, d, e, f);
        e.Girar(- 2 * M_PI / 3);  
        segmentos += GeneraAntiCurvaKoch(nivel, d, e, f);
      
    return segmentos;
}