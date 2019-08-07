#include<bits/stdc++.h>
using namespace std;
int temp [200][200];
void mulit(int a[][200],int b[][200],int n)
{
    memset(temp,0,sizeof temp);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        for(int k=0;k<n;k++)
            temp[i][j]+=a[i][k]*b[k][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j]=temp[i][j];
}
int main()
{
    int a[200][200],b[200][200];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        cin>>a[i][j];
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        cin>>b[i][j];
    mulit(a,b,n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
