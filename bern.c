#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

#include"bin.h"

void histogram(float suc_rate);
float variance(int* sprt,int size,float p);
float success_rate(float sim_suc,float total);
float expected_val(int* sprt,int size,float p);
bool check_support(int* sprt,int size,int val);
float bern_PMF(int val,float p,int* sprt,int size);
int bern_simulation(int num,float p);
int bern(float p);

void histogram(float suc_rate){
	int successes = suc_rate*10;
	int successes_percent = successes*10;

	printf("Successes:  "); 
	for(int i = 0;i < successes;i++)
		printf("-");
	printf("%*c  (%d%)\n",10-successes+1,' ',successes_percent);

	printf("Failures :  "); 
	for(int i = 0;i < 10-successes;i++)
		printf("-");
	printf("%*c  (%d%)\n",successes+1,' ',100-successes_percent);
}

float variance(int* sprt,int size,float p){
	float var;
	float exs =0;

	for(int i = 0;i < size;i++)
		exs += ((float)*(sprt+i))*((float)*(sprt+i)) * bern_PMF(*(sprt+i),p,sprt,size);	
	
	var = exs - expected_val(sprt,size,p)*expected_val(sprt,size,p);

	return var;

}

float success_rate(float sim_suc,float total){
	return sim_suc/total;
}

float expected_val(int* sprt,int size,float p){
	float E = 0;
	for(int i = 0;i < size;i++)
		E += (float)*(sprt+i) * bern_PMF(*(sprt+i),p,sprt,size);	
	return E;
}

bool check_support(int* sprt,int size,int val){
	int m;
	int l = 0;
	int r = size-1;

	while(l <= r){
		m = l + floor((r-l)/2);
	
		if(*(sprt+m) < val)
			l = m+1;
		else if(*(sprt+m) > val)
			r = m-1;
		else
			return true;
	}
	return false;
}

float bern_PMF(int val,float p,int* sprt,int size){
	//P(X = val) = p	
	if(!check_support(sprt,size,val))
		fprintf(stderr,"Invalid support with val: %d\n",val);
	if(val == 1)
		return p;
	else
		return 1-p;
}

int bern_simulation(int num,float p){
	int sucesses = 0;
	for(int i = 0;i < num;i++){
		int a = bern(p);
//		printf("bern(p) for %d is %d\n",i,a);
		if(a == 1){
			printf("%d\t+\n",i+1);
			sucesses++;
		}
		else
			printf("%d\t-\n",i+1);
	}

	return sucesses;
}

int bern(float p){
	double normalised_rand_guess = (double)rand()/(double)RAND_MAX;

//	printf("Random Number is:%f\n",normalised_rand_guess);

	if(normalised_rand_guess <= p)
		return 1;
	else
		return 0;

}

int main(){
	clock_t start_time = clock(); 
	srand(time(NULL));

	float p = 0.5;
	int support[11] = {0,1,2,3,4,5,6,7,8,9,10};
	int total_sim = 10;

//	int success = bern_simulation(total_sim,p);
//	float sucess_rate = success_rate((float)success,(float)total_sim);
//	histogram(sucess_rate);

	float bin = bin_PMF(9,p,support,11,11);
	printf("bin PMF:%f\n",bin);

	bin_simulation(10,p,5);
		
	clock_t end_time = clock(); 
	printf("Time taken:%f secs\n",(double)(end_time-start_time)/CLOCKS_PER_SEC);
}
