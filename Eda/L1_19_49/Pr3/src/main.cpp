#include <iostream>
#include <queue>
#include <vector>
#include <stdexcept>
#include <fstream>

#include "cola.h"

using namespace std;

void Conectar(vector<string>&, Cola<string>&, string, ofstream&);
void Desconectar(vector<string>&, Cola<string>&, ofstream&);

int main()
{
    string usuario;
    ifstream f_in;
    ofstream f_out;
    Cola<string> cEspera;
    vector<string> vActivo;


    f_in.open("data/datos.txt");
    f_out.open("data/salida.txt");
    if (!f_in || !f_out) cout << "Error al abrir el fichero\n";
    else
    {
        while(getline(f_in, usuario))
        {
            if (usuario[0] == 'C')
                Conectar(vActivo, cEspera, usuario, f_out);
            else
                Desconectar(vActivo, cEspera, f_out);
        }
        f_in.close();
        f_out.close();
    }

    return 0;
}

// Verificar si la cola de activos esta llena
// Si no esta llena agregar al usuario a la cola activos
// Si esta llena agregar al usuario en la cola espera
/**
 * @brief Añade un usuario al vector de jugadores activos, 
 * sino los añade a la cola de espera
 * 
 * @param activo 
 * @param espera 
 * @param usuario 
 */

void Conectar(vector<string>& activo, Cola<string>& espera, string usuario, ofstream& out)
{  
    /* Si hay plazas disponibles en el vector de jugadores de la partida, se debe añadir
    el nuevo usuario (string) a este vector. Además,se debe mostrar por pantalla
    el mensaje “<usuario>: Jugador activo”, donde “<usuario> es el nombre
    de usuario leído del archivo.*/
    if (activo.size() < 10)
    {
        usuario.erase(0, 2);
        activo.push_back(usuario);
        cout << usuario << ": Jugador activo. " << endl;
        out << usuario << ": Jugador activo. " << endl;
    }
    /*Si no hay plaza en la partida, se debe enviar al usuario a la sala de espera 
    (añadir a la cola). Si esta operacion se puede realizar correctamente (no hay 
    excepcion), se mostrara por pantalla el mensaje “<usuario>: Espera turno 
    en la sala de espera”. Si hubiera algun error el mensaje sería “<usuario>: 
    Imposible conectar, intentelo mas tarde”. En ningun caso, el programa 
    finalizara porque se lance una excepción desde Cola*/
    else
    {	
        try
	    {
            usuario.erase(0, 2);
            espera.Encolar(usuario);
            cout << usuario << ": Espera turno en la sala de espera." << endl;
            out << usuario << ": Espera turno en la sala de espera." << endl;
	    }
	    catch(exception& e)
	    {
		    cerr << e.what() << '\n';
		    throw(runtime_error(usuario + ": Imposible conectar, intentelo mas tarde"));
	    }
    }
}
 /**
  * @brief Desconecta a un usuario del vector de jugadores activos
  * 
  * @param [in / out] activo 
  * @param [in / out] espera 
  */


void Desconectar(vector<string>& activo, Cola<string>& espera, ofstream& out)
{
    string usuario;
    /*Si la linea leida indica una desconexion, entonces se debe eliminar de la partida al 
    primer jugador del vector de jugadores activos, pero antes mostrara el mensaje “<usuario>: Ha sido desconectado del juego”, 
    donde <usuario> es el nombre de usuario eliminado. Además, se debe llevar al primer usuario de la sala de espera al 
    vector de jugadores activos en la partida (eliminar de la cola y añadir al vector). Si es 
    posible realizar este proceso e incorporar un jugador a la partida entonces, se 
    mostrará el mensaje "<usuario>: Pasa a ser Jugador activo". 
    */
    cout << activo.front() << ": Ha sido desconectado del juego." << endl;
    out << activo.front() << ": Ha sido desconectado del juego." << endl;
    activo.erase(activo.begin());

    if(!espera.ColaVacia())
    {
        usuario = espera.PrimeroCola();
        cout << usuario << ": Pasa a ser Jugador activo." << endl;
        out << usuario << ": Pasa a ser Jugador activo." << endl;
        espera.Desencolar();
        activo.push_back(usuario);
    }
    /*En caso contrario, 
    si al extraer un usuario de la sala de espera se generará un error (excepción) entonces, 
    se debería mostrar el mensaje "Hay espacio disponible en la partida". En 
    ningún caso, el programa finalizará porque se lance una excepción desde Cola.*/
    else
    {
        activo.erase(activo.begin());
        cout << "Hay espacio disponible en la partida." << endl;
        out << "Hay espacio disponible en la partida." << endl;
    }


}