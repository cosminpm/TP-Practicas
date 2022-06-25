#include <stdlib.h>
#include <math.h>
#include "Pantalla.h"

#include "Bullet.h"

struct BulletRep
{
    Imagen i;
    int x, y, w, h, vx, vy;
    double angulo;
};

Bullet BulletCrea (Imagen i, int x, int y, int w, int h, int vx, int vy, double angulo)
{
    Bullet nuevo=malloc(sizeof(struct BulletRep));
    nuevo ->i=i;
    nuevo ->x=x;
    nuevo ->y=y;
    nuevo ->w=w;
    nuevo ->h=h;
    nuevo->vx = vx*sin(angulo*2*3.1416/360);
    nuevo->vy = -vy*cos(angulo*2*3.1416/360);
    nuevo ->angulo=angulo;
    return nuevo;
}

void Bullet_Dibuja (Bullet b)
{
    return Pantalla_DibujaImagenTransformada(b->i,b->x,b->y,b->w,b->h,b->angulo,SDL_FLIP_NONE);
}

void Bullet_Libera(Bullet b)
{
    free(b);
}


int Bullet_Mueve (Bullet b)
{
    b->x += b->vx;
    b->y += b->vy;
    return ( (b->x<30) || (b->y<35) || (b->x>Pantalla_Anchura()-b->w-35) || (b->y>Pantalla_Altura()-b->h-35) );
}
int Bullet_GetX(Bullet b)
{
    return b->x;
}
int Bullet_GetY(Bullet b)
{
    return b->y;
}
int Bullet_GetW(Bullet b)
{
    return b->w;
}
int Bullet_GetH(Bullet b)
{
    return b->h;
}

