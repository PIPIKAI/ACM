#include<stdio.h>
# include<bits/stdc++.h>
using namespace std;
void inti(int *f,int n)
{
	srand((int )time(NULL));
	for(int i=0;i<n;i++)
		f[i]=(rand()%20);
}
void Qsort(int f[],int l,int r)
{
	int i=l,j=r,flag=f[l];
	if(l>r)
	return ;
	while(i!=j)
	{
		while(f[j]>=flag&&i<j)
		j--;
		while(f[i]<=flag&&i<j)
		i++;
		if(i<j)
		swap(f[i],f[j]);
	}
	swap(f[l],f[i]);
	Qsort(f,l,i-1);
	Qsort(f,i+1,r);
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
	clock_t start,finish;
	double waste;
	cin>>n;
	inti(f,n);
	dis(f,n);
	start=clock();
	Qsort(f,0,n-1);
	finish=clock();
	waste=(double)(finish-start)/CLOCKS_PER_SEC;
	dis(f,n);
	cout<<"waste :"<<waste<<endl;
	return 0;
}
