#include "Pantalla.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Personaje.h"
#include "Enemigo.h"
#include "Colision.h"
#include "Galaxia.h"
#include "Vida.h"
#include "Ejercito.h"
#include "Rafaga.h"
#include <math.h>
#include <unistd.h>

/**
* \mainpage Videojuego Escape Invaders
* \brief Basado en los túpicos juegos clásicos de recreativas de naves. En este se debes destruir a los enemigos "pelotas" que se van moviendo por la pantalla y recoger a las monedas.<br/>
Las teclas de dirección izquierda, derecha, arriba y abajo (tambien se pueden combinar dos telcas para moverse en diagonal) se utilizan para mover al personaje, y la tecla P para disparar. Puede pulsar el botón de ESC para salir.
*/
/**
 \file main.c
 \brief Contiene la declaracion de los elementos y el bucle principal del programa y el uso de funciones.
 */




int main(int argc, char **argv)
{

    int menu=0;
    srand(time(NULL));

    /**<  Generamos la pantalla con 1000 pixels de ancho y 600 de alto */
    Pantalla_Crea("PIicio", 1000,600);
    Imagen fondo = Pantalla_ImagenLee("PInicio.bmp", 0);
    int terminado = 0;

    while (Pantalla_Activa() && !terminado)
    {
        /**<  Generamos el menú*/

        Pantalla_DibujaImagen(fondo,0,0,Pantalla_Anchura(),Pantalla_Altura());
        Pantalla_ColorTrazo(255,255,255,255);
        Pantalla_ColorTrazo(0,85,85,255);
        Pantalla_ColorRelleno(233,233,233,255);
        Pantalla_DibujaRectangulo(425,150,150,50);
        Pantalla_DibujaRectangulo(425,250,150,50);
        Pantalla_DibujaRectangulo(425,350,150,50);
        Pantalla_ColorTrazo(0,0,0,255);
        Pantalla_DibujaTexto("PLAY",485,170);
        Pantalla_DibujaTexto("HELP",485,270);
        Pantalla_DibujaTexto("EXIT",485,370);

        /** Para el uso del ratón */
        double rx=0;
        double ry=0;
        double*prx=&rx;
        double*pry=&ry;
        Pantalla_RatonCoordenadas(prx,pry);
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_7)) printf("%f,%f,",rx,ry);
        if (rx>425 && rx<573 && ry>152 && ry <197 && Pantalla_RatonBotonPulsado(1)) menu = 1, terminado=1;
        if (rx>425 && rx<573 && ry>249 && ry <298 && Pantalla_RatonBotonPulsado(1)) menu = 2, terminado=1;
        if (rx>425 && rx<573 && ry>350 && ry <400 && Pantalla_RatonBotonPulsado(1)) menu = 3, terminado=1;
        Pantalla_Actualiza();
        Pantalla_Espera(40);
    }
    Pantalla_ImagenLibera(fondo);
    terminado=0;

/**<  La pantalla de ayuda la inicializamos */
    if (menu==2)
    {
        fondo=Pantalla_ImagenLee("ayuda.bmp",0);
        while (Pantalla_Activa() && !terminado)
        {
            Pantalla_DibujaImagen(fondo,0,0,Pantalla_Anchura(),Pantalla_Altura());
            if (Pantalla_TeclaPulsada(SDL_SCANCODE_RETURN)) terminado=1,menu=1;
            Pantalla_Actualiza();
            Pantalla_Espera(40);
        }
        Pantalla_ImagenLibera(fondo);
    }
    terminado=0;
    /**<  En el caso de que hayamos seleccionado jugar inicializamos todo el juego */
    if (menu==1)
    {
        fondo=Pantalla_ImagenLee("PJuego1.bmp",0);
        Imagen pi=Pantalla_ImagenLee("nave1.bmp",255);
        Imagen v1=Pantalla_ImagenLee("Vida.bmp",255);
        Imagen ei=Pantalla_ImagenLee("enemigo.bmp",255);
        Imagen si=Pantalla_ImagenLee("moneda.bmp",255);
        Imagen pointsIm=Pantalla_ImagenLee("Points.bmp",255);
        Imagen pause=Pantalla_ImagenLee("pause.bmp",255);
        Imagen bala=Pantalla_ImagenLee("bullet.bmp",255);
        /**<  Se crean los objetos del juego */
        int ph=50;
        int pw=50;
        int px=rand()%(Pantalla_Anchura()-pw-35);
        int py=Pantalla_Altura()-ph-35;
        Personaje p = PersonajeCrea(pi,px,py,pw,ph,0);

        int eh=50;
        int ew=50;
        int ey=0;
        int puntos=0;
        int vx = 7;
        int vy = 7;
        /**<  Para controlar el tiempo*/
        int tiempoInicio = time(NULL);
        /**<  Mas objetos del juego, las vidas */
        Galaxia g= GalaxiaCrea(8);

        int sw=30;
        int sh=30;
        Vida L1=VidaCrea(v1,970,570,25,25);
        Vida L2=VidaCrea(v1,945,570,25,25);
        Vida L3=VidaCrea(v1,920,570,25,25);
        Rafaga r=RafagaCrea(3);

        int vida=3;
        int lvl=1;
        Ejercito E=EjercitoCrea();
        int Enemigos=0;
        int pausa = 0;
        char texto2[100];
        char texto[100];
        int tempararicion=0;

        int t=0;
        int temp=0;
        int invulnerable=0;
        while (Pantalla_Activa() && !terminado)
        {
            Pantalla_DibujaImagen(fondo,0,0,Pantalla_Anchura(),Pantalla_Altura());

            if (Pantalla_TeclaPulsada(SDL_SCANCODE_1)) pausa = 1;

            if (Pantalla_TeclaPulsada(SDL_SCANCODE_2) && pausa==1)
            {
                pausa=0;
            }

            if (Pantalla_TeclaPulsada(SDL_SCANCODE_ESCAPE)) terminado=1;
            if (!pausa)
            {
                puntos +=
                    GalaxiaColision(g,PersonajeGetX(p), PersonajeGetY(p), PersonajeGetW(p), PersonajeGetH(p));

                /**<  Aquí controlamos la rotación del personaje */
                if (Pantalla_TeclaPulsada(SDL_SCANCODE_RIGHT)&&!Pantalla_TeclaPulsada(SDL_SCANCODE_UP)&&!Pantalla_TeclaPulsada(SDL_SCANCODE_DOWN)) PersonajeMueve(p,5,0),PersonajeRota(p,90);
                if (Pantalla_TeclaPulsada(SDL_SCANCODE_LEFT)&&!Pantalla_TeclaPulsada(SDL_SCANCODE_UP)&&!Pantalla_TeclaPulsada(SDL_SCANCODE_DOWN))  PersonajeMueve(p,-5,0),PersonajeRota(p,-90);
                if (Pantalla_TeclaPulsada(SDL_SCANCODE_UP)&&!Pantalla_TeclaPulsada(SDL_SCANCODE_RIGHT)&&!Pantalla_TeclaPulsada(SDL_SCANCODE_LEFT))    PersonajeMueve(p,0,-5),PersonajeRota(p,0);
                if (Pantalla_TeclaPulsada(SDL_SCANCODE_DOWN)&&!Pantalla_TeclaPulsada(SDL_SCANCODE_RIGHT)&&!Pantalla_TeclaPulsada(SDL_SCANCODE_LEFT))  PersonajeMueve(p,0,5),PersonajeRota(p,180);

                if (Pantalla_TeclaPulsada(SDL_SCANCODE_DOWN)&&Pantalla_TeclaPulsada(SDL_SCANCODE_RIGHT)) PersonajeMueve(p,vx/sqrt(2),vy/sqrt(2)),PersonajeRota(p,135);
                if (Pantalla_TeclaPulsada(SDL_SCANCODE_DOWN)&&Pantalla_TeclaPulsada(SDL_SCANCODE_LEFT)) PersonajeMueve(p,-vx/sqrt(2),vy/sqrt(2)),PersonajeRota(p,-135);
                if (Pantalla_TeclaPulsada(SDL_SCANCODE_UP)&&Pantalla_TeclaPulsada(SDL_SCANCODE_LEFT)) PersonajeMueve(p,-vx/sqrt(2),-vy/sqrt(2)),PersonajeRota(p,-45);
                if (Pantalla_TeclaPulsada(SDL_SCANCODE_UP)&&Pantalla_TeclaPulsada(SDL_SCANCODE_RIGHT)) PersonajeMueve(p,vx/sqrt(2),-vy/sqrt(2)),PersonajeRota(p,45);

                /**< Controlamos la inserción de las monedas */
                if (rand()%1==0)
                {
                    GalaxiaInserta(g,si,33+rand()%(Pantalla_Anchura()-(sw+66)),33+rand()%(Pantalla_Altura()-sh-66),sw,sh);
                }

                int tiempoFinal=time(NULL);
                int tiempo=tiempoFinal-tiempoInicio;
                sprintf(texto,"Time: %d s",tiempo);

                sprintf(texto2,"%d",puntos);
                /**<  Para la inserción de los enemigos según los puntos*/
                if (Enemigos==0 && tempararicion==0)
                {
                    EjercitoInserta(E,ei,rand()%(Pantalla_Anchura()-pw-35),ey,ew,eh,vx,vy);
                    Enemigos++;
                }

                if (Enemigos==1 && puntos>=25 && tempararicion==0)
                {
                    EjercitoInserta(E,ei,rand()%(Pantalla_Anchura()-pw-35),ey,ew,eh,vx,vy);
                    Enemigos++;
                }

                if (Enemigos==2 && puntos>=50 && tempararicion==0)
                {
                    EjercitoInserta(E,ei,rand()%(Pantalla_Anchura()-pw-35),ey,ew,eh,vx,vy);
                    Enemigos++;
                }
                if (tempararicion>0)tempararicion--;
                /**<  Invulnerabilidad del personaje después de morir durante cierto tiempo */

                if (!invulnerable)
                {
                    if (EjercitoColision(E,PersonajeGetX(p),PersonajeGetY(p),PersonajeGetW(p),PersonajeGetH(p)))
                    {
                        vida--;
                        Enemigos--;
                        PersonajeSetX(p,500);
                        PersonajeSetY(p,500);
                        PersonajeRota(p,0);
                        invulnerable=1;
                        temp=150;
                        tempararicion=50;

                    }
                }
                if (temp>0)
                {
                    temp--;
                    invulnerable=1;
                    Pantalla_ColorRelleno(255,255,255,100);
                    Pantalla_ColorTrazo(0,85,85,255);
                    Pantalla_DibujaCirculo(PersonajeGetX(p)+25,PersonajeGetY(p)+25,32);
                }
                else
                {
                    invulnerable=0;
                }

                if (vida==0) terminado=1;

                EjercitoMueve(E);
                RafagaMueve(r);
                if (RafagaColision(r,E))
                {
                    tempararicion=50;
                    Enemigos--;
                    puntos=puntos+3;
                }

            }
            RafagaDibuja(r);
            /**<  Insercion de las vidas*/
            Pantalla_ColorTrazo(255, 255, 255,255);
            Pantalla_DibujaTexto("Press ESC to CLOSE", 10,10);
            Pantalla_DibujaImagen(pointsIm,25,575,60,20);
            if (puntos>=0) lvl=1;
            if (puntos>=25) lvl=2;
            if (puntos>=50) lvl=3;
            if (vida>0) VidaDibuja(L1);
            if (vida>1) VidaDibuja(L2);
            if (vida>2)  VidaDibuja(L3);
            /**<  Para disparar a los enemigos y disparar con el ESPACIO*/
            if ((Pantalla_TeclaPulsada(SDL_SCANCODE_P)&&(t==0)))
            {
                RafagaInserta(r,bala,PersonajeGetX(p)+19,PersonajeGetY(p)+15,12,23,10,10,PersonajeGetAngulo(p));
                t=10;

            }
            if (t>0) t--;

            Pantalla_DibujaTexto(texto,900,10);
            Pantalla_ColorTrazo(255,255,255,255);
            Pantalla_DibujaTexto(texto2,85,580);

            char nivel[50];
            sprintf(nivel,"LVL %d ",lvl);
            Pantalla_DibujaTexto(nivel,450,5);

            GalaxiaDibuja(g);
            PersonajeDibuja(p);
            EjercitoDibuja(E);
            /**<  Los dibujos de cuando estemos en modo pausa*/
            if (pausa)
            {
                Pantalla_DibujaImagen(pause,350,150,300,300);
                Pantalla_ColorRelleno(0,0,0,255);
                Pantalla_DibujaRectangulo(400,365,200,35);
                Pantalla_ColorTrazo(255,255,255,255);
                Pantalla_DibujaTexto("PRESS 2 TO CONTINUE  ",420 ,375);
            }


            Pantalla_Actualiza();
            Pantalla_Espera(10);
        }



        PersonajeLibera(p);
        GalaxiaLibera(g);
        EjercitoLibera(E);

        RafagaLibera(r);
        VidaLibera(L1);
        VidaLibera(L2);
        VidaLibera(L3);

        Pantalla_ImagenLibera(pause);
        Pantalla_ImagenLibera(pi);
        Pantalla_ImagenLibera(ei);
        Pantalla_ImagenLibera(fondo);
        Pantalla_ImagenLibera(si);
        Pantalla_ImagenLibera(v1);
        Pantalla_ImagenLibera(bala);

        Pantalla_ImagenLibera(pointsIm);
        terminado=0;
        int puntos_max;
        FILE*f=fopen("resultado.txt","r");
        fscanf(f,"%d",&puntos_max);
        fclose(f);
        /**<  Control de la puntuación */
        if (puntos>puntos_max)
        {

            FILE*f=fopen("resultado.txt","w");
            fprintf(f,"%d",puntos);
            fclose(f);
            sprintf(texto,"NUEVO RECORD: %d",puntos);
        }
        /**<  Muestra por pantalla la pantalla final */
        else sprintf(texto,"Husted ha conseguido tantos puntos %d    -   Record: %d  ",puntos,puntos_max);
        fondo=Pantalla_ImagenLee("Game_Over.bmp",0);
        while (Pantalla_Activa() && !terminado)
        {

            if (Pantalla_TeclaPulsada(SDL_SCANCODE_F1)) terminado=1;
            Pantalla_DibujaImagen(fondo,0,0,Pantalla_Anchura(),Pantalla_Altura());
            Pantalla_ColorTrazo(255,255,255,255);
            Pantalla_DibujaTexto("Pulsa F1 para salir", 30,30);
            Pantalla_DibujaTexto(texto,30,60);
            Pantalla_Actualiza();
            Pantalla_Espera(40);
        }
    }
    Pantalla_ImagenLibera(fondo);
    Pantalla_Libera();
    return 0;
}

