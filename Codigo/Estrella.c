
#include <stdlib.h>
#include "Estrella.h"


struct EstrellaRep
{
    int x,y,w,h;
    Imagen i;
};

Estrella EstrellaCrea(Imagen i, int x, int y, int w, int h)
{
    Estrella nuevo = malloc(sizeof(struct EstrellaRep));
    nuevo->i=i;
    nuevo->x=x;
    nuevo->y=y;
    nuevo->w=w;
    nuevo->h=h;
    return nuevo;
}
void EstrellaLibera(Estrella e)
{
    free(e);
}

void EstrellaDibuja(Estrella e)
{
    return Pantalla_DibujaImagen(e->i,e->x,e->y,e->h,e->w);
}
int EstrellaGetX(Estrella e)
{
    return e->x;
}
int EstrellaGetY(Estrella e)
{
    return e->y;
}
int EstrellaGetW(Estrella e)
{
    return e->w;
}
int EstrellaGetH(Estrella e)
{
    return e->h;
}
