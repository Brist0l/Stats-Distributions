#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

void histogram(float suc_rate);
float variance(int* sprt,int size,float p);
float success_rate(float sim_suc,float total);
float expected_val(int* sprt,int size,float p);
bool check_support(int* sprt,int size,int val);
float PMF(int val,float p,int* sprt,int size);
int simulation(int num,float p);
int bern(float p);

void histogram(float suc_rate){
	int successes = suc_rate*10;
	int successes_percent = successes*10;

	printf("Successes:  "); 
	for(int i = 0;i < successes;i++)
		printf("X");
	printf("%*c  (%d%)\n",10-successes+1,' ',successes_percent);

	printf("Failures :  "); 
	for(int i = 0;i < 10-successes;i++)
		printf("X");
	printf("%*c  (%d%)\n",successes+1,' ',100-successes_percent);
}

float variance(int* sprt,int size,float p){
	float var;
	float exs =0;

	for(int i = 0;i < size;i++)
		exs += ((float)*(sprt+i))*((float)*(sprt+i)) * PMF(*(sprt+i),p,sprt,size);	
	
	var = exs - expected_val(sprt,size,p)*expected_val(sprt,size,p);

	return var;

}

float success_rate(float sim_suc,float total){
	return sim_suc/total;
}

float expected_val(int* sprt,int size,float p){
	float E = 0;
	for(int i = 0;i < size;i++)
		E += (float)*(sprt+i) * PMF(*(sprt+i),p,sprt,size);	
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

float PMF(int val,float p,int* sprt,int size){
	//P(X = val) = p	
	if(!check_support(sprt,size,val))
		fprintf(stderr,"Invalid support with val: %d\n",val);
	if(val == 1)
		return p;
	else
		return 1-p;
}

int simulation(int num,float p){
	int sucesses = 0;
	for(int i = 0;i < num;i++){
		if(bern(p) == 1){
			printf("%d simulation:Selected\n",i);
			sucesses++;
		}
		else
			printf("%d simulation:Not Selected\n",i);
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

	float p = 0.345;
	int support[2] = {0,1};
	int total_sim = 10;

	int success = simulation(total_sim,p);
	float sucess_rate = success_rate((float)success,(float)total_sim);
	histogram(sucess_rate);
	
	clock_t end_time = clock(); 
	printf("Time taken:%f secs\n",(double)(end_time-start_time)/CLOCKS_PER_SEC);
}
