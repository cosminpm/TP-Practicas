#include "Ejercito.h"
#include <stdlib.h>
#include "Pantalla.h"
#include "Enemigo.h"
#include "Colision.h"


struct EjercitoRep
{
    Enemigo e;
    Ejercito sig;
};

Ejercito EjercitoCrea()
{
    Ejercito e = malloc (sizeof(struct EjercitoRep));
    e -> sig = NULL;
    return e;
}
void EjercitoLibera(Ejercito e)
{
    while ( e->sig != NULL )
    {
        Ejercito borrar = e->sig;
        e->sig = borrar->sig;
        EnemigoLibera(borrar->e);
        free( borrar );
    }
    free( e );

}
void EjercitoInserta(Ejercito e, Imagen i, int x, int y, int w, int h, int vx, int vy)
{
    Ejercito aux = malloc (sizeof(struct EjercitoRep));
    aux->e = EnemigoCrea(i,x,y,w,h,vx,vy);
    aux->sig = e->sig;
    e->sig = aux;
}
void EjercitoDibuja(Ejercito e)
{
    while (e->sig!=NULL)
    {
        EnemigoDibuja(e->sig->e);
        e=e->sig;
    }
}
void EjercitoMueve(Ejercito e)
{
    while (e->sig!=NULL)
    {
        EnemigoMueve(e->sig->e);
        e=e->sig;
    }

}


int EjercitoColision(Ejercito e, int x, int y, int w, int h)
{
    int contador=0;
    while ( e->sig != NULL )
    {
        if (colision(x,y,w,h,EnemigoGetX(e->sig->e),EnemigoGetY(e->sig->e),EnemigoGetW(e->sig->e),EnemigoGetH(e->sig->e)))
        {
            Ejercito borrar = e->sig;
            e->sig = borrar->sig;
            EnemigoLibera(borrar->e);
            free( borrar );
            contador++;
        }
        else
        {
            e = e->sig; // Avanzar
        }
    }
    return contador;
}
