#define NR_END 1
#define FREE_ARG char*
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>


void nrerror(char error_text[])
/* Numerical Recipes standard error handler */
{
	fprintf(stderr,"Numerical Recipes run-time error...\n");
	fprintf(stderr,"%s\n",error_text);
	fprintf(stderr,"...now exiting to system...\n");
	exit(1);
}

double *dvector(long nl, long nh)
/* allocate a double vector with subscript range v[nl..nh] */
{
	double *v;

	v=(double *)malloc((size_t) ((nh-nl+1+NR_END)*sizeof(double)));
	char msg[]="allocation failure in dvector()";
	if (!v) nrerror(msg);
	return v-nl+NR_END;
}

int *ivector(long nl, long nh)
/* allocate an int vector with subscript range v[nl..nh] */
{
        int *v;

        v=(int *)malloc((size_t) ((nh-nl+1+NR_END)*sizeof(int)));
	char msg[]="allocation failure in ivector()";
	if (!v) nrerror(msg);
        return v-nl+NR_END;
}

unsigned long *lvector(long nl, long nh)
/* allocate an unsigned long vector with subscript range v[nl..nh] */
{
        unsigned long *v;

        v=(unsigned long *)malloc((size_t) ((nh-nl+1+NR_END)*sizeof(long)));
        char msg[]="allocation failure in lvector()";
        if (!v) nrerror(msg);
        return v-nl+NR_END;
}

double **dmatrix(long nrl, long nrh, long ncl, long nch)
/* allocate a double matrix with subscript range m[nrl..nrh][ncl..nch] */
{
        long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
        double **m;

        /* allocate pointers to rows */
        m=(double **) malloc((size_t)((nrow+NR_END)*sizeof(double*)));
        char msg[]="allocation failure 1 in matrix()";
	if (!m) nrerror(msg);
        m += NR_END;
        m -= nrl;

        /* allocate rows and set pointers to them */
        m[nrl]=(double *) malloc((size_t)((nrow*ncol+NR_END)*sizeof(double)));
	char msg1[]="allocation failure 2 in matrix()";
        if (!m[nrl]) nrerror(msg1);
        m[nrl] += NR_END;
        m[nrl] -= ncl;

        for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;

        /* return pointer to array of pointers to rows */
        return m;
}


void free_dvector(double *v, long nl, long nh)
/* free a double vector allocated with dvector() */
{
	free((FREE_ARG) (v+nl-NR_END));
}

void free_ivector(int *v, long nl, long nh)
/* free an int vector allocated with ivector() */
{
        free((FREE_ARG) (v+nl-NR_END));
}

void free_lvector(unsigned long *v, long nl, long nh)
/* free an unsigned long vector allocated with lvector() */
{
        free((FREE_ARG) (v+nl-NR_END));
}

void free_dmatrix(double **m, long nrl, long nrh, long ncl, long nch)
/* free a double matrix allocated by dmatrix() */
{
        free((FREE_ARG) (m[nrl]+ncl-NR_END));
        free((FREE_ARG) (m+nrl-NR_END));
}


//********************   ODE Integration   *********************
//*************************************************************/
//====         Simple RK Integrator       ========

void rk(double y[],int n,double &x,double h,
     void (*derivs)(double, double[], double[]), int nt)
{
  int it,i;
  double hh,h6,xh,*yt,*dy0,*dyt,*dym;
  yt=dvector(1,n);    dy0=dvector(1,n);
  dyt=dvector(1,n);   dym=dvector(1,n);

  hh=h*0.5;    h6=h/6.;
  for (it=1;it<=nt;it++)
    {
      xh=x+hh;
      (*derivs)(x,y,dy0);
      for(i=1;i<=n;i++) yt[i]=y[i]+hh*dy0[i];
      (*derivs)(xh,yt,dyt);
      for(i=1;i<=n;i++) yt[i]=y[i]+hh*dyt[i];
      (*derivs)(xh,yt,dym);
      for(i=1;i<=n;i++)
        {
          yt[i]=y[i]+h*dym[i];
          dym[i]=dyt[i]+dym[i];
        }
      x+=h;
      (*derivs)(x,yt,dyt);
      for(i=1;i<=n;i++) y[i]+=h6*(dy0[i]+2.*dym[i]+dyt[i]);
    }
  free_dvector(yt,1,n);     free_dvector(dyt,1,n);
  free_dvector(dy0,1,n);    free_dvector(dym,1,n);
}
//==================================================================
