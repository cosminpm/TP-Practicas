#ifndef __Vida_H__
#define __Vida_H__
#include "Pantalla.h"
#include "Vida.h"

/**
    \file Vida.h
    \brief Vidas que nos indicarán cuantas vidas tenemos en cada momento
*/
/**
    \brief TDA Vida
*/
typedef struct VidaRep * Vida;
/**
    \brief Funcion que crea las vidas
    \param i la imagen con la que cargamos las vidas
    \param x la posicion horizontal
    \param y la posicion vertical
    \param w la anchura
    \param h la altura
    \return las vidas
*/
Vida VidaCrea(Imagen i, int x, int y, int w, int h);
/**
    \brief Libera las vidas
    \param v las vidas
*/
void VidaLibera(Vida v);
/**
    \brief Dibuja las vidas
    \param v la vida
*/
void VidaDibuja(Vida v);
#endif // __Vida_H__

