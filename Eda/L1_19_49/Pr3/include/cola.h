/**
 * @file cola.h
 * @brief Material de la Practica 3 de EDA (GIM).
 * 
 * template class Cola
 *
 * @author Mario Gil y Agustin Soares
 * @date 25/10/2022
 * @version 1.0
 */
 
#ifndef _COLA_H_
#define _COLA_H_

#include <queue>
#include <stdexcept>
#include <iostream>

using namespace std;

/**
 * Clase Cola (template)
 * @class Cola
 * @brief Plantilla para clases Cola de cualquier tipo
 * 
 */
template <class E>
class Cola
{
	public:
		Cola();
		void Encolar(E);
		void Desencolar();
		E PrimeroCola();
		bool ColaVacia();
		int DevuelveTam();

	private:
        queue<E> datos;
};

/**
 * Constructor de una cola vacia
 */
template <class E>
Cola<E>::Cola()
:datos()
{}

/**
 * Guardar un nuevo elemento en la cola
 * @pre hay espacio disponible en memoria
 * @exception bad_alloc fallo al reservar memoria
 * @param[in] x elemento a�adido
 */
template <class E>
void Cola<E>::Encolar(E x)
{
	try
	{
		datos.push(x);
	}
	catch(exception& e)
	{
		cerr << e.what() << endl;
		throw bad_alloc();
	}
}

/**
 * Eliminar un elemento de la cola
 * @pre cola no vacia
 * @exception runtime_error cola vacia
 */
template <class E>
void Cola<E>::Desencolar()
{
	//COMPLETAR:
	//SI LA COLA ESTA VACIA SE DEBE LANZAR UNA EXCEPCION runtime_error
	//PARA CUMPLIR CON LA PRECONDICION

	try
	{
		datos.pop();
	}
	catch(exception& e)
	{
		cerr << e.what() << '\n';
		throw(runtime_error("Cola::Desencolar()"));
	}
}

/**
 * Consultar el PRIMER elemento de la cola
 * @pre cola no vacia
 * @exception runtime_error cola vacia
 * @return E
 */
template <class E>
E Cola<E>::PrimeroCola()
{
	//COMPLETAR:
	//SI LA COLA ESTA VACIA SE DEBE LANZAR UNA EXCEPCION runtime_error
	//PARA CUMPLIR CON LA PRECONDICION
	try
	{
		return datos.front();
	}
	catch(exception& e)
	{
		cerr << e.what() << '\n';
		throw(runtime_error("Cola::PrimeroCola()"));
	}
}

/**
 * Comprobar si la pila esta vacia
 * @retval true cola vacia
 * @retval false no vacia
 */
template <class E>
bool Cola<E>::ColaVacia()
{
   return datos.empty();
}

template <class E>
int Cola<E>::DevuelveTam()
{
	return datos.size();
}

#endif
