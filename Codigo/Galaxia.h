#ifndef Galaxia_H
#define Galaxia_H
#include "Pantalla.h"
/**
    \file Galaxia.h
    \brief Conjunto de estrellas (monedas)
*/

/**
    \brief TDA Galaxia
*/
typedef struct GalaxiaRep * Galaxia;

/**
    \brief Crea el primer objeto de la galaxia
    \param nmax como el número máximo de monedas que puede haber por pantalla
    \return  la galaxia
*/
Galaxia GalaxiaCrea(int nmax);
/**
    \brief Libera el conjunto de monedas
    \param g la galaxia
*/
void GalaxiaLibera(Galaxia g);
/**
    \brief Dibuja la galaxia
    \param g la galaxia
*/
void GalaxiaDibuja(Galaxia g);
/**
    \brief Inserta monedas de la galaxia
    \param g la galaxia en cuestion
    \param i la imagen con la que vamos a cargas las monedas
    \param x la posicion horizontal
    \param y la posicion vertical
    \param w la anchura de las monedas
    \param h la altura de las monedas
*/
void GalaxiaInserta(Galaxia g, Imagen i, int x, int y, int w, int h);
/**
    \brief Va suprimiendo elementos de la galaxia, monedas
    \param g la galaxia
    \param x la posicion horizontal
    \param y la posicion vertical
    \param w la anchura de la imagen
    \param h la altura de la imagen
*/
void GalaxiaSuprime (Galaxia g, int x, int y, int w, int h);
/**
    \brief Detecta si se ha producido una colisión de la nave con un objeto
    \param x la posicion x del segundo objeto
    \param y la posicion y del segundo objeto
    \param w la anchura del segundo objeto
    \param h la altura del segundo objeto
    \return lleva la cuenta de las monedas que se han producido choque
*/

int GalaxiaColision(Galaxia g, int x, int y, int w, int h);

#endif
