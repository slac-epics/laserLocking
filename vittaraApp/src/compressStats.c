/* compressStats.c, 2012-09-10 */
/* current author: Matjaz Kobal */

#include <stdio.h>
#include <math.h>
#include <dbEvent.h>
#include <dbDefs.h>
#include <dbCommon.h>
#include <recSup.h>
#include <aSubRecord.h>
#include <registryFunction.h>
#include <epicsExport.h>

# define MAX_SAMPLES 1000
# define PI 3.1415926535


int compressStats(aSubRecord *precord)
{	
	unsigned long i, N, Nc;
	double data[MAX_SAMPLES], datac[MAX_SAMPLES],datad[MAX_SAMPLES];
	double avg, std, std_scale, phase;
	
	N=precord->noa;     // INPA number of samples
	Nc=precord->noc;     // INPC number of samples

	std_scale= *(double *) precord->b;     // STD scale
        if (std_scale == 0) { std_scale=1;}

        memcpy(data,precord->a,N*sizeof(double));


	if (Nc==N) {
	   memcpy(datac,precord->c,Nc*sizeof(double)); 
	   memcpy(datad,precord->d,Nc*sizeof(double)); 
           for (i=0;i<N; i++){
	      phase=data[i];
	      data[i]= phase/sqrt(datac[i]*datad[i]);
           }
        }

	avg=0;
	for (i=0;i<N; i++){
	    avg=avg+data[i];	
	}
	avg=avg/N;


	std=0;
	for (i=0; i<N; i++){
	    std=std+(avg-data[i])*(avg-data[i]);	
	}
	std=sqrt(std/N);

	*(double *)precord->vala=avg;
        *(double *)precord->valb=std_scale*std;	

	return 0;
}

epicsRegisterFunction(compressStats);
