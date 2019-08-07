#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	int n,m,q,f[1005],cnt=1;
	string s,t;
	cin>>n>>m>>q>>s>>t;
	for(int i=0;i<n;i++)
    {
        string ss=s.substr(i,m);
        if(t==ss)
            f[cnt++]=i+1;
    }
	for(int i=0;i<q;i++)
    {
        int l,r,ans=0;
        cin>>l>>r;
        for(int j=0;j<cnt;j++)
            if(l<=f[j]&&r>=f[j]+m-1)
                ans++;
        cout<<ans<<endl;
    }
   return 0;
}
