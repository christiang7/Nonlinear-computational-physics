#include <cmath>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include "nr_progs.cxx"
using namespace std ;

const int nsteps = 50000;
const int n=500
;

double 
eps,
*omega
;

void kuramotosakageq(double t,double x[], double dxdt[]);

int main ()
{
    
    double 
    *X,
    t ,
    h = 0.05,
    konz = 1., // Parameter für die Verteilung der Oszillatoren auf dem Einheitskreis
    mittel,
    stheta,
    ctheta
    ;
    omega = dvector(1,n);
    X = dvector(1,n);
    for(int i = 1;i <= n;i++)
    {
        omega[i]=tan(-0.97*M_PI/2.+0.97*M_PI/(n-1.)*(i-1.));
    }
    for(eps=1.5; eps < 2.5; eps=eps + 0.1)
    {
        for(int i = 1;i <= n;i++)
        {
            X[i]=konz*2*M_PI*i/n;
        }
        mittel = 0.;
        rk( X,n, t,h, kuramotosakageq, 5000);
        for(int i = 1; i <= nsteps; i++)
        {
            rk( X,n, t,h, kuramotosakageq, 1);
            stheta =0.;
            ctheta =0.;
            for(int j = 1;j<=n;j++)
            {
                stheta += sin(X[j]);
                ctheta += cos(X[j]);
            }
            mittel+= sqrt(stheta*stheta+ctheta*ctheta)/n;
        }
        cout << eps << ' ' << mittel/nsteps << endl;
    }
};

void kuramotosakageq(double t,double x[], double dxdt[])
{
    double 
    theta,
    stheta,
    ctheta,
    R
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
        dxdt[i]=omega[i] +eps*R*sin(theta-x[i]);
    }
}
;
