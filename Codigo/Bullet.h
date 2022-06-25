#ifndef __Bullet_H__
#define __Bullet_H__
#include "Pantalla.h"
/**
   \file Bullet.h
   \brief Consiste en una bala que es disparada por la nave en la direcci�n en la que est� la nave.
 */

/**
    \brief TDA Bullet
 */
typedef struct BulletRep * Bullet;
/**
    \brief Inicializa la bala, que vamos a usar para disparar a los enemigos.
    \param i cargamos la imagen de la bala que vamos a usar
    \param x posicion de la bala en la anchura de la pantalla
    \param y posicion de la bala en la altura de la pantalla
    \param w anchura de la bala
    \param h altura de la bala
    \param vx velocidad horizontal de la bala
    \param vy velocidad vertical de la bala
    \param angulo de la bala que rotar� seg�n la rotaci�n de la nave
    \return la bala
*/
Bullet BulletCrea (Imagen i, int x, int y, int w, int h, int vx, int vy, double angulo);

/**
    \brief Libera la bala
    \param b recibe la bala
*/
void Bullet_Libera(Bullet b);
/**
    \brief Mueve la bala
    \param b recibe la bala
    \return  verdadero o falso para saber si se ha slaido de la pantalla o no.
*/
int Bullet_Mueve(Bullet b);

/**
    \brief M�tdodo que dibuja la bala en la pantalla
    \param Recibe como par�metro la bala
*/
void Bullet_Dibuja(Bullet b);

/**
    \brief M�todo get que  la posici�n X (posicion horizontal) de la bala
    \param Rec�be como par�metro en cuesti�n la bala
    \return  la X de la bala
*/

int Bullet_GetX(Bullet b);
/**
    \brief M�todo get que  la posici�n Y (posicion vertical) de la bala
    \param Rec�be como par�metro en cuesti�n la bala
    \return la X de la bala
*/

int Bullet_GetY(Bullet b);
/**
    \brief M�todo get que  la posici�n H (altura de bala)
    \param Rec�be como par�metro en cuesti�n la bala
    \return  la H de la bala
*/
int Bullet_GetH(Bullet b);
/**
    \brief M�todo get que  la posici�n W (anchura de la bala)
    \param Rec�be como par�metro en cuesti�n la bala
    \return  la W de la bala
*/

int Bullet_GetW(Bullet b);

#endif //__Bullet_H__
