#ifndef __Personaje_H__
#define __Personaje_H__

#include "Pantalla.h"
/**
    \file Personaje.h
    \brief Personaje que vamos a usar para movernos por el mapa y jugar con el
*/
/**
    \brief TDA Personaje
*/
typedef struct PersonajeRep * Personaje;
/**
    \brief Crea el personaje que vamos a usar
    \param i Imagen con la que vamos a jugar con nuestro personaje
    \param x coordenada x del personaje
    \param y coordenada y del personaje
    \param w anchura del personaje
    \param h altura del personaje
    \param angulo angulo del personaje, para que podamos girarlo
    \return te  el personaje creado
*/
Personaje PersonajeCrea(Imagen i, int x, int y, int w, int h,double angulo);
/**
    \brief Libera el personaje
    \param p el personaje
*/
void PersonajeLibera(Personaje p);
/**
    \brief Mueve el personaje en cuestion
    \param p el personaje
    \param vx la velocidad horizontal
    \param vy la velocidad vertical
*/
void PersonajeMueve(Personaje p,int vx, int vy);
/**
    \brief Dibuja el personaje en cuestion
    \param p el personaje
*/
void PersonajeDibuja(Personaje p);
/**
    \brief Funcion set que modifica la posicion x del personaje
    \param p el personaje
    \param x la coordeanda x donde vamos a ponerlo
*/
void PersonajeSetX(Personaje p, int x);
/**
    \brief Funcion set que modifica la posicion y del personaje
    \param p el personaje
    \param y la coordenada y donde vamos a ponerlo
*/
void PersonajeSetY(Personaje p, int y);
/**
    \brief Funcion set que modifica la velocidad del personaje
    \param velocidad que le vamos a dar al personaje
*/
void PersonajeSetV(Personaje p, int velocidad);
/**
    \brief Funcion Get que obtiene la posicion x del personaje
    \param p el personaje
    \return la posicion x del personaje
*/
int PersonajeGetX(Personaje p);
/**
    \brief Funcion Get que obtiene la posicion y del personaje
    \param p el personaje
    \return la posicion y del personaje
*/
int PersonajeGetY(Personaje p);
/**
    \brief Funcion Get que obtiene la anchura del personaje
    \param p el personaje
    \return  la anchura del personaje
*/
int PersonajeGetW(Personaje p);
/**
    \brief Funcion Get que obtiene la altura del personaje
    \param p el personaje
    \return  la altura del personaje
*/
int PersonajeGetH(Personaje p);

/**
    \brief Funcion Get que obtiene el angulo del personaje
    \param p el personaje
    \return devulve en angulo
*/
double PersonajeGetAngulo(Personaje p);
/**
    \brief Funcion hace que el personaje rote según un angulo
    \param p el personaje
    \param angulo el angulo que va a tener el personaje
*/

void PersonajeRota(Personaje p,double angulo);

#endif // __Personaje_H__
