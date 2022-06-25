#ifndef __Rafaga_H__
#define __Rafaga_H__
#include "Pantalla.h"
#include "Ejercito.h"
/**
    \file Rafaga.h
    \brief Conjunto de balas
*/

/**
    \brief TDA Rafaga
*/
typedef struct RafagaRep * Rafaga;
/**
    \brief Crea la Ráfaga
    \return  la rafaga que hemos creado
*/
Rafaga RafagaCrea();
/**
    \brief Libera la rafaga
    \param r la rafaga
*/
void RafagaLibera (Rafaga r);
/**
    \brief Inserta balas en la rafaga
    \param r la rafaga
    \param i la imagen de las balas
    \param x la posicion horizontal
    \param y la posicion vertical
    \param w la anchura
    \param h la altura
    \param vx la velocidad horizontal
    \param vy la velocidad vertical
    \param angulo el angulo de la bala
*/
void RafagaInserta(Rafaga r,Imagen i, int x, int y, int w, int h, int vx, int vy, double angulo);
/**
    \brief Dibuja la rafaga
    \param r la rafaga
*/
void RafagaDibuja(Rafaga r);
/**
    \brief Mueve la rafaga
    \param r la ragaga
*/
void RafagaMueve(Rafaga r);

/**
    \brief Funcion de colision entre las balas y el ejercito
    \param r la rafaga
    \param e el ejercito
    \return el numero de enemigos que hemos matado
*/

int RafagaColision(Rafaga r, Ejercito e);


#endif //__Ráfaga_H__
