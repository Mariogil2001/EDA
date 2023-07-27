/**
 * @file main.cpp
 * @brief Pr8: Implementacion del main
 *
 * @author: Agustin Soares y Mario Gil
 * @date: 16/12/22
 * @version 1.0
 */

#include "grafo.h"
#include "pr8.h"
#include <unordered_map>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string FICH = "data/escenario_small.dat";     // Direccion del fichero a utilizar
const size_t PESO = 1;                              // Peso de los arcos

// Tarea 2. Lectura del escenario
Escenario LeerEscenario (string);                   // Crea un escenario a partir de los datos de un fichero.
void ImprimirEscenario(Escenario);                  // Imprime por pantalla los datos del escenario.

// Tarea 3. Construcción del grafo de escenario
void ConstruirGrafo(Grafo &, const Escenario &);    // Construye el grafo de movilidad entre posiciones del escenario.
// Tarea 4. Exploración del grafo
vector<bool> DFS(Grafo, size_t);                    // Exploración en profundidad (DFS) de un grafo desde un nodo origen.
void DFSAux(Grafo, size_t, vector<bool> &);         // Recorre nodos para verficiar si son adyacentes.
size_t PrimerLibre(Escenario);                      // Devuelve la primera posicion libre del escenario.

/**
 *  @brief Programa principal
 */
int main()
{
    Escenario escenario;

    escenario = LeerEscenario(FICH);
    //ImprimirEscenario(escenario);

    size_t tam = escenario.alto * escenario.ancho;
    Grafo grafo(tam);

    ConstruirGrafo(grafo, escenario);
    PintarEscenario(escenario);

    //size_t origen = PrimerLibre(escenario);
    //cout << "La primera posicion libre es: " << origen << endl;
    
    //vector<bool> nodosVisitados;
    escenario.posiciones = DFS(grafo, 11);
    PintarEscenario(escenario);

    return 0;
}

/**
 *  @brief Crea un escenario a partir de los datos de un fichero.
 *
 *  @param [in]  fich Direccion del fichero a usar
 *
 *  @return Escenario completo
 */
Escenario LeerEscenario(string fich)
{
    ifstream f;
    Escenario escenario;
    string sAlto, sAncho;
    char caracter;
    bool libre;

    f.open(fich);
    if (!f)
        cout << "Error al abrir el fichero/n";
    else
    {
        f >> sAlto;                         // Se almacena el valor del alto del escenario (string)
        f >> sAncho;                        // Se almacena el valor del ancho del escenario (string)
        escenario.alto = stoi(sAlto);       // Transformamos el valor de la altura a un tipo int
        escenario.ancho = stoi(sAncho);     // Transformamos el valor de la altura a un tipo int
        for (unsigned int i = 0; i < escenario.alto * escenario.ancho; i++)     // Para cada posicion del escenario...
        {
            f >> caracter;                  // Se almacena el valor de la posicion
            if (caracter == 'X')            // La posicion esta obstaculizada?
                libre = false;              // Si -> no esta libre
            else
                libre = true;               // No -> esta libre
            escenario.posiciones.push_back(libre);  // Anadimos si la posicion esta libre o no al vector de posiciones del escenario
        }
    }
    f.close();
/*
    for (unsigned int i = 0; i < escenario.alto * escenario.ancho; i++)
    {
        cout << escenario.posiciones[i] << " ";
    }
*/
    return escenario;
}

/**
 *  @brief Muestra por pantalla los datos de un escenario.
 *
 *  @param [in]  escenario Estructura escenario para el uso de sus datos.
 */
void ImprimirEscenario(Escenario escenario)
{
    unsigned int posicionesTot = escenario.alto * escenario.ancho;
    unsigned int libres = 0, obstaculos = 0;

    for (unsigned int i = 0; i < posicionesTot; i++)
    {
        if (escenario.posiciones[i] == true)
            libres++;               // Conteo de posiciones libres
        else
            obstaculos++;           // Conteo de posiciones obstaculizadas
    }

    cout << "Dimensiones del Mapa: " << escenario.alto << " * " << escenario.ancho << endl;
    cout << "Posiciones totales: " << posicionesTot << endl;
    cout << "Posiciones transitables: " << libres << endl;
    cout << "Posiciones ocupadas: " << obstaculos << endl;
}

/**
 *  @brief Construye un Grafo a partir de una estructura.
 *
 *  @param [in]  grafo      Modifica un grafo con los nodos y arcos del escenario
 *  @param [in]  escenario  Define la construccion del grafo
 */
void ConstruirGrafo(Grafo & grafo, const Escenario & escenario)
{
    vector<size_t> vecinos;

    for (size_t i = 0; i < escenario.alto*escenario.ancho; i++)
    {
        vecinos = Vecinos(i, escenario);                // Se calculan los vecinos de cada posicion
        for (size_t j = 0; j < vecinos.size(); j++)     // Se crea un arco entre el nodo origen y sus vecinos
        {
            grafo.AsignarArco(i, j, PESO);
        }
        grafo.Print(i);                                 // Se imprime la informacion del nodo (arcos y pesos) por pantalla
    }
}

/*
Algoritmo de exploración en profundidad (DFS) de un grafo desde un nodo origen.
El algoritmo debe devolver un vector de valores booleanos que indique, para todos
los nodos del grafo, si el nodo ha sido visitado en el recorrido (true) o no (false). 
Manera eficiente, método NodosAdyacentes en la clase Grafo
*/
/**
 *  @brief Exploración en profundidad de un grafo.
 *
 *  @param [in]  grafo  Tipo de dato donde estan almacenados los nodos y sus arcos
 *  @param [in]  origen Nodo de comienzo
 */
vector<bool> DFS(Grafo grafo, size_t origen)
{
    vector<bool> visit(grafo.Size(), false); // Almacena si los nodos fueron visitados
    
    DFSAux(grafo, origen, visit);            // Func. que actualiza visitas
    
    return visit;
}

/**
 *  @brief Auxuliar a DFS
 *
 *  @param [in]  grafo      Tipo de dato donde estan almacenados los nodos y sus arcos
 *  @param [in]  escenario  Posicion/ indice del nodo actual
 *  @param [in]  visitado   Vector tipo bool, si el nodo esta visitado = true, sino = false
 */
void DFSAux(Grafo grafo, size_t origen, vector<bool> & visitado)
{
    visitado[origen] = true;
    //vector<size_t> nodosAdy = grafo.NodosAdyacentes(origen);

    for (size_t n = 0; n < grafo.NodosAdyacentes(origen).size(); n++)
        if (grafo.NodosAdyacentes(origen)[n] == false)
            DFSAux(grafo, grafo.NodosAdyacentes(origen)[n], visitado);
}

size_t PrimerLibre(Escenario escenario)
{
    size_t primero;
    bool encontrado = false;
    unsigned int posicionesTot = escenario.alto * escenario.ancho;

    for (unsigned int i = 0; i < posicionesTot && encontrado == false; i++)
    {
        if (escenario.posiciones[i] == true)
        {
            primero = i;
            encontrado = true;
        }
    }
        return primero;
    }