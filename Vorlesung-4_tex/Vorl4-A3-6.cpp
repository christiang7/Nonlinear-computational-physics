#include <cmath>
#include <fstream>
#include <iostream>
#include "nr_progs.cxx"
using namespace std ;

const int nsteps = 1000000 ;

void roesslereqt(double t,double x[], double dxdt[]);
void roesslereqy(double y,double x[], double dxdy[]);
double Periode(double t,double X[]);

int main ()
{
    
    double // Kommentar
    *X,
    t ,
    *T,
    *tempy,
    *xn,
    h = 0.005
    ;
    int 
    n = 3,
    k = 0,
    j = 0
    ;
    
    X = dvector(1,n);
    tempy = dvector(1,nsteps);
    xn = dvector(1,nsteps);
    T = dvector(1,nsteps);

    X[1] = 0.1;
    X[2] = 0.4;
    X[3] = 0.7;
    rk( X,n, t,h, roesslereqt, 10000); // Einschwingzeit
    for(int i = 1; i <= nsteps; i++)
    {
        rk( X,n, t,h, roesslereqt, 1);
        tempy[i]=X[2];
        //cout << X[1] << endl;
        //T[j]=t;
        if  (i >=2)
            if ((tempy[i-1] > 0.) and (tempy[i] < 0.) and (X[1]<0.))
            {
                j = j+1;
                //cout << '#'<< tempy[i-1] << ' '<< tempy[i] << ' ' << X[1] << ' ' << t << endl;
                T[j]=Periode(t,X);
                //cout <<'#'<< T[j] << endl;
                xn[j]=X[1];
            }
    }
    // Ausgabe der Periode mit den x Werten
    for (int i = 2;i <= j;i= i+1)
    {
        cout << xn[i-1] << ' ' << T[i] - T[i-1] <<  endl;
    }
};

void roesslereqt(double t,double x[], double dxdt[])
{
    double 
    a = 0.15,
    b = 0.4,
    c = 8.5
    ; 
    
    dxdt[1]=(-x[2]-x[3]);
    dxdt[2]=x[1]+a*x[2];
    dxdt[3]=b+x[3]*(x[1]-c);
}    
;    
void roesslereqy(double y,double x[], double dxdy[])
{
    double 
    a = 0.15,
    b = 0.4,
    c = 8.5
    ; 
    
    dxdy[1]=(-y-x[3])/(x[1]+a*y);
    dxdy[2]=1/(x[1]+a*y);
    dxdy[3]=(b+x[3]*(x[1]-c))/(x[1]+a*y);
}    
;    

double Periode(double t, double X[])
{
    double
    y
    ;
    
    y=X[2];
    X[2]=t;
    rk( X,3, y,-y, roesslereqy, 1);
    t=X[2];
    X[2] =y;
    return t;
};
