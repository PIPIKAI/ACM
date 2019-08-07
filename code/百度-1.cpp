#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[2000];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	int n;
	while(cin>>n)
    {
        int ans=0;
        for(int i=0;i<n;i++)
            cin>>f[i];
        sort(f,f+n,cmp);
        for(int i=0;i<n-2;i++)
        {
            int a,b,c;
            a=f[i],b=f[i+1],c=f[i+2];
            if(b+c>a)
                ans=max(ans,a+b+c);
        }
        if(ans!=0)
        cout<<ans<<endl;
        else
        cout<<"-1"<<endl;
    }
   return 0;
}
