/*******      biharmonic coupling function       ************/
/*******              animation                  ************/
#include <iostream> 
#include <fstream> 
#include <math.h>
#include "my_defs.h"
#include "nrlib.h"
#define ENDLAN cout<< 'e' << endl << flush
using namespace std;

/*************  important parameters  **************/
const int nosc = 1000;           // number of systems
const double A = 0.2, gam2 = pi, sg2=sin(gam2), cg2=cos(gam2); // parameters
const double gam1=1.5, sg1=sin(gam1), cg1=cos(gam1);
const int ntrans=50000, npt = 5000;
const double tstep=0.1;
double *sp, *cp, *s2p, *c2p;

/******************************************************/
void ensem(double t, double phi[],double phider[])
{
  double X1,X2,Y1,Y2;
  int k;

  X1=X2=Y1=Y2=0;
  for (k=1; k <= nosc; k++)
    {
      sp[k]=sin(phi[k]);     cp[k]=cos(phi[k]);
      s2p[k]=2*sp[k]*cp[k];  c2p[k]=SQR(cp[k])-SQR(sp[k]);
      X1+=cp[k]; Y1+=sp[k];  X2+=c2p[k];   Y2+=s2p[k];
    }
  X1/=nosc; Y1/=nosc; X2/=nosc; Y2/=nosc;
  for (k=1; k <= nosc; k++) 
    phider[k]=(Y1*cg1+X1*sg1)*cp[k]+(Y1*sg1-X1*cg1)*sp[k]+
      A*((Y2*cg2+X2*sg2)*c2p[k]+(Y2*sg2-X2*cg2)*s2p[k]);
}
/******************************************************/
int main () 
{
  double *phi, t,  arc, cphi, sphi, X1, Y1; 
  int i,k;

  /*  ofstream fout("gap_time_anim.dat",ios::out); //  output: raster plot
      fout.setf(ios::scientific);fout.precision(12); */


  cout.setf(ios::scientific);cout.precision(4);
  cout<<"set xrange [-1.1:1.1]"<<endl;
  cout<<"set yrange [-1.1:1.1]"<<endl;
  cout<<"set nokey"<<endl;
  cout<<"set title 'biharmonic model'"<<endl<<flush;
  cout<<"set siz sq"<<endl;
		
  phi=dvector(1,nosc);   t=0.0;
  sp=dvector(1,nosc);    cp=dvector(1,nosc);
  s2p=dvector(1,nosc);   c2p=dvector(1,nosc);

  arc=1.;
  for (i=1; i <= nosc; i++)  phi[i]=arc*pi2/nosc*i;    // Initial conditions
  phi[1]+=10e-8;         // perturbation to the splay state
      
  rk(phi,nosc,t,tstep,ensem,ntrans); // transient
  for (i=1; i<=nosc; i++) phi[i]=fmod(phi[i],pi2);
     
  for (i=1; i <= npt; i++)     // main integration
  {
      cout<<"plot '-' w p,'-' w l,'-' w p pt 3 ps 2 ,'-' w l, '-' w p pt 5 ps 2"<<endl;
      rk(phi,nosc,t,tstep,ensem,5);
      
      if (i%500==0)
      for (k=1;k<=nosc;k++) phi[k]+=k*10e-6;   // perturbation to clusters
      
      X1=Y1=0;
      for (k=1; k <= nosc; k++)
	  {
	    cphi = cos(phi[k]);  sphi = sin(phi[k]);
	    X1 += cphi;          Y1 += sphi;
	    cout << cphi << ' ' << sphi << endl;
	  }
      ENDLAN;
      cout << "0 0" << endl << cphi << ' ' << sphi << endl; ENDLAN;
      cout << cphi << ' ' << sphi << endl; ENDLAN;
      X1/=nosc; Y1/=nosc;
      cout << "0 0" << endl << X1 << ' ' << Y1 << endl; ENDLAN;
      cout<< X1 << ' ' << Y1 << endl;  ENDLAN;
      //      cout<<"set nolabel 1"<<endl<<flush;
      cout<<"set label 1 \"time= ";
      printf("%10.2f",t);  cout<<" \" at screen 0.8,0.9";  cout<<endl<<flush;
  }
  //  fout.close();  
}

