#include<stdio.h>
# include<bits/stdc++.h>
using namespace std;
void dis(int f[],int n);
void inti(int *f,int n)
{
	srand((int )time(NULL));
	for(int i=0;i<n;i++)
		f[i]=(rand()%20);
}
void shellsort(int f[],int n)
{
	int gap,i,j,temp;
	for(gap=n/2;gap>0;gap/=2)
	{
		for(i=gap;i<n;i++)
		{
			for(j=i-gap;j>=0&&f[j]>f[j+gap];j-=gap)
			{
				swap(f[j],f[j+gap]);
				dis(f,n);
			}
		}
	}
}
void dis(int f[],int n)
{
	for(int i=0;i<n;i++)
	cout<<f[i]<<"  ";
	cout<<endl;
}
int f[100000000];
int main()
{
	int n;
	cin>>n;
	inti(f,n);
	dis(f,n);
	shellsort(f,n);
	dis(f,n);
	return 0;
}
