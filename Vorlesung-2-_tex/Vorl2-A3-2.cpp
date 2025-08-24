#include <cmath>
#include <fstream>
#include <iostream>
#include "nr_progs.cxx"
using namespace std ;

void vandpoleq(double t,double x[], double dxdt[]);

int main ()
{
    
    double // Kommentar
    *x,
    t ,
    h = 0.05;
    int nsteps = 10000;
    x = dvector(1,2);
    x[1] = 0.1;
    x[2] = 0.4;
    for(int i = 1; i <= nsteps; i++)
    {
    rk( x,2, t,h, vandpoleq, 1);
    cout << t << ' ' << x[1] << ' ' << x[2] << endl;
    }
};

void vandpoleq(double t,double x[], double dxdt[])
{
    double 
    mu = 5;
    
    dxdt[1]=x[2];
    dxdt[2]=mu*(1-x[1]*x[1])*x[2]-x[1];
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
