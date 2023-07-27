/**
 * @file NPC.h
 * 
 * @brief Practica 6 EDA-GIM: Interfaz de la clase NPC
 *  
 * @version 1.0
 * @author Jesus Albert
 * @date 21-11-2022
 * 
 */

#ifndef _PERSONAJE_NPC_H_
#define _PERSONAJE_NPC_H_

#include <queue>    //priority_queue
#include <utility>  //pair
#include <string>
#include <vector>
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
        /// @brief Cargar informacion de los personajes humanos que atacan al NPC
        void CargarAtacantes();
        /// @brief Actualizar la informacion de los personajes atacantes en un nuevo ciclo de juego
        void ActualizarCiclo();
        /// @brief Ejecutar la estrategia de ataque
        /// @return nombre del personaje atacado
        std::string Atacar();
    private:
        /// @brief nombre del personaje NPC
        std::string nombre;
        /// @brief nivel de vida del personaje NPC, <1 = sin vida
        float vida; 
        /// @brief Los personajes que atacan al NPC
        std::vector<Personaje> atacantes;
        /// @brief tipo de los datos almacenados en el monticulo (aggro,nombre)
        typedef std::pair<int,std::string> ParDato;
        /// @brief monticulo de maximos para seleccionar el objetivo del ataque en cada ciclo del juego
        std::priority_queue<ParDato> monticulo;
};

#endif