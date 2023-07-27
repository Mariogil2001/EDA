/**
 * @file personaje.h
 * @author Jesus Albert
 * @brief Practica 6 EDA-GIM: Interfaz de la clase Personaje
 * @version 1.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _PERSONAJE_H_
#define _PERSONAJE_H_

#include <vector>
#include <string>
#include <fstream>

/// @brief Clase que representa a un personaje controlado por un jugador humano
class Personaje
{
    public:
        /// @brief Constructor por defecto
        Personaje();
        /// @brief Establecer el nombre
        /// @param  nombre
        void SetNombre(std::string);
        /// @brief Establecer el nivel de aggro
        /// @param  aggro
        void SetAggro(int);
        /// @brief Consultar el nombre
        /// @return nombre
        std::string GetNombre();
        /// @brief Consultar el aggro
        /// @return aggro
        int GetAggro();
        /// @brief Evolucionar al siguiente ciclo cambiando el aggro
        void AvanzarCiclo();
        /// @brief Operador entrada
        /// @param  Flujo de entrada
        /// @param  Personaje leido
        /// @return Flujo de entrada modificado
        friend std::ifstream& operator>> (std::ifstream&, Personaje&);
    private:
        /// @brief nombre del personaje
        std::string nombre;
        /// @brief aggro en el ciclo actual del juego
        int aggro;
        /// @brief ciclo en el que se encuentra el juego
        int ciclo; 
        /// @brief variacion del aggro del personaje en cada ciclo del juego
        std::vector<int> varaggro;
};

#endif