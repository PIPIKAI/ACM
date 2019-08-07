#include<stdio.h>
#include<math.h>
typedef int  getL;
typedef int  getW;
 void disp(int ,int );
struct  ck
{
	int x;
	int y;
};

void area(getL x,getW y)//面积 
{
	printf("rectangle area is %.1d\n",x*y) ;
}
void diagonal(double x,double y)//对角线 
{
	printf("rectangle diagonal is %.1lf \n",sqrt(x*x+y*y)) ;
}
void perimeter(getL x,getW y)//周长 
{
	printf("rectangle perimeter is %.1d\n",2*x+2*y) ;
}
 void disp (getL x,getW y)
 {
 	int i,j;
 	printf("\n");
 	for(j=1;j<=y;j++)
 	{
 		if(j==1)
 		{
 			printf("┍");
 			for(i=2;i<x;i++ )
 			printf("━");
 			printf("┑");
 			printf("\n");
		 }
		 else if(j==y) 
		 {
 			printf("┕");
 			for(i=2;i<x;i++ )
 			printf("━");
 			printf("┙");
 			printf("\n");
		 }
		 else
		 {
		 	printf("│");
 			for(i=2;i<x;i++ )
 			printf("  ");
 			printf("│");
 			printf("\n");
		 }
	 }
 	
 	
 }
 void set1(getL x,getW y)
{
	struct ck sq;
	sq.x=x;
	sq.y=y;
	area(sq.x, sq.y);
	 diagonal(sq.x, sq.y);
}
void set2(getL x,getW y)
{
	struct ck sq;
	sq.x=x;
	sq.y=y;
	
	disp (sq.x, sq.y);
}
int main()
{
	set1(4,3);
	
	set2(5,2);
	getchar(); 
	return 0;
 } 
