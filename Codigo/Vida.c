#include <stdlib.h>
#include "Vida.h"


struct VidaRep
{
    int x,y,w,h;
    Imagen i;

};

Vida VidaCrea(Imagen i, int x, int y, int w, int h)
{
    Vida nuevo = malloc(sizeof(struct VidaRep));
    nuevo->i=i;
    nuevo->x=x;
    nuevo->y=y;
    nuevo->w=w;
    nuevo->h=h;
    return nuevo;
}



void VidaLibera(Vida v)
{
    free(v);
}

void VidaDibuja(Vida v)
{
    return Pantalla_DibujaImagen(v->i,v->x,v->y,v->h,v->w);
}


