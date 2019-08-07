#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
	int k,n,f[255];
	int last=0,len,i;
	char str[255];
	int sum=0;
	scanf("%d%s",&k,str);
	len=strlen(str);
	while(i<len)
	{
		f[i]=str[i]-'0';
		sum+=f[i];
		i++; 
	}
	if(sum>=k)
	{
		printf("0");
		return 0;
	}
	sort(f,f+len);
	for(i=0;i<len;i++)
	{
		if(sum+9-f[i]>=k)
		{
			last++;
			break;
		}
		else
		{
			sum+=9-f[i];
			last++;
		}
		
	}
	printf("%d",last);

	return 0;
}
