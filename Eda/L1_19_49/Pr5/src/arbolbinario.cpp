/**
 * @file arbolbinario.cpp
 * @author Jesus Albert
 * @brief Implementacion de la clase ArbolB (arbol binario generico)
 * @version 2.0
 * @date 2022-11-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdexcept>
#include <string>
#include <iostream>
#include "arbolbinario.h"

using namespace std;

/**
 * @brief Constructor del arbol
 * 
 */
ArbolB::ArbolB()
:raiz(nullptr)
{}

/**
 * @brief Generar un nuevo arbol con raiz, izquierda y derecha
 * 
 * @param x dato de la raiz del arbol
 * @param i subarbol izquierdo del nuevo arbol
 * @param d subarbol derecho del nuevo arbol
 */
void ArbolB::Plantar(Tipo x, const ArbolB& i, const ArbolB& d)
{
    if ( raiz != nullptr )
	{
    	Vaciar(raiz);
		raiz=nullptr;
	}
    raiz = new NodoBin();
    raiz->dato = x;
	Copiar(i.raiz,raiz->izq);
	Copiar(d.raiz,raiz->der);
}

/**
 * @brief Devolver el subarbol izquierdo
 * 
 * @pre Arbol no vacio
 * @exception runtime_error
 * @return ArbolB 
 */
ArbolB ArbolB::Subarb_izq() const
{
	if ( Vacio() )
		throw runtime_error("Subarb_izq: Precondicion");
	else
	{
		ArbolB tree;
		Copiar(raiz->izq,tree.raiz);
		return tree;
	}
}

/**
 * @brief Devolver el subarbol derecho
 * 
 * @pre Arbol no vacio
 * @exception runtime_error
 * @return ArbolB 
 */
ArbolB ArbolB::Subarb_der() const
{
	if ( Vacio() )
		throw runtime_error("Subarb_der: Precondicion");
	else
	{
		ArbolB tree;
		Copiar(raiz->der,tree.raiz);
		return tree;
	}
}

/**
 * @brief Devolver el dato en la raiz del arbol
 * 
 * @pre Arbol no vacio
 * @exception runtime_error
 * @return Tipo 
 */
Tipo ArbolB::Raiz() const
{
	if ( Vacio() )
		throw runtime_error("Raiz: Precondicion");
	else
		return raiz->dato;	
}

/**
 * @brief Validar si el arbol esta vacio
 * 
 * @return true si arbol vacio
 * @return false si arbol NO vacio
 */
bool ArbolB::Vacio() const
{
	return raiz==nullptr;
}

/**
 * @brief Constructor de copia de la clase
 * 
 * @param orig origen de la copia
 */
ArbolB::ArbolB(const ArbolB& orig)
{
	raiz = nullptr;
	Copiar(orig.raiz,raiz);
}

/**
 * @brief Operador asignacion de arboles
 * 
 * @param orig origen de la asignacion (rvalue)
 * @return ArbolB& 
 */
ArbolB& ArbolB::operator=(const ArbolB& orig)
{
	Vaciar(raiz);
	Copiar(orig.raiz,raiz);
	return *this;
}

/**
 * @brief Copiar un arbol en otro a partir de los punteros raices de los arboles
 * 
 * @param ptr_orig puntero al origen de la copia
 * @param ptr_dest puntero al destino de la copia
 */
void ArbolB::Copiar(ArbolB::PunteroNodoBin ptr_orig, ArbolB::PunteroNodoBin& ptr_dest) const
{
	if ( ptr_orig != nullptr )
	{
		ptr_dest = new NodoBin();
		ptr_dest->dato = ptr_orig->dato;
		Copiar(ptr_orig->izq, ptr_dest->izq);
		Copiar(ptr_orig->der, ptr_dest->der);
	}
	else
		ptr_dest = nullptr;
}

/**
 * @brief Destructor de la clase
 * 
 */
ArbolB::~ArbolB()
{
 	if (raiz != nullptr)
		Vaciar(raiz); 
}

/**
 * @brief Vaciar y liberar la memoria de un arbol
 * 
 * @param p puntero a la raiz del arbol
 */
void ArbolB::Vaciar(PunteroNodoBin& p)
{
	if ( p != nullptr )
	{
		Vaciar(p->izq);
		Vaciar(p->der);
		try
		{
		 	delete p;
		 	p = nullptr;
		}
		catch(...)
		{
			cerr << "ArbolB::Vaciar --> Error DELETE" << endl;
		}
	}
}

/**
 * @brief Mostrar por pantalla los datos del arbol en orden prefijo
 * Un subarbol vacio se representa con "."
 */
void ArbolB::Imprimir()
{
	if ( raiz!=nullptr )
	{
		cout << raiz->dato << endl ;
		Subarb_izq().Imprimir();
		Subarb_der().Imprimir();
	}
	else
		cout << "." << endl ;
}
