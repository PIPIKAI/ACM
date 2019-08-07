#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int f[25],k,flag=0,p;
bool cmp(int a,int b)
{
    return a<b;//½µÐò
}
void dfs(int n)
{
    if(n<0)
        return ;
    if(p-f[n]>0)
    {
        //cout<<p<<" -"<<f[n]<<endl;
        p=p-f[n];
        dfs(n-1);
    }

    else if(p-f[n]==0)
    {
        flag=1;
        return ;
    }

    else
    {
        dfs(n-1);
        p=k;
        dfs(n-1);
    }

}
int main()
{
    int n,i,j,sum=0;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>f[i];

        cin>>k;
    sort(f,f+n,cmp);
    p=k;
    for(i=n-1;i>=0;i--)
    {
        dfs(i);
    }

   if(flag==1)
    cout<<"Of course,I can!";
   else
    cout<<"Sorry,I can't!";
    return 0;
}

