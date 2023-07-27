/**********************************************************************/ /**
 * @file pr2_funciones_ordenar.h
 *
 * @brief Funciones de ORDENACION para la Practica n.2 de EDA-GIM
 *
 * Incluye 3 funciones tipicas de ordenacion de vectores:
 * 1) Insercion
 * 2) Seleccion
 * 3) Quicksort
 *
 * @version 2.0
 * @author Agustin Soares y Mario Gil Domingo
 * @date 17-10-2022
 */ /**********************************************************************/

#ifndef _PR2_FUNCIONES_ORDENAR_H_
#define _PR2_FUNCIONES_ORDENAR_H_

//#define NDEBUG
#include <assert.h>
#include <vector>
#include <cstdlib> // srand, rand; Equivalente C, #include <stdlib.h>
#include <ctime>   // Equivalente C, #include <time.h>

using namespace std;

// Tipos de datos utilizados
typedef int TDato;             // tipo de los valores de los vectores
typedef vector<TDato> TVector; // tipo vector

// Prototipos de las funciones incluidas en el archivo
size_t OrdenarInsercion(TVector&);
size_t OrdenarSeleccion(TVector&);
size_t OrdenarQuicksort(TVector&);
size_t Particion(TVector&, int, int);
bool Ordenado(TVector);
void Desordenar(TVector& v);

/**
 *  @brief Ordenar por Insercion
 *
 *  @param [in,out]  v  vector que contiene los datos
 *
 *  @return  pasos realizados
 *
 *  @post  {for_all alfa:0<alfa<v.size(): v[i]>=v[i-1]}
 *
 */
size_t OrdenarInsercion(TVector& v)
{
    int i, j;            // indices
    size_t n = v.size(); // talla, num. elementos de v
    size_t pasos = 0;    // pasos realizados

    if (n != 0)
        for (i = n - 2; i >= 0; i--)
        {
            v.push_back(v[i]); // poner centinela
            pasos++;
            j = i + 1;

            while (v[j] < v[n])
            {
                v[j - 1] = v[j];
                j++;
                pasos += 2;
            }
            v[j - 1] = v[n];
            pasos += 2;
            v.pop_back(); // quitar centinela
            pasos++;
        }
    assert(Ordenado(v));
    return pasos;
}

/**
 *
 *  @brief Ordenar por Seleccion
 *
 *  @param [in,out]  v  vector que contiene los datos
 *
 *  @return  pasos realizados
 *
 *  @post  {for_all alfa:0<alfa<v.size(): v[i]>=v[i-1]}
 *
 */
size_t OrdenarSeleccion(TVector& v)
{
    size_t i, j, pos_min; // indices
    size_t n = v.size();  // talla, num. elementos de v
    size_t pasos = 0;     // pasos realizados
    TDato aux;            // dato auxiliar

    if (n != 0)
        for (i = 0; i < n - 1; i++)
        {
            pos_min = i;
            for (j = i + 1; j < n; j++)
            {
                pasos++;
                if (v[j] < v[pos_min])
                    pos_min = j;
            }

            aux = v[i];
            v[i] = v[pos_min];
            v[pos_min] = aux;
            pasos += 3;
        }
    assert(Ordenado(v));
    return pasos;
}

/**
 *
 *  @brief Ordenar por Quicksort
 *
 *  @param [in,out]  v  vector que contiene los datos
 *
 *  @return  pasos realizados
 *
 *  @post  {for_all alfa:0<alfa<v.size(): v[i]>=v[i-1]}
 *
 */
size_t OrdenarQuicksort(TVector& v)
{
    size_t pasos = 0; // pasos realizados

    if (v.size() != 0)
        pasos = Particion(v, 0, v.size() - 1);
    assert(Ordenado(v));
    return pasos;
}

/**
 *
 *  @brief Particion del algoritmo de ordenacion Quicksort
 *
 *  @param [in,out]  v  vector que contiene los datos
 *  @param [in]  izq  Posicion izquierda donde empieza la particion.
 *  @param [in]  der  Posicion derecha donde acaba la particion.
 *
 *  @return  pasos realizados
 *
 */
size_t Particion(TVector& v, int izq, int der)
{
    int i, j;         // indices
    TDato aux, piv;   // dato auxiliar y pivote de la particion
    size_t pasos = 0; // pasos realizados

    piv = v[(izq + der) / 2];
    pasos++;
    i = izq;
    j = der;

    while (i <= j)
    {
        while (v[i] < piv)
        {
            i++;
            pasos++;
        }
        pasos++;
        while (piv < v[j])
        {
            j--;
            pasos++;
        }
        pasos++;

        if (i < j)
        {
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
            pasos += 3;
        }
        else if (i == j)
        {
            i++;
            j--;
        }
    }
    if (izq < j)
        pasos += Particion(v, izq, j);
    if (i < der)
        pasos += Particion(v, i, der);

    return pasos;
}

/**
 *
 *  @brief Comprobar si un vector esta ordenado de menor a mayor
 *
 *  @param [in]  v   vector que contiene los datos
 *  @retval true v ordenado
 *  @retval false v no ordenado
 *
 *  @post  {for_all alfa:0<alfa<n: v[i]>=v[i-1]}
 *
 */
bool Ordenado(TVector v)
{
    unsigned int i;
    bool orden = false;

    if (v.size() == 0)
        orden = true;
    else
    {
        i = 1;
        while ((i < v.size()) && (v[i] >= v[i - 1]))
            i++;
        if (i == v.size())
            orden = true;
    }
    return orden;
}

/**
 *  @brief Desordena aleatoriamente los elementos de un vector
 *
 *  @param [in,out]  v   vector que contiene los datos
 *
 */
void Desordenar(TVector& v)
{
    size_t i, cual; // indices
    TDato aux;      // dato auxiliar

    for (i = 0; i < v.size(); i++)
    {
        cual = rand() % v.size();
        aux = v[cual];
        v[cual] = v[0];
        v[0] = aux;
    }

    return;
}

#endif