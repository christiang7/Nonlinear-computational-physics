#include <cmath>
#include <fstream>
#include <iostream>
#include "nr_progs.cxx"
using namespace std ;

void lorenzeq(double t,double x[], double dxdt[]);

int main ()
{
    
    double // Kommentar
    *x,
    t ,
    h = 0.05;
    int nsteps = 10000, n =3;
    x = dvector(1,n);
    x[1] = 0.1;
    x[2] = 0.4;
    x[3] = 0.7;
    rk( x,n, t,h, lorenzeq, 1000); // einschwingzeit
    for(int i = 1; i <= nsteps; i++)
    {
    rk( x,n, t,h, lorenzeq, 1);
    cout << t << ' ' << x[1] << ' ' << x[2] << ' ' << x[3] << endl;
    }
};

void lorenzeq(double t,double x[], double dxdt[])
{
    double 
    a = 10.,
    b = 28.,
    c = - 8./3.
    ; 
    
    dxdt[1]=a*(x[2]-x[1]);
    dxdt[2]=b*x[1]-x[2]- x[1]*x[3];
    dxdt[3]=c*x[3]+x[1]*x[2];
}    
;    





/*
    for (r = 0.; r < 4.; r = r+delta_r)// erste Schleife für die r Werte
    {
        x = 0.3;
        for (int i = 0; i < 1000; i++)// zweite Schleife für die x Werte
        {
            x = r*x*(1-x);
            //cout << x << endl;
            if (i >= 900)
            {
                cout << r << ' ' << x << endl;
            }
        }
    }
    */
