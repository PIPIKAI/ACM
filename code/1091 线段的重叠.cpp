#include<iostream>
#include<algorithm>
using namespace std;
int max(int a,int b)
{
    return a>b?a:b;
}
int min(int a,int b)
{
    return a<b?a:b;
}
bool cmp(int *a,int *b)
{
    if(a[0]==b[0])
        return a[1]<b[1];
    return a[0]<b[0];
}
int main()
{
    int maxl=0,i,j,n;
    cin>>n;
    int **f = new int*[50050];
    for(i=0;i<n;i++)
    {
        f[i]=new int [2];
        cin>>f[i][0]>>f[i][1];
    }

    sort(f,f+n,cmp);
    int k=f[0][1];

    for(i=1;i<n;i++)
    {
        if(f[i][1]>=k)
        {
            maxl=max(maxl,k-f[i][0]);
            k=f[i][1];
        }
        else
            maxl=max(maxl,f[i][1]-f[i][0]);
    }

    cout<<maxl;
    return 0;
}
