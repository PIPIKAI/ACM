#include<stdio.h>
#include<math.h>
#define MAX 1000010
int isap[MAX]={0};
void sshai()
{
    int i,j,n=sqrt(MAX)+1;
    for(i=2;i<=n;i++)
        for(j=2;j<=MAX/i;j++)
            isap[j*i]=1;
}
int main()
{

	int n;
	sshai();
	while(~scanf("%d",&n))
    {

	if(isap[n]==1)
        printf("0\n");
    else
        printf("1\n");
    }



}
