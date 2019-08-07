#include<stdio.h>
char aa[10000],bb[10000];
int a[10000],b[10000],*B,*S;
int main ()
{
	int n=1,x,y,s=0,end;
	int i,j,flag=0;
	scanf("%s\n%s",aa,bb);
	
	 for(i=0;aa[i]!='\0';i++)
	 a[i]=aa[i]-'0';
	 for(j=0;bb[j]!='\0';j++)
	 b[j]=bb[j]-'0';
	 if(i>=j)
	 {
	 x=end=i-1,y=j-1;
	 B=a,S=b;
	 }
	 else
	 {
	 	x=end=j-1;y=i-1;
	 	B=b,S=a;
	 }
	 	 while(x>=0)
	 {
	 	int temp=s+*(S+y)+*(B+x);
	 	B[x]=temp%10;
	 	s=temp/10;
		 if(s==1&&x==0)
	 	{
	 		for(int i=end;i>=0;i--)
	 		*(B+i+1)=*(B+i);
	 		*(B+0)=1;end++;
		 }
	 	x--;y--;
	 }
	 for(int i=0;i<=end;i++)
	 printf("%d",*(B+i));

	return 0;
 } 
