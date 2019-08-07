#include<iostream>
#include<algorithm>
using namespace std;
int f[200],n,maxl=1;
void dfs(int i,int len,int ch,int t)
{
    if(i>=n-1)
    {
        maxl=maxl>len?maxl:len;
        return ;
    }
        if(ch==f[i+1]-t)
        {
            len++;
            t=f[i+1];
        }

    dfs(i+1,len,ch,t);
}
int main()
{
    int i,j;
    cin>>n;
    for( i=0;i<n;i++)
        cin>>f[i];
    sort(f,f+n);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        dfs(0,1,f[j]-f[i],f[i]);
    }
    cout<<maxl;
    return 0;
}
