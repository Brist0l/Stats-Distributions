#include<stdio.h>
#include<time.h>
#include<math.h>

#include"bern.h"
#include"pnc.h"

float bin_CDF(int n,float p,int k,int* sprt,int size);
void bin_simulation(int num,float p,int reps);
float bin_PMF(int val,float p,int* sprt,int size,int n);

float bin_CDF(int n,float p,int k,int* sprt,int size){
	float cdf = 0;
	for(int i = 0;i <= k;i++)
		cdf += bin_PMF(i,p,sprt,size,n);

	return cdf;
}

void bin_simulation(int num,float p,int reps){
	for(int i = 0;i<reps;i++){
		printf("No. of Successes:%d\n",bern_simulation(num,p));
		printf("\n\n");	
	}

}


float bin_PMF(int val,float p,int* sprt,int size,int n){
	if(!check_support(sprt,size,val))
		fprintf(stderr,"Invalid support with val: %d\n",val);
	double sp = pow(p,val);
	double fp = pow((1-p),n-val);

	float prob = (combine(n,val))*sp*fp;

	return prob;
}
