#include "Galaxia.h"
#include <stdlib.h>
#include "Pantalla.h"
#include "Estrella.h"
#include "Colision.h"

struct GalaxiaRep {
    Estrella * e;
    int n, nmax;
};

Galaxia GalaxiaCrea(int nmax)
{
    Galaxia g = malloc (sizeof(struct GalaxiaRep));
    g -> e = malloc(nmax * sizeof(Estrella));
    g -> nmax = nmax;
    g -> n = 0;
    return g;
}
void GalaxiaLibera(Galaxia g)
{
    for(int i=0; i< g->n ;i++)
    {
        EstrellaLibera(g->e[i]);
    }
    free (g->e);
    free(g);
}
void GalaxiaDibuja(Galaxia g)
{
    for (int i = 0; i < g->n; i++)
    {
        EstrellaDibuja(g->e[i]);
    }
}
void GalaxiaInserta(Galaxia g, Imagen i, int x, int y, int w, int h)
{
    if (g -> n < g -> nmax)
    {
        g->e [g->n]=EstrellaCrea(i,x,y,w,h);
        g->n++;
    }
}

int GalaxiaColision(Galaxia g, int x, int y, int w, int h)
{
    int contador=0;
    int i = 0;
    while (i< g->n)
    {
        if (colision(EstrellaGetX(g->e[i]),EstrellaGetY(g->e[i]),EstrellaGetW(g->e[i]),EstrellaGetH(g->e[i]),x,y,w,h))
        {
            EstrellaLibera (g->e[i]);
            g->e[i] = g-> e[g->n-1];
            g->n--;
            contador=contador+1;
        }
        else i++;
    }
    return contador;
}
