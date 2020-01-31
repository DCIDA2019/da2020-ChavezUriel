#include <stdio.h>
#include <time.h>
#include <math.h>

int main(int argc, char *argv[])
{
    clock_t start = clock();


    int it=10000,i;
    double veli=2.0, posi=0.0, w0=3.0,  ti=0.0, tf=10.0,h, pos[it], vel[it], posreal[it], velreal[it], t[it];

    h=(tf-ti)/(it);
    pos[0]=posi;
    vel[0]=veli;
    posreal[0]=posi;
    velreal[0]=veli;

    for(i=0;i<it;i++)
    {
        pos[i+1]=pos[i]+h*vel[i];
        vel[i+1]=vel[i]+h*(-w0*w0*pos[i]);
        t[i+1]=t[i]+h;
        posreal[i+1]=2/w0*sin(w0*t[i+1]);
        velreal[i+1]=2*cos(w0*t[i+1]);
    }


    printf("Tiempo transcurrido: %f", ((double)clock() - start) / CLOCKS_PER_SEC);

    return 0;
}
