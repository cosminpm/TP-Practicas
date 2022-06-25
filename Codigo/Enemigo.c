#include <stdlib.h>
#include "Enemigo.h"

struct EnemigoRep
{
    int x,y,w,h,vx,vy;
    Imagen i;
};

Enemigo EnemigoCrea(Imagen i, int x, int y, int w, int h,int vx, int vy)
{
    Enemigo nuevo = malloc(sizeof(struct EnemigoRep));
    nuevo->i=i;
    nuevo->x=x;
    nuevo->y=y;
    nuevo->w=w;
    nuevo->h=h;
    nuevo->vx=vx;
    nuevo->vy=vy;
    return nuevo;
}
void EnemigoLibera(Enemigo e)
{
    free(e);
}

void EnemigoSetX(Enemigo e, int x)
{
    e->x=x;
}
void EnemigoSetY(Enemigo e, int y)
{
    e->y=y;
}



void EnemigoSetV(Enemigo e, int velocidad)
{
    e->vx=velocidad;
    e->vy=velocidad;
}

void EnemigoMueve(Enemigo e)
{
    e->x += e->vx ;
    e->y += e->vy;
    if (e->x<35) {e->x=35;e->vx*=-1;}
    if (e->y<35) {e->y=35;e->vy*=-1;}
    if (e->x>Pantalla_Anchura()-e->w-35) {e->x=Pantalla_Anchura()-e->w-35; e->vx*=-1;}
    if (e->y>Pantalla_Altura()-e->h-35)  {e->y=Pantalla_Altura()-e->h-35; e->vy*=-1;}

}
void EnemigoDibuja(Enemigo e)
{
    return Pantalla_DibujaImagen(e->i,e->x,e->y,e->h,e->w);
}
int EnemigoGetX(Enemigo e)
{
    return e->x;
}
int EnemigoGetY(Enemigo e)
{
    return e->y;
}
int EnemigoGetW(Enemigo e)
{
    return e->w;
}
int EnemigoGetH(Enemigo e)
{
    return e->h;
}
