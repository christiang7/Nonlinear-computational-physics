#include <cmath>
#include <fstream>
#include <iostream>
#include "nr_progs.cxx"
using namespace std ;

void vandpoleq(double t,double x[], double dxdt[]);
void pred_corr(double x[],double h,int k,double dxdt[]);
double power(double zahl, int exponent);

const int nsteps = 1000000;
const double h = 0.01;
const int taureal = 2;
const int tau = int(taureal/h);

int main ()
{

    double // Kommentar
    *x,
    t ,
    *dxdt
    ;
    x = dvector(1,nsteps);
    dxdt = dvector(1,nsteps);
    for(int i = 1; i <= tau; i++)
    {
        x[i]=0.5;
        dxdt[i]=x[i]+0.1;
    }
    //cout << power(2.,4) << endl;
    for(int i = tau+1; i <= nsteps-tau; i++)
    {
        //rk( x,2, t,h, vandpoleq, 1);
        pred_corr(x,h,i,dxdt);
        /*
        for(int j=1+k;j<nwerte;j+=1)
        {
            x1[j+1]=x1[j];
            x2[j+1]=x2[j];
        }
        k+=1;
        for(int l=1;l<=k;l+=1)
        {
            x1[l]=x1[j+l];
            x2[l]=x2[j+l];
        }
        //k+=1;
        //x1[k]=x1[k];
        //x2[1]=
        if k=nwerte then k=0;
        */
        //cout << "gr" << i <<endl;
        if (i>100*tau)
        {
            cout << h*(i+1)-taureal << ' ' << x[i+1] << ' ' << x[i+1-tau] << ' ' << x[i+1-tau-tau] << endl;
        }
    }
};


void pred_corr(double x[],double h,int i,double dxdt[])
{
    double
    gam=1.,
    beta=2.
    ;
    double n =7;
    //predictor step
    dxdt[i]=beta*x[i-tau]/(1+pow(x[i-tau],n))-gam*x[i];
    x[i+1]=x[i]+h/12.*(23.*dxdt[i]-16.*dxdt[i-1]+5.*dxdt[i-2]);
    //corrector step
    dxdt[i+1]=beta*x[i+1-tau]/(1+pow(x[i+1-tau],n))-gam*x[i+1];
    x[i+1]=x[i]+h/12.*(5.*dxdt[i+1]+8.*dxdt[i]-dxdt[i-1]);
}
;
/*
double power(double zahl, int exponent)
{
    double temp=zahl;
    for(int i = 1; i<=(exponent-1);i+=1)
    {
        zahl*=temp;
    }
    return (zahl);
}
;
*/
