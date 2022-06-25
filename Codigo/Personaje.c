#include <stdlib.h>
#include "Personaje.h"


struct PersonajeRep
{
    int x,y,w,h;
    double angulo;
    Imagen i;
};


Personaje PersonajeCrea(Imagen i, int x, int y, int w, int h,double angulo)
{
    Personaje nuevo = malloc(sizeof(struct PersonajeRep));
    nuevo->i=i;
    nuevo->x=x;
    nuevo->y=y;
    nuevo->w=w;
    nuevo->h=h;
    nuevo->angulo=angulo;
    return nuevo;
}

void PersonajeSetX(Personaje p, int x)
{
    p->x=x;
}
void PersonajeSetY(Personaje p, int y)
{
    p->y=y;
}
void PersonajeRota(Personaje p, double angulo)
{

    p->angulo=(angulo);

}

void PersonajeLibera(Personaje p)
{
    free(p);
}
void PersonajeMueve(Personaje p,int vx, int vy)
{
    p->x += vx;
    p->y += vy;
    if (p->x<30) p->x=30;
    if (p->y<35) p->y=35;
    if (p->x>Pantalla_Anchura()-p->w-35) p->x=Pantalla_Anchura()-p->w-35;
    if (p->y>Pantalla_Altura()-p->h-35)  p->y=Pantalla_Altura()-p->h-35;

}

void PersonajeSetV(Personaje p, int velocidad)
{
    p->x=velocidad;
    p->y=velocidad;
}

void PersonajeDibuja(Personaje p)
{
    return Pantalla_DibujaImagenTransformada(p->i,p->x,p->y,p->h,p->w,p->angulo,SDL_FLIP_NONE);
}
int PersonajeGetX(Personaje p)
{
    return p->x;
}
int PersonajeGetY(Personaje p)
{
    return p->y;
}
int PersonajeGetW(Personaje p)
{
    return p->w;
}
int PersonajeGetH(Personaje p)
{
    return p->h;
}

double PersonajeGetAngulo(Personaje p)
{
    return p->angulo;
}
