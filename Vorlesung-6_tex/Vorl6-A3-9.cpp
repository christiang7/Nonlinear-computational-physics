#include <cmath>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include "nr_progs.cxx"
#define ENDLAN cout<< 'e' << endl << flush
using namespace std ;

const int nsteps = 50000;
const int n=300
;
const double omega=0.5;
double 
R ,
beta0 = M_PI/4.,
eps = 1.4,
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
    konz = 1., // Parameter für die Verteilung der Oszillatoren auf dem Einheitskreis
    mittel,
    cphi,
    sphi
    ;
    
    X = dvector(1,n);
    
    cout.setf(ios::scientific);cout.precision(4);
    cout<<"set xrange [-1.1:1.1]"<<endl;
    cout<<"set yrange [-1.1:1.1]"<<endl;
    cout<<"set nokey"<<endl;
    cout<<"set title 'Kuramotosakag Modell'"<<endl;
    cout<<"set siz sq"<<endl;
        
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
            cout<<"plot '-' w p,'-' w l,'-' w p pt 3 ps 2 ,'-' w l, '-' w p pt 5 ps 2"<<endl;
            rk( X,n, t,h, kuramotosakageq, 1);
            stheta =0.;
            ctheta =0.;
            for(int i = 1;i<=n;i++)
            {
                sphi = sin(X[i]);
                cphi = cos(X[i]);
                stheta += sphi;
                ctheta += cphi;
                cout << cphi << ' ' << sphi << endl;
            }
            ENDLAN;
            cout << "0 0" << endl << cphi << ' ' << sphi << endl; ENDLAN;
            cout << cphi << ' ' << sphi << endl; ENDLAN;
            stheta/=n; ctheta/=n;
            cout << "0 0" << endl << ctheta << ' ' << stheta << endl; ENDLAN;
            cout<< ctheta << ' ' << stheta << endl;  ENDLAN;
            R = sqrt(stheta*stheta+ctheta*ctheta)/n;
            cout<<"set label 1 \"time= ";
            printf("%10.2f",t);  cout<<" \" at screen 0.8,0.9";  cout<<endl<<flush;
            usleep(50*1000);
            //mittel=mittel+ R;
            //cout << t << ' ' << R << endl;
        
        }
        //cout << mittel/nsteps << ' ' << eps << endl;
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
