/**
 * @file NPC.h
 * 
 * @brief Practica 7 EDA-GIM: Interfaz de la clase NPC revisada incluyendo memoria de personajes
 *  
 * @version 1.0
 * @author Jesus Albert
 * @date 02-12-2022
 * 
 */

#ifndef _PERSONAJE_NPC_H_
#define _PERSONAJE_NPC_H_

#include <queue>    //priority_queue
#include <utility>  //pair
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "personaje.h"

/// @brief Clase que representa a un personaje NPC (Non Player Character)
class NPC
{
    public:
        ///Constructor por defecto
        NPC();
        /// @brief Constructor con nombre y nivel inicial de vida
        /// @param  nombre
        /// @param  nivel de vida
        NPC(std::string,float);
        /// @brief Establecer el nombre del NPC
        /// @param  nombre
        void SetNombre(std::string);
        /// @brief Establecer el nivel de vida del NPC
        /// @param  nivel de vida
        void SetVida(float);
        /// @brief Consultar el nombre del NPC
        /// @return nombre
        std::string GetNombre();
        /// @brief Consultar el nivel de vida del NPC
        /// @return nivel de vida
        float GetVida();
        /// @brief Cargar la memoria del NPC con todos los personales conocidos
        void CargarMemoria();
        /// @brief Cargar informacion de los personajes humanos que atacan al NPC
        void CargarAtacantes();
        /// @brief Actualizar la informacion de los personajes atacantes en un nuevo ciclo de juego
        void ActualizarCiclo();
        /// @brief Ejecutar la estrategia de ataque
        /// @return nombre del personaje atacado
        std::string Atacar();
        /// @brief criterio para asignar prioridades en el monticulo para los personajes atacantes
        /// @return La prioridad
        float Prioridad(int,int,int); 
    private:
        /// @brief nombre del personaje NPC
        std::string nombre;
        /// @brief nivel de vida del personaje NPC, <1 = sin vida
        float vida; 
        /// @brief tipo de los datos vinculados con cada clave en la tabla de memoria
        struct Resultados
        {
            int nvictorias; //Numero de victorias sobre el personaje
            int nderrotas; //Numero de derrotas sobre el personaje
        };
        /// @brief Informacion sobre personajes del juego conocidos por el NPC (indexada por nombre del personaje)
        std::unordered_map<std::string,Resultados> memoria;
        /// @brief Informacion de los personajes que atacan (ahora) al NPC
        std::unordered_map<std::string,Personaje> atacantes;
        /// @brief tipo de los datos almacenados en el monticulo (prioridad,nombre)
        typedef std::pair<int,std::string> ParDato;
        /// @brief monticulo de maximos para seleccionar el objetivo del ataque en cada ciclo del juego
        std::priority_queue<ParDato> monticulo;
};

/* 
 * Actualizaciones del codigo para esta practica.
 * 
 * Funcion CargarMemoria(). Guarda los datos de los NPC usando Resultados(struct).
 * Nuevo mapa desordenado para guardar los datos de los personajes conocidos por el NPC
 * Nuevo mapa desordenado para guardar los datos de los personajes que atacan al NPC.
 */

#endif