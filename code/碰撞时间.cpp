#include<stdio.h>
#include<algorithm>
using namespace std;
int f[100000];
int max(int a,int b)
{
	return a>b?a:b;
}
int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
    int n,l,j,i;
    int ma=-1,mi;
    
    scanf("%d%d",&n,&l);
    int mid=l/2;
    for(i=0;i<n;i++)
    {
    	scanf("%d",&f[i]);
    	ma=max(ma,max(f[i],l-f[i]));	
	} 
	sort(f,f+n);
      for(i=0;i<n;i++)
	{
	  	
	  	if(mid<f[i])
	  	break;
	}  
	//	printf("%d\n",i);
	 if(i!=n)
		mi=max(f[i-1],l-f[i]);
	else
	mi=f[i-1];
	if(f[i-1]==mid)
	mi=mid;

    printf("%d %d\n",mi,ma);

    return 0;
}
