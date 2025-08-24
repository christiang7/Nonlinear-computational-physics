#include <cmath>
#include <fstream>
#include <iostream>
#include "nr_progs.cxx"
using namespace std ;

const int nsteps = 100000 ;

void lorenzeq(double t,double x[], double dxdt[]);
double maximum(double a, double b, double c);


int main ()
{
    
    double // Kommentar
    *x,
    t ,
    *z,
    //**matrix,
    //matrix[nsteps][4]={0},
    //xmax[nsteps][3]={0},
    *xmax,
    h = 0.005
    ;
    int 
    n =3,
    k = 0,
    j =0
    ;
    
    x = dvector(1,n);
    z = dvector(1,nsteps);
    xmax = dvector(1,nsteps);
    //matrix = dmatrix(1,nsteps,1,4);
    x[1] = 0.1;
    x[2] = 0.4;
    x[3] = 0.7;
    rk( x,n, t,h, lorenzeq, 10000); // Einschwingzeit
    for(int i = 1; i <= nsteps; i++)
    {
        rk( x,n, t,h, lorenzeq, 1);
        //cout << x[3] << endl;
        //matrix[i][0]=x[1];
        //matrix[i][1]=x[2];
        z[i]=x[3];
        //matrix[i][3]=t;
    }
    for(int i = 2;i <=nsteps-1;i++)
    {
        if  ((z[i] > z[i-1]) and (z[i] > z[i+1]))
        {
            j = j+1;
            xmax[j]=maximum(z[i-1],z[i],z[i+1]);
        }
        //cout << t << ' ' << x[1] << ' ' << x[2] << ' ' << x[3] << ' ' << xmax[i][0] << ' ' << xmax[i][1] << ' ' << xmax[i][2] << endl;
    }
    // z_n+1 = z_n Ausgabe
    for (int i = 2;i <= j;i= i+1)
    {
        cout << xmax[i-1] << ' ' << xmax[i] << endl;
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

double maximum(double a, double b, double c)
{
    double
    d, e, f
    ;
            //d = (c-2.*b-a)/2.;
            //e= (b-a-3.*d);
            //f=1.-d-e;
            d = (c-a)/2.-(b-a);
            e = 2.*(b-a)-(c-a)/2.;
            f = a;
            return f-e*e/(4.*d);
            //d = (matrix[i][3]-matrix[i-2][3]-(matrix[i-1][3]-matrix[i-2][3])/(matrix[i-1][j]-matrix[i-2][j])) / (matrix[i][j]*matrix[i][j]-matrix[i-1][j]*matrix[i-1][j]+(matrix[i-1][j]*matrix[i-1][j]-matrix[i-2][j]*matrix[i-2][j])/(matrix[i-1][j]-matrix[i-2][j]));
            //e = ((matrix[i-1][3]-matrix[i-2][3])-a*(matrix[i-1][j]*matrix[i-1][j]-matrix[i-2][j]*matrix[i-2][j])) / (matrix[i-1][j]-matrix[i-2][j]);
            //f = matrix[i-2][3]-a*matrix[i-2][j]*matrix[i-2][j]-b*matrix[i-2][j];
            //xmax[k][j] = c-b*b/(2*a)+b*b/(4*a);
            //k = k +1;
            //cout << xmax[k-1][j] <<endl;
};



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
