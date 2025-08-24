#include <cmath>
#include <fstream>
#include <iostream>
#include "nr_progs.cxx"
using namespace std ;

void vandpoleq(double t,double x[], double dxdt[]);
void pred_corr(double x1[], double x2[],double h,int k,double dx1dt[],double dx2dt[]);

const int nsteps = 10000;

int main ()
{

    double // Kommentar
    *x1,
    *x2,
    t ,
    h = 0.05,
    *dx1dt,
    *dx2dt
    ;
    int
    k=0,
    nwerte=4
    ;
    x1 = dvector(1,nsteps);
    x2 = dvector(1,nsteps);    
    dx1dt = dvector(1,nsteps);
    dx2dt = dvector(1,nsteps);
    for(int i = 1; i < nwerte; i++)
    {
        x1[i]=0.8*i;
        x2[i]=0.9*i;
        dx1dt[i]=x1[i];
        dx2dt[i]=x2[i];
    }
    for(int i = 3; i <= nsteps-nwerte; i++)
    {
        //rk( x,2, t,h, vandpoleq, 1);
        pred_corr(x1,x2,h,i,dx1dt,dx2dt);
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
        cout << h*(i+1) << ' ' << x1[i+1] << ' ' << x2[i+1] << endl;
    }
};

void vandpoleq(double t,double x[], double dxdt[])
{
    double
    mu = 5.;

    dxdt[1]=x[2];
    dxdt[2]=mu*(1-x[1]*x[1])*x[2]-x[1];
}
;

void pred_corr(double x1[], double x2[],double h,int i,double dx1dt[], double dx2dt[])
{
    double

    mu=5.
    ;
    //predictor step
    dx1dt[i]=x2[i];
    dx2dt[i]=mu*(1-x1[i]*x1[i])*x2[i]-x1[i];
    x1[i+1]=x1[i]+h/12.*(23.*dx1dt[i]-16.*dx1dt[i-1]+5.*dx1dt[i-2]);
    x2[i+1]=x2[i]+h/12.*(23.*dx2dt[i]-16.*dx2dt[i-1]+5.*dx2dt[i-2]);
    //corrector step
    dx1dt[i+1]=x2[i+1];
    dx2dt[i+1]=mu*(1-x1[i+1]*x1[i+1])*x2[i+1]-x1[i+1];
    x1[i+1]=x1[i]+h/12.*(5.*dx1dt[i+1]+8.*dx1dt[i]-dx1dt[i-1]);
    x2[i+1]=x2[i]+h/12.*(5.*dx2dt[i+1]+8.*dx2dt[i]-dx2dt[i-1]);
}
;
