#ifndef __Estrella_H__
#define __Estrella_H__
#include "Pantalla.h"
#include "Estrella.h"
/**
   \file Estrella.h
   \brief Consiste en una estrella que recogerá la nave para conseguir puntos
 */
/**
    \brief TDA Estrella
*/
typedef struct EstrellaRep * Estrella;
/**
    \brief  Inicializa la estrella que vamos a usar
    \param  i Imagen de la estrella
    \param x posicion horizontal
    \param y posicion verrtical
    \param w anchura
    \param h altura
    \return  el la estrella creada
*/
Estrella EstrellaCrea(Imagen i, int x, int y, int w, int h);
/**
    \brief Libera la estrella
    \param e recibe la estrella
*/
void EstrellaLibera(Estrella e);
/**
    \brief Dibuja la estrella
    \param e recibe la estrella
*/
void EstrellaDibuja(Estrella e);
/**
    \brief Funcion Get que  la posición x de la estrella
    \param e recibe la estrella
    \return  la x de la estrella, posicion horizontal
*/
int EstrellaGetX(Estrella e);
/**
    \brief Funcion Get que  la posición y de la estrella
    \param e recibe la estrella
    \return  la y de la estrella, posicion vertical
*/
int EstrellaGetY(Estrella e);
/**
    \brief  Funcion Get que  la anchura de la estrella
    \param  e la estrella
    \return la anchura de la estrella
*/
int EstrellaGetW(Estrella e);
/**
    \brief  Funcion Get que  la altura de la estrella
    \param  e la estrella
    \return la altura de la estrella
*/
int EstrellaGetH(Estrella e);

#endif // __Estrella_H__

