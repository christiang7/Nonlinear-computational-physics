#include <cmath>
#include <fstream>
#include <iostream>
#include "nr_progs.cxx"
using namespace std ;

const int nsteps = 10000 ;
const int ncells = 10;
void celleqt(double t,double x[], double dxdt[]);
void celleqX(double X,double x[], double dxdX[]);
double Zeit(double t,double x[]);

int main ()
{
    
    double // Kommentar
    *x,
    t ,
    *T,
    *tempx,
    *xn,
    h = 0.3,
    signal,
    X,
    tausch
    ;
    int 
    k = 0,
    j = 0
    ;
    
    x = dvector(1,ncells);
    tempx = dvector(1,ncells);
    xn = dvector(1,nsteps);
    T = dvector(1,nsteps);
    
    //Anfangsbedingungen:
    for(int i = 1; i <= ncells; i++)
    {
        x[i] = 1.-double(i)/double(ncells); 
        //cout << x[i] << endl;
    }
    
    
    for(int i = 1; i <= nsteps; i++)
    {
        /*
        for(int k = 1; k <= ncells; k++)
        {
          tempx[k] = x[k];
          //cout << x[k] << endl;
        }
        */
        rk( x,ncells, t,h, celleqt, 1);
        
        for(int l = 1; l <= ncells; l++)
        {
            //cout << x[l] << endl;
            if (x[l]>=1.)
            {
                tausch=x[1];
                x[1]=x[l]-1.;
                x[l]=tausch;
                t=Zeit(t,x);
                x[l]=0.;
                signal = l;
                cout << t << ' ' << signal << endl;
            }
        }
        cout << x[1] << endl;
        //T[j]=t;
        
    }
    // Ausgabe der Zeit mit den x Werten
    /*
    for (int i = 2;i <= j;i= i+1)
    {
        cout << xn[i-1] << ' ' << T[i] - T[i-1] <<  endl;
    }
    */
};

void celleqt(double t,double x[], double dxdt[])
{
    double
    x0=1.
    ;
    for(int i = 1; i <= ncells; i++)
    {
        dxdt[i]=x0-x[i];
    }
}
;

void celleqX(double X,double x[], double dxdX[])
{
    double 
    x0=1.
    ; 
    dxdX[1]=1./(x0-X);
    for(int i = 2; i <= ncells; i++)
    {
        dxdX[i]=(x0-x[i])/(x0-X);
    }
    
}
;


double Zeit(double t, double x[])
{
    double
    temp
    ;
    cout << 100 << endl;
    temp=x[1];
    x[1]=t;
    rk( x,ncells, temp,-temp, celleqX, 1);
    t=x[1];
    x[1]=temp;
    return t;
}
;
