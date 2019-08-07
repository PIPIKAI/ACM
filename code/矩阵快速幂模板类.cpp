#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000;
int c[N][N];
void multi(int a[][N],int b[][N],int n)// æÿ’Û≥À∑®
{
    memset(c,0,sizeof c);
    for(int i=0;i<n;i++)
        for(int k=0;k<n;k++)
            if(a[i][k])
                for(int j=0;j<n;j++)
                    c[i][j]+=a[i][k]*b[k][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j]=c[i][j];
}
int s[N][N];
void qpow(int a[][N],int n)
{
    memset(s,0,sizeof s);
    for(int i=0;i<N;i++) s[i][i]=1;
    while(n)
    {
        if(1&n)
            multi(s,a,n); // s*=a
        multi(a,a,n); // a*=a;
        n>>=1;
    }
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
   int n,a[N][N],b[N][N];
   cin>>n;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        cin>>a[i][j];
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        cin>>b[i][j];
    multi(a,b,n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<a[i][j]<<" ";
        cout<<endl;
    }

   return 0;
}
