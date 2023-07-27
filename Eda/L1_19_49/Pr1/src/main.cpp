/**
 * @file main.cpp
 * @brief Programa de Test de la Practica 1 de EDA (GIM).
 * 
 * Utilizacion de Punto2d y Triangulo
 *
 * @author Jesus Albert
 * @date 07/09/2022
 * @version 1.0
 */

#define _USE_MATH_DEFINES
#include "punto2d.h"
#include "triangulo.h"
#include "math.h"
#include <iostream>

void Test1();
void Test2();
void Test3();
void Test4();

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}

/**
 * @brief Manipulacion de puntos
 * 
 */
void Test1()
{
    /* Crear 3 puntos en diferentes localizaciones */
    Punto2d p1(1,0), p2(3,5), p3;

    cout << "**************" << endl;
    cout << "*   Test 1   *" << endl;
    cout << "**************" << endl;

    /* Mostrar los puntos en pantalla 
    Resultado correcto:
        (1,0)
        (3,5)
        (0,0)
    */
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    cout << "p3 = " << p3 << endl;
    cout << "-------------" << endl;

    /* Modificar el punto p1 con Set */
    p1.Set(5,25);
    /* Rotar el punto p2 un angulo pi/2 (90º) */
    p2.Rotar(M_PI/2);
    /* Desplazar el punto p3 */
    p3.Desplazar(-1,7);

    /* Mostrar los puntos en pantalla 
    Resultado correcto:
        (5,25)
        (-5,3)
        (-1,7)
    */
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    cout << "p3 = " << p3 << endl;
    cout << "-------------" << endl;
    cout << "Fin Test 1" << endl;
}

/**
 * @brief Manipulacion simple de triangulos, solo Set
 * 
 */
void Test2()
{
    /* Crear 2 triangulos con valores por defecto */
    Triangulo t, s;

    cout << "**************" << endl;
    cout << "*   Test 2   *" << endl;
    cout << "**************" << endl;

    /* Mostrar los triangulos (vertices) por pantalla 
    Resultado correcto:
        (0,0); (2,0); (1,2)
        (0,0); (2,0); (1,2))
    */
    cout << "t = " << t << endl;
    cout << "s = " << s << endl;

    /* Comprueba si los dos triangulos son iguales */
    if ( t == s )
        cout << "t y s son IGUALES" << endl;
    else
        cout << "ERROR en el test" << endl;
    cout << "-------------" << endl;

    /* Modificar los vertices del triangulo t 
    con valores correctos */
    t.SetV0( Punto2d(10,10) );
    t.SetV1( Punto2d(20,20) );
    t.SetV2( Punto2d(30,30) );

    /* Mostrar el triangulo t por pantalla 
    Resultado correcto:
        (10,10) ; (20,20) ; (30,30)
    */
    cout << "t = " << t << endl;

    /* Comprueba si los dos triangulos son iguales */
    if ( t == s )
        cout << "ERROR en el test" << endl;
    else
        cout << "t y s son DIFERENTES" << endl;
    cout << "-------------" << endl;

    /* Modificar los vertices del triangulo s 
    con valores INcorrectos */
    s.SetV0( Punto2d(5,7) );
    s.SetV1( Punto2d(20,30) );
    s.SetV2( Punto2d(-10,15) ); //Fuera del escenario

    /* Mostrar el triangulo s por pantalla 
    Resultado correcto:
        No se debe llegar a ejecutar porque ha debido
        saltar un aserto incumplido
    */
    cout << "s = " << s << endl;
    cout << "-------------" << endl;
    cout << "Fin Test 2" << endl;
}

/**
 * @brief Desplazar triangulos
 * 
 */
void Test3()
{
    /* Crear 2 triangulos con valores por defecto */
    Triangulo t, s;

    cout << "**************" << endl;
    cout << "*   Test 3   *" << endl;
    cout << "**************" << endl;

    /* Mostrar los triangulos (vertices) por pantalla 
    Resultado correcto:
        (0,0); (2,0); (1,2)
        (0,0); (2,0); (1,2)
    */
    cout << "t = " << t << endl;
    cout << "s = " << s << endl;
    cout << "-------------" << endl;

    /* Desplazar el triangulo t +10, +20 */
    t.Desplazar(10,20);
    /* Desplazar el triangulo s +500, +300 */
    s.Desplazar(500,300);
    /* Mostrar los triangulos (vertices) por pantalla 
    Resultado correcto:
        (10,20) ; (12,20) ; (11,22) 
        (500,300) ; (502,300) ; (501,302) 
    */
    cout << "t = " << t << endl;
    cout << "s = " << s << endl;
    cout << "-------------" << endl;

    /* Desplazar el triangulo t -100, -100 */
    t.Desplazar(-100,-100);

    /* Mostrar el triangulo t por pantalla 
    Resultado correcto:
        No se debe llegar a ejecutar porque ha debido
        saltar un aserto incumplido en Desplazar
    */
    cout << "t = " << t << endl;
    cout << "-------------" << endl;
    cout << "Fin Test 3" << endl;
}

/**
 * @brief Rotacion de triangulos
 * 
 */
void Test4()
{
    /* Crear un triangulo con valores por defecto */
    Triangulo t;

    cout << "**************" << endl;
    cout << "*   Test 4   *" << endl;
    cout << "**************" << endl;

    /* Modificar los vertices del triangulo t  */
    t.SetV0( Punto2d(100,110) );
    t.SetV1( Punto2d(200,220) );
    t.SetV2( Punto2d(300,330) );
    /* Mostrar el triangulo por pantalla 
    Resultado correcto:
        (100,110) ; (200,220) ; (300,330)
    */
    cout << "t = " << t << endl;
    cout << "-------------" << endl;

    /* Rotar el triangulo pi/6 (30º) radianes */
    t.Rotar(M_PI/6);

    /* Mostrar el triangulo por pantalla 
    Resultado correcto:
        (31.6025,145.263) ; (63.2051,290.526) ; (94.8076,435.788)
    */
    cout << "t = " << t << endl;
    cout << "-------------" << endl;

    /* Deshacer la rotacion anterior */
    t.Rotar(-M_PI/6);

    /* Mostrar el triangulo por pantalla 
    Resultado correcto:
        (100,110) ; (200,220) ; (300,330)
    */
    cout << "t = " << t << endl;
    cout << "-------------" << endl;

    /* Rotar el triangulo pi/2 (90º) radianes */
    t.Rotar(M_PI/2);

    /* Mostrar el triangulo por pantalla 
    Resultado correcto:
        No se debe llegar a ejecutar porque ha debido
        saltar un aserto incumplido en Rotar
    */
    cout << "t = " << t << endl;
    cout << "-------------" << endl;
    cout << "Fin Test 4" << endl;
}