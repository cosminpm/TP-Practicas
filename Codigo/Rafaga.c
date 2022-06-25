
#include <stdlib.h>
#include "Pantalla.h"
#include "Rafaga.h"
#include "Colision.h"
#include "Bullet.h"
#include "Ejercito.h"



struct RafagaRep
{
    Bullet r;
    Rafaga sig;
};


Rafaga RafagaCrea()
{
    Rafaga r = malloc (sizeof(struct RafagaRep));
    r -> sig = NULL;
    return r;
}

void RafagaLibera (Rafaga r)

{
        while ( r->sig != NULL )
    {
        Rafaga borrar = r->sig;
        r->sig = borrar->sig;
        Bullet_Libera(borrar->r);
        free( borrar );
    }
    free( r );
}

void RafagaInserta(Rafaga r,Imagen i, int x, int y, int w, int h, int vx, int vy, double angulo)
{
    Rafaga aux = malloc (sizeof(struct RafagaRep));
    aux->r = BulletCrea(i,x,y,w,h,vx,vy,angulo);
    aux->sig = r->sig;
    r->sig = aux;
}

void RafagaDibuja(Rafaga r)
{
    while (r->sig!=NULL)
    {
        Bullet_Dibuja(r->sig->r);
        r=r->sig;
    }
}


void RafagaMueve(Rafaga r)
{
        while ( r->sig != NULL )
    {
        if (Bullet_Mueve(r->sig->r))
        {
            Rafaga borrar = r->sig;
            r->sig = borrar->sig;
            Bullet_Libera(borrar->r);
            free( borrar );
        }
        else
        {
            r = r->sig; // Avanzar
        }
    }
}


int RafagaColision(Rafaga r, Ejercito e)
{
    int contador=0;
    while ( r->sig != NULL )
    {
        int n = EjercitoColision(e,Bullet_GetX(r->sig->r),Bullet_GetY(r->sig->r),Bullet_GetW(r->sig->r),Bullet_GetH(r->sig->r));
        if (n>0)
        {
            Rafaga borrar = r->sig;
            r->sig = borrar->sig;
            Bullet_Libera(borrar->r);
            free( borrar );
            contador += n;
        }
        else
        {
            r = r->sig; // Avanzar
        }
    }
    return contador;
}



