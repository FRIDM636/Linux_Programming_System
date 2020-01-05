#include<stdio.h>

void* func(){
	return (void*)(18);
}

int func_arg(int x){
	return x;
}

void* caller(void* (*p)()) {
	return p();
}

int caller_args(int (*p)(), int arg){
	return p(arg);
}

int main(){

	void* (*p)();
	int (*q)(int);
	p = func;
	q = func_arg;

	printf("Value func p() is: %d\n",p());
	printf("Value caller(p) is: %d\n",caller(p));
	printf("Value caller_args(q,arg) is: %d\n",caller_args(q,18));

	return 0;
}
