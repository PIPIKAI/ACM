#include<stdio.h>
#include<string.h>
int change(char *s);
int cifang(int x,int n);
int qie(char *str ,int k,int count)
{
	char t[2500];
	int i,j;
	for(i=count,j=0;i<k+count;i++)
	{
		t[j]=str[i];j++;
	}
	t[j]='\0';
	printf("%s",t);
	return change(t);
}
int change(char *str)
{
	int i,sum=0,j;
	for(i=strlen(str)-1,j=0;i>=0;j++,i--)
	{
		sum+=cifang((str[j]-'0'),i);
	}
	printf("  sum=%d\n",sum);
	return sum;
}
int cifang(int x,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		x=2*x;
	}
	return x;
}
int main()
{
	int n,len,i=0,t;

	while(scanf("%d\n",&n)!=EOF)
{
	i=0;
	char str[n][255];
	int m [n];
	int f[n];

	while(i<n)
	{
		scanf("%d\n%s",&m[i],str[i]);
			f[i]=0;
		i++;
	}
	i=0;
		while(i<n)
		{
			int j=0;
			len=strlen(str[i]);
			if(m[i]==len)
			{
				f[i]=change(str[i]);
				if(f[i]<t)
				f[i]=t;
			}
			else
			{
				while(j<=len-m[i])
				{

				    t=qie(str[i],m[i],j);
					if(f[i]<t)
					f[i]=t;
					j++;
				}
			}
		i++;
		}

	for(i=0;i<n;i++)
	printf("Case #%d: %d\n",i+1,f[i]);
}
	return 0;
}
