
#ifndef __Colision_H__
#define __Colision_H__

/**
   \file Colision.h
   \brief Consiste en una funci�n para detectar las colisiones entre dos objetos
 */

 /**
    \brief funcion que detecta la colisi�n de la bala
    \return Valor booleano que indica si se ha producido la colisi�n entre los dos objetos
    \param x1 Posici�n horizontal del primer objeto
    \param y1 Posicion vertical del primer objeto
    \param w1 Anchura del primer objeto
    \param h1 Altura del primer objeto
    \param x2 Posici�n horizontal del segundo objeto
    \param y2 Posicion vertical del segundo objeto
    \param w2 Anchura del segundo objeto
    \param h2 Altura del segundo objeto
 */
int colision (int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
#endif
