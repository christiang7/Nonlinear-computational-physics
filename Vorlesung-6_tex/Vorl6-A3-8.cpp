#include <cmath>
#include <fstream>
#include <iostream>
#include "nr_progs.cxx"
using namespace std ;

const int nsteps = 5000;
const int n=10
;
const double omega=0.5;
double 
R ,
beta0 = M_PI/4.,
eps = 0.1,
stheta,
ctheta
;

void kuramotosakageq(double t,double x[], double dxdt[]);
double betaeq(void);

int main ()
{
    
    double 
    *X,
    t ,
    h = 0.05,
    konz = 0.01, // Parameter für die Verteilung der Oszillatoren auf dem Einheitskreis
    mittel
    ;
    
    X = dvector(1,n);
    
    
    for(eps=0.; eps < M_PI/2.; eps=eps + 0.01)
    {
        for(int i = 1;i <= n;i++)
        {
            X[i]=konz*2*M_PI*i/n;
        }
        X[8]=X[8]+1.e-8; //Störung eingeführt
        
        mittel = 0.;
        
        rk( X,n, t,h, kuramotosakageq, 5000); // Einschwingzeit
        //cout << eps << endl;
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
            mittel=mittel+ R;
            //cout << t << ' ' << R << endl;
        }
        cout << mittel/nsteps << ' ' << eps << endl;
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
        dxdt[i]=omega +eps*R*sin(theta-x[i]+betaeq());
    }
}
;

double betaeq(void)
{
    return (beta0 + eps*eps*R*R);
}
;
