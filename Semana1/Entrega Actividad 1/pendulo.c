#include <stdio.h>
#include <math.h>
#include <windows.h>

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

int main(int argc, char *argv[])
{
  LARGE_INTEGER t_ini, t_fin;
  double secs;

  QueryPerformanceCounter(&t_ini);
    
    
    int it=1000,i;
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
    
    
  QueryPerformanceCounter(&t_fin);

  secs = performancecounter_diff(&t_fin, &t_ini);
  printf("%.16g milliseconds\n", secs * 1000.0);
  return 0;
}