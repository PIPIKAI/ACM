#include<iostream>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int f[3005][3];
ll n;
void fine(int a,int i)
{
    if(f[a][1]!=0)
    {
        f[i][2]++;
        f[i][1]=f[a][1];
        fine(f[a][1],i);
    }
}
void solve()
{
    int ans=-1;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        f[a][1]=b;
    }
    for(int i=1;i<=n;i++)
    {
        fine(f[i][1],i);
    }
    if(f[0][1]==f[0][2])
    {
        if(f[1][2]==f[2][2])
            ans=1;
        else if(f[1][2]>f[2][2])
            ans=2;
        else
            ans=3;
    }
    else
    {

    }
     if(ans==1)
       {
           cout<<"You are my brother"<<endl;
        }
        else if(ans==2)
        {
            cout<<"You are my elder"<<endl;
        }
        else if(ans==3)
        {
            cout<<"You are my younger"<<endl;
        }
}
int main()
{
   while(cin>>n)
   {
       memset(f,0,sizeof(f));
        solve();

   }
    return 0;
}


