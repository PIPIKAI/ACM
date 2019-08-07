#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans;
int vis[11];
ll make(int i,int j)
{
    if(i>j)
        return 0;
    int t=vis[i];
    while(i<j)
    {
        i++;
        t=t*10+vis[i];
    }
    return t;
}
int main()
{
    //cout<<6
   ios::sync_with_stdio(false);cin.tie(0);
    while(cin>>n)
    {
        if(n==0)
            return cout<<"18"<<endl,0;
         ans=0;

    for(int i=1;i<=9;i++)
        vis[i]=i;
    do
    {
        int a,b,c;
        for(int i=1;i<9;i++)
        {
            for(int j=i;j<9;j++)
            {
                a=make(1,i);
                b=make(i+1,j);
                c=make(j+1,9);
                if(a==0||b==0||c==0)
                    continue;
                if(a*b-c==n||a-b*c==n)
                {
                    ans++;
                }

            }
        }
    }while(next_permutation(vis+1,vis+10));
    cout<<ans<<endl;
    }

   return 0;
}
