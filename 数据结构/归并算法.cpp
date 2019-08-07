#include<stdio.h>
# include<bits/stdc++.h>
using namespace std;
void inti(int *f,int n)
{
	srand((int )time(NULL));
	for(int i=0;i<n;i++)
		f[i]=(rand()%20000);
}
void merge(int f[],int l,int ll,int r,int rr,int p[])
{
	int i=l,j=l;
	while(l<=ll&&r<=rr)
	{
		if(f[l]<f[r])
		p[i++]=f[l++];
		else
		p[i++]=f[r++]; 
	}
	while(r<=rr) p[i++]=f[r++];
	
	while(l<=ll) p[i++]=f[l++];
	
	for(;j<i;) { f[j]=p[j];j++;}
}
void mersort(int f[],int l,int r,int p[])
{
	int k=(l+r)/2;
	if(l<r)
	{
		mersort(f,l,k,p);
		mersort(f,k+1,r,p);
		merge(f,l,k,k+1,r,p);
	}
}
void dis(int f[],int n)
{
	for(int i=0;i<n;i++)
	cout<<f[i]<<"  ";
	cout<<endl;
}
int f[100000000],p[100000000];
int main()
{
	int n;
	clock_t start,finish;
	double waste;
	cin>>n;
	inti(f,n);
	//dis(f,n);
	start=clock();
	mersort(f,0,n-1,p);
	finish=clock();
	waste=(double)(finish-start)/CLOCKS_PER_SEC;
//	dis(f,n);
	cout<<"waste :"<<waste<<endl;
	return 0;
}
