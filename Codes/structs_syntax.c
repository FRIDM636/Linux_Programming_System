#include<stdio.h>



typedef char Byte;
typedef struct point;
struct point {
	int x,y;
}a,b,P; //these are object list declaration


/*
typedef struct point P;
struct point {
	int x,y;
}a,b,point; // these are declaration
*/
/*
typedef struct{
 	int x,y;
	}a,b,P; //these are alias
*/
/*
 struct point {
 	int x,y;
	}; //we must add stuct keywork before point each time
*/ 

  /*
struct point {
	int x,y;
}a,b; //This is an object list declaration
*/
int main(){
	//struct point p ;
	//struct point p = {3,4};
	//struct point g = {1,2};
	//P g = {1,2};
	Byte c = 'A';
	//b g = {1,2};
	struct point f = {3,4};
	//a.x = 6;
	//a.y = 8;
	//b.x = 3;
	//b.y = 4;
	//printf("point a is: (%d,%d)\n",a.x,a.y);
	//printf("point b is: (%d,%d)\n",b.x,b.y);
	printf("Byte is: %c\n",c);
	printf("point f is: (%d,%d)\n",f.x,f.y);
	//printf("point is: (%d,%d)\n",p.x,p.y);
	return 0;
}
