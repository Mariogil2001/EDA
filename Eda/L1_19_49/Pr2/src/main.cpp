#include <iostream>
#include <assert.h>
#include <vector>
#include <cstdlib>       // srand, rand; Equivalente C, #include <stdlib.h>
#include <ctime>         // Equivalente C, #include <time.h>
#include <fstream>       // Libreria 

#include "pr2_funciones_ordenar.h"

using namespace std;

// Tipos de datos utilizados
typedef int TDato;             // tipo de los valores de los vectores
typedef vector<TDato> TVector; // tipo vector

// Prototipos de las funciones incluidas en el archivo
void Experimento(unsigned, unsigned, int);
void Guardar (ofstream &, TVector, TVector, TVector, int); 


/**
 * @brief Ejecuta los tres metodos de ordenacion y escribe los resultados en diferentes archivos de texto.
 * 
 * @param tini Talla inicial
 * @param tfin Talla Final
 * @param inc  Valor de Incremento de las tallas
 */

void Experimento(unsigned int tini, unsigned int tfin, int inc)
{
    TVector vOriginal, vCrec, vDecr;
    // Vectores con la media de cada iteracion
    TVector vMediaIns, vMediaSel, vMediaQs;
    // Vectores con los pasos crecientes y decrecientes
    TVector TInsCre, TSelCre, TQsCre, TInsDecr, TSelDecr, TQsDecr;
    float TInsRan, TSelRan, TQsRan;
    ofstream f_out;

    unsigned int n = tfin - tini;
    unsigned int k = tini + inc;

    while ( k <= n)
    {
        TInsRan = 0.0;
        TSelRan = 0.0;
        TQsRan = 0.0;
        // Tenemos que contar los pasos utilizando los tres metodos de ordenacion sobre un vector creciente, uno decreciente y uno random
        // Creamos un vector ordenado para usarlo como vector de base
        for (unsigned int i = 0; i < k; i++)
            vOriginal.push_back(i);

        vCrec = vOriginal;                             // Creamos una copia del vector base (creciente)
        TInsCre.push_back(OrdenarInsercion(vCrec));    // Ordenamos el vector copia con Insercion y guardamos el numero de pasos
        TSelCre.push_back(OrdenarSeleccion(vCrec));    // Ordemanos el vector copia con Seleccion y guardamos el num de pasos
        TQsCre.push_back(OrdenarQuicksort(vCrec));     // Ordenamos el vector copia con Qs y guardamos el num de pasos

        vOriginal.clear();                             // Vaciar el vector original
        
        for (unsigned int i = k; i > 0; i--)           // Rellenar el vector original de manera decreciente
            vOriginal.push_back(i);

        vDecr = vOriginal;                             // Creamos una copia del vector original (ahora decreciente)
        TInsDecr.push_back(OrdenarInsercion(vDecr));   // Ordenamos el vector copia con Insercion y guardamos el num de pasos
    
        vDecr = vOriginal;                             // Volvemos a copia el vector original para trabajar con el vector decreciente
        TSelDecr.push_back(OrdenarSeleccion(vDecr));   // Ordemanos el vector copia con Seleccion y guardamos el num de pasos

        vDecr = vOriginal;                             // Volvemos a copia el vector original para trabajar con el vector decreciente
        TQsDecr.push_back(OrdenarQuicksort(vDecr));    // Ordenamos el vecttor copia con Qs y guardamos el num de pasos

        for (unsigned int i = 0; i < k; i++)
        {
            Desordenar(vOriginal);                     // Desordenar el vector de manera aleatoria y ordenar con los diferentes metodos
            TInsRan += OrdenarInsercion(vOriginal);
            Desordenar(vOriginal);
            TSelRan += OrdenarSeleccion(vOriginal);
            Desordenar(vOriginal);
            TQsRan += OrdenarQuicksort(vOriginal);
        }


        vMediaIns.push_back(TInsRan / k);
        vMediaSel.push_back(TSelRan / k);
        vMediaQs.push_back(TQsRan / k);
        k+= inc;      

        vOriginal.clear();
    }
        // Se deben escribir los resultados en un archivo de salida
        f_out.open ("data/salida_INS.dat");
        if (!f_out) cout << "Error al abrir el fichero " << "salida_INS.dat";
        else 
        {
            Guardar (f_out, TInsCre, TInsDecr, vMediaIns, inc);
            f_out.close ();
        }
        
        f_out.open ("data/salida_SEL.dat");
        if (!f_out) cout << "Error al abrir el fichero " << "salida_SEl.dat";
        else 
        {
            Guardar (f_out, TSelCre, TSelDecr, vMediaSel, inc);
            f_out.close ();
        }
        
        f_out.open ("data/salida_QS.dat");
        if (!f_out) cout << "Error al abrir el fichero " << "salida_QS.dat";
        else 
        {
            Guardar (f_out,TQsCre, TQsDecr, vMediaQs, inc);
            f_out.close ();
        } 
    
}

/**
 *
 * Guarda las medias de los valores obtenidos en la funcion experimento
 *
 * @param [in] mejor TVector vector con los pasos del vector ordenado de manera creciente
 * @param [in] peor TVector vector con los pasos del vector ordenado de manera decreciente
 * @param [in] medio TVector vector con los pasos del vector ordenado de manera aleatorio
 * @param [in] inc entero que muestra el incremento de la talla cada caso
 * @param [out] f fichero
 *
 */ 

void Guardar (ofstream & out, TVector mejor, TVector peor, TVector medio, int inc)
{
    int aux = inc;
    for(unsigned int i = 0; i < medio.size(); i ++)
    {
        out << aux << " ";
        out << mejor.at(i) << " ";
        out << peor.at(i) << " ";
        out << medio.at(i) << endl; 
        aux +=inc;
    }
}

int main()
{
    unsigned int tini = 0;
    unsigned int tfin = 1000;
    int inc= 25;
    
    Experimento(tini,tfin,inc);
	

    return 0;    
}

