#ifndef __Ejercito_H__
#define __Ejercito_H__

#include "Pantalla.h"
/**
   \file Ejercito.h
   \brief Consiste en un conjunto de enemigos mediante estructuras enlazadas
 */

/**
    \brief TDA Ejercito
 */
typedef struct EjercitoRep * Ejercito;

/**
    \brief Crea el primer objeto de la lista de enemigos
    \return  la estructura enlazada en cuesti�n
*/
Ejercito EjercitoCrea();
/**
    \brief Libera el ejercito de enemigos
    \param e recibe el ejercito de enemigos
*/
void EjercitoLibera (Ejercito e);
/**
    \brief Funci�n que inserta a los enemigos
    \param e Recibe el ejercito en cuesti�n al que se debe insertar el enemigo
    \param i Recibe la imagen con la que se debe dibujar al enemigo
    \param x Recibe la posici�n x (horizontal)
    \param y Recibe la posici�n y (vertical)
    \param w anchura
    \param h altura
    \param vx velocidad horizontal
    \param vy velocidad vertical
*/
void EjercitoInserta(Ejercito e,Imagen i, int x, int y, int w, int h, int vx, int vy);
/**
    \brief M�tdodo que dibuja la el ejercito en la pantalla
    \param Recibe como par�metro el ejercito
*/
void EjercitoDibuja(Ejercito e);
/**
    \brief Mueve los enemigos del ejercito
    \param e recibe el ejercito
*/
void EjercitoMueve(Ejercito e);
/**
    \brief Detecta la colisi�n entre el ejercito y otro objeto
    \return Te  el n�mero de enemigos que han colisionado
    \param  e Recibe el ejercito en cuestion
    \param  x Recibe la posici�n x (horizontal) del otro objeto
    \param y Recibe la posici�n y (vertical) del otro objeto
    \param w Recibe la anchura del otro objeto
    \param h Recibe la altura del otro objeto
*/
int EjercitoColision(Ejercito e, int x, int y, int w, int h);


#endif // __Ejercito_H__
