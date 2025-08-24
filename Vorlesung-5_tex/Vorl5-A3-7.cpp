#include <cmath>
#include <fstream>
#include <iostream>
#include "nr_progs.cxx"
using namespace std ;

const int nsteps = 50000;
const int n=10
;
const double omega=0.5;
double 
R ,
beta = M_PI/1.5,
eps = 0.1,
stheta,
ctheta
;

void kuramotosakageq(double t,double x[], double dxdt[]);

int main ()
{
    
    double 
    *X,
    t ,
    h = 0.05,
    konz = 0.01 // Parameter für die Verteilung der Oszillatoren auf dem Einheitskreis
    ;
    
    X = dvector(1,n);

    for(int i = 1;i <= n;i++)
    {
        X[i]=konz*2*M_PI*i/n;
    }
    X[8]=X[8]+1e-8; //Störung eingeführt
    //rk( X,n, t,h, kuramotosakageq, 10000); // Einschwingzeit
    for(int i = 1; i <= nsteps; i++)
    {
        
        rk( X,n, t,h, kuramotosakageq, 1);
        stheta =0.;
        ctheta =0.;
        for(int i = 1;i<=n;i++)
        {
        stheta += sin(X[i]);
        ctheta += cos(X[i]);
        }
        R = sqrt(stheta*stheta+ctheta*ctheta)/n; 
        cout << t << ' ' << R << endl;
    }
};

void kuramotosakageq(double t,double x[], double dxdt[])
{
    double 
    theta
    ;
    stheta =0.;
    ctheta =0.;
    for(int i = 1;i<=n;i++)
    {
        stheta += sin(x[i]);
        ctheta += cos(x[i]);
    }
    R = sqrt(stheta*stheta+ctheta*ctheta)/n; 
    theta = atan2(stheta,ctheta);
    for(int i = 1; i<= n;i++)
    {
        dxdt[i]=omega +eps*R*sin(theta-x[i]+beta);
    }
}
;
