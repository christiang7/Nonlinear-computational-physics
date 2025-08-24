#include <cmath>
#include <fstream>
#include <iostream>
#include "nr_progs.cxx"
using namespace std ;

void vandpoleq(double t,double x[], double dxdt[]);
double phidot(double t, double x[]);

double theta; // Variable wird auch in den unter include Programmen mit benutzt GLOBAL! halt

int main ()
{
    
    double // Kommentar
    *x,
    t ,
    delta_theta= 0.001,
    omega,
    h = 0.05
    ;
    int nsteps = 50000,n = 2;
    x = dvector(1,n);
    
    for(theta = 0.8; theta <= 1.2; theta += delta_theta)
    {
    x[1] = 0.1;
    x[2] = 0.4;
    omega = 0.;
    rk( x,n, t,h, vandpoleq, 1000);
    for(int i = 1; i <= nsteps; i++)
    {
        rk( x,n, t,h, vandpoleq, 1);
        omega += phidot(t,x);
    //cout << t << ' ' << x[1] << ' ' << x[2] << ' ' << omega << endl;
    }
    cout << omega/nsteps - theta << ' ' << theta << endl;
    }
};

void vandpoleq(double t,double x[], double dxdt[])
{
    double 
    mu = 0.5,
    eps = 0.1
    ;

    dxdt[1]=x[2];
    dxdt[2]=mu*(1-x[1]*x[1])*x[2]-x[1]+eps*cos(theta*t);
}    
;    


double phidot(double t, double x[])
{
    double 
    *dxdt
    ;
    dxdt = dvector(1,2);
    vandpoleq(t,x,dxdt);
    return -(dxdt[2]*x[1]- dxdt[1]*x[2])/(x[1]*x[1]+x[2]*x[2]);
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
