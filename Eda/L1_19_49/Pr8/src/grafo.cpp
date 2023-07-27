/**
 * @file grafo.cpp
 * @brief Pr8: Implementacion de la clase Grafo
 *
 * @author: Agustin Soares y Mario Gil
 * @date: 16/12/22
 * @version 1.0
 */
 
#include "grafo.h"
#include <unordered_map>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

/**
 *  @brief Constructor de Grafo
 *
 *  @param [in]  tam Numero de nodos del grafo
 * 
 *  @pre tam > 0
 *  @exception out_of_range si no cumple precondicion
 */
Grafo::Grafo(size_t tam)
{
    if (tam <= 0)
        throw out_of_range("Grafo: tamanyo <= 0");
    arcos.resize(tam);
}

/**
 *  @brief Asignar un arco (dirigido) entre nodos del Grafo
 *
 *  @param [in]  orig nodo origen del arco
 *  @param [in]  dest nodo destino del arco
 *  @param [in]  p  peso asignado al arco
 * 
 *  @pre 0 <= orig <= Size() y 0 <= dest <= Size() 
 *  @exception out_of_range si no cumple precondicion
 */
void Grafo::AsignarArco(size_t orig, size_t dest, TipoPeso p)
{
    // Creamos iterador de tipo unordered map para recorrer los arcos
    std::unordered_map<size_t,TipoPeso> ::iterator it = arcos.at(orig).begin();
 
    if (orig < 0 || orig > Size())
        throw out_of_range("Grafo: Origen fuera de rango");
    else if (dest < 0 || dest > Size())
        throw out_of_range("Grafo: Destino fuera de rango");

    else
    {
        while ((it != arcos.at(orig).end()) && (it ->first != dest))
            it++ ;
        if (it == arcos.at(orig).end()) //añadimos el arco pq no existe
           arcos.at(orig).insert(make_pair(dest,p));
        else //cambiamos el peso pq ya existe
            it->second = p;
    }  

}

/**
 *  @brief Obtener el peso de un arco (dirigido) entre nodos del Grafo
 *
 *  @param [in]  orig nodo origen del arco
 *  @param [in]  dest nodo destino del arco
 *  @return peso del arco
 *  @retval 0 si no existe el arco
 * 
 *  @pre 0 <= orig <= Size() y 0 <= dest <= Size() 
 *  @exception out_of_range si no cumple precondicion
 */
TipoPeso Grafo::PesoArco(size_t orig, size_t dest) const
{
    TipoPeso p;
    // Creamos iterador de tipo unordered map para recorrer los arcos
    std::unordered_map<size_t,TipoPeso> ::const_iterator it = arcos.at(orig).begin();

    if (orig < 0 || orig > Size())
        throw out_of_range("Grafo: Origen fuera de rango");
    else if (dest < 0 || dest > Size())
        throw out_of_range("Grafo: Destino fuera de rango");
    else
    {
        while ((it != arcos.at(orig).end()) && (it-> first != dest) )
            it++;
        if (it != arcos.at(orig).end()) //existe el arco (orig,dest)
            p = it -> second;
        else
            p = 0; //Asume tipo numerico
    }

    return p;
}

/**
 * @brief Devolver la lista de nodos adyacentes a un nodo
 * 
 * @param i nodo del que se desean obtener los adyacentes
 * @return list<size_t> lista de nodos destino de los arcos
 *
 *  @pre 0 <= i <= Size()
 *  @exception out_of_range si no cumple precondicion
 */
vector<size_t> Grafo::NodosAdyacentes(size_t i) const
{
    std::unordered_map<size_t,TipoPeso> ::const_iterator it = arcos.at(i).begin();
    vector <size_t> adyacencias;
    
    if (i < 0 || i > Size())
        throw out_of_range("Grafo: Origen fuera de rango");
    else
    {
        while(it != arcos.at(i).end())
        {
            adyacencias.push_back(it ->first);
            it++;
        }
    }   
    return adyacencias; 
}        

/**
 *  @brief Numero de nodos del Grafo
 *
 *  @return numero de nodos
 */
size_t Grafo::Size() const
{
    return arcos.size();
}

/**
 * @brief Imprimir en pantalla los arcos de un nodo del Grafo
 * 
 * @param [in]  orig nodo cuyos arcos se muestran
 * 
 *  @pre 0 <= orig <= Size()
 *  @exception out_of_range si  no cumple precondicion
*/
void Grafo::Print(size_t orig) const
{
    unordered_map<size_t,TipoPeso>::const_iterator it;

    if ( orig < 0 || orig > this->Size() )
            throw out_of_range("Print: orig fuera de rango");

    else
    {
        cout << "Nodo " << orig << " (num.arcos=" << arcos[orig].size() << ")" << endl;
        cout << string(60,'-') << endl;
        for (it = arcos[orig].begin(); it != arcos[orig].end();  it++)
            cout << "<" << orig << "," << it->first << ">:" << it->second << " ";
        cout << endl;
        cout << string(60,'-') << endl;
    }
}

