#include <cmath>
#include <fstream>
#include <iostream>
#include "nr_progs.cxx"
using namespace std ;

const int nsteps = 100000;
const int n=50
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
    h = 0.05
    ;
    
    X = dvector(1,n);

    for(int i = 1;i <= n;i++)
    {
        X[i]=0.01*2*M_PI*i/n;
    }
    X[8]=X[8]+1e-8;
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
    *sphi,
    *cphi,
    cbeta=cos(beta),
    sbeta=sin(beta)
    ;
    sphi = dvector(1,n);
    cphi= dvector(1,n);
    stheta =0.;
    ctheta =0.;
    for(int i = 1;i<=n;i++)
    {
        sphi[i]=sin(x[i]);
        cphi[i] = cos(x[i]);
        stheta += sphi[i];
        ctheta += cphi[i];
    }
    
    for(int i = 1; i<= n;i++)
    {
        dxdt[i]=omega +eps/n*(stheta*(cphi[i]*cbeta+sphi[i]*sbeta)-ctheta*(sphi[i]*cbeta-cphi[i]*sbeta));
    }
}
;
