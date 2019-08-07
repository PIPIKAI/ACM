#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int vis[100002],w[100002];
map <string,int > f;
int deep;
int ans;
void ini()
{
    for(int i=0;i<=100000;i++)
        vis[i]=i,w[i]=1;
}
int find(int  x)
{
    while(vis[x]!=x)
        x=vis[x];
    return x;
}
int merge(int  a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b)
        return w[a];
    else
    {
        if(a>b)
        {
            vis[a]=b;
        }
        else
        {
            vis[b]=a;
        }
        int t=w[a]+w[b];
        w[a]=w[b]=t;
        return t;
    }

}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	int t;
	while(cin>>t)
    {
        while(t--)
        {
            ini();
            int n,ans=0,cnt=1;
            cin>>n;
            for(int i=0;i<n;i++)
            {
                string a,b;
                int x,y;
                cin>>a>>b;
                if(f[a]!=0)
                    x=f[a];
                else
                   x=f[a]=cnt,cnt++;
                 if(f[b]!=0)
                    y=f[b];
                 else
                    y=f[b]=cnt,cnt++;
                int ans=merge(x,y);
                cout<<ans<<endl;
            }
        }

    }
   return 0;
}
/*
1
4
Fred Barney
Barney Betty
Wile Wilma
Betty Wilma

*/
