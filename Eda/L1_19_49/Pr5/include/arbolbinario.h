/**
 * @brief Interfaz de la Clase Arbol Binario (generico)
 * 
 */
 
#ifndef _ARBOL_B_H_
#define _ARBOL_B_H_
 
#include <string>
	
using namespace std;

/*
Tipo de los datos almacenados en el arbol
Modificar por lo que corresponda
*/
typedef string Tipo; 

class ArbolB
{
	public:
		ArbolB();
		void Plantar(Tipo, const ArbolB&, const ArbolB&);
		ArbolB Subarb_izq () const;
		ArbolB Subarb_der () const;
		Tipo Raiz() const;
		bool Vacio() const;
		//Constructor de copia, destructor, asignacion
		ArbolB(const ArbolB&);
		ArbolB& operator=(const ArbolB&);
		~ArbolB();
		//Imprimir en pantalla los datos del arbol
		void Imprimir();
	private:
		//Tipo Nodo
		class NodoBin;
		typedef NodoBin* PunteroNodoBin ;
		class NodoBin
		{
			public:
				Tipo dato;
				PunteroNodoBin izq;
				PunteroNodoBin der;
				NodoBin()
				:dato(),izq(nullptr),der(nullptr){}
		};

		//Raiz del arbol
		PunteroNodoBin raiz;
		
		//Metodos auxiliares para copiar y vaciar
		void Copiar(PunteroNodoBin, PunteroNodoBin&) const;
		void Vaciar(PunteroNodoBin&);
};

#endif
