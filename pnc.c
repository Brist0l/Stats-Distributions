long long factorial(int n);
long long combine(int n,int r);
long long permute(int n,int r);

long long permute(int n,int r){
	long long perm = factorial(n)/factorial(n-r);
}
// nCr
long long combine(int n,int r){ 
	long long comb = factorial(n)/(factorial(n-r)*factorial(r));
	return comb;
}

long long factorial(int n){
	long long fact = n;

	while(n > 1)
		fact *= --n;
	if(n == 0)
		return 1;

	return fact;
}
