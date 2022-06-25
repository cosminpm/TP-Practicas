#ifndef __Bullet_H__
#define __Bullet_H__
#include "Pantalla.h"
/**
   \file Bullet.h
   \brief Consiste en una bala que es disparada por la nave en la dirección en la que esté la nave.
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
    \param angulo de la bala que rotará según la rotación de la nave
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
    \brief Métdodo que dibuja la bala en la pantalla
    \param Recibe como parámetro la bala
*/
void Bullet_Dibuja(Bullet b);

/**
    \brief Método get que  la posición X (posicion horizontal) de la bala
    \param Recíbe como parámetro en cuestión la bala
    \return  la X de la bala
*/

int Bullet_GetX(Bullet b);
/**
    \brief Método get que  la posición Y (posicion vertical) de la bala
    \param Recíbe como parámetro en cuestión la bala
    \return la X de la bala
*/

int Bullet_GetY(Bullet b);
/**
    \brief Método get que  la posición H (altura de bala)
    \param Recíbe como parámetro en cuestión la bala
    \return  la H de la bala
*/
int Bullet_GetH(Bullet b);
/**
    \brief Método get que  la posición W (anchura de la bala)
    \param Recíbe como parámetro en cuestión la bala
    \return  la W de la bala
*/

int Bullet_GetW(Bullet b);

#endif //__Bullet_H__
