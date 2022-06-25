#ifndef __Enemigo_H__
#define __Enemigo_H__
#include "Pantalla.h"

/**
   \file Enemigo.h
   \brief Consiste en un enemigo que intentará matar el personaje
 */

 /**
    \brief TDA Enemigo
 */
typedef struct EnemigoRep * Enemigo;
/**
    \brief  Inicializa el enemigo que con el que vamos a usar
    \param  i Imagen del enemigo
    \param x posicion horizontal del enemigo
    \param y posicion verrtical del enemigo
    \param w anchura del enemigo
    \param h altura del enemigo
    \param vx velocidad horizontal del enemigo
    \param vy velocidad verticsl del enemigo
    \return  el enemigo creado
*/

Enemigo EnemigoCrea(Imagen i, int x, int y, int w, int h, int vx, int vy);
/**
    \brief Libera el enemigo
    \param e recibe el enemigo
*/
void EnemigoLibera(Enemigo e);
/**
    \brief funcion para devolver el enemigo
    \param e recibe el enemigo en cuestion
*/
void EnemigoMueve(Enemigo e);
/**
    \brief Dibuja al enemigo en cuestion
    \param e recibe el enemigo
*/
void EnemigoDibuja(Enemigo e);
/**
    \brief Función Set que regula la posicion horizontal del enemigo
    \param e recibe el enemigo
    \param x donde se querrá poner al enemigo en la coordenada x
*/
void EnemigoSetX(Enemigo e,int x);
/**
    \brief Función Set que regula la posicion vertical del enemigo
    \param e recibe el enemigo
    \param y donde se querrá poner al enemigo en la coordenada y
*/
void EnemigoSetY(Enemigo e,int y);

/**
    \brief Función Set que regula la velocidad del enemigo
    \param e recibe el enemigo
    \param v donde se indicará la velocidad del enemigo
*/
void EnemigoSetV(Enemigo e,int velocidad);
/**
    \brief Función Get que  la posición horizontal actual del enemigo
    \param e recibe el enemigo
    \return  la posicion x del enemigo
*/
int EnemigoGetX(Enemigo e);
/**
    \brief Función Get que  la posición vertical actual del enemigo
    \param e recibe el enemigo
    \return  la posicion y del enemigo
*/
int EnemigoGetY(Enemigo e);
/**
    \brief Función Get que  la anchura del enemigo
    \param e recibe el enemigo
    \return  la anchura
*/
int EnemigoGetW(Enemigo e);
/**
    \brief Función Get que  la altura del enemigo
    \param e recibe el enemigo
    \return  la altura
*/
int EnemigoGetH(Enemigo e);



#endif // __Enemigo_H__
