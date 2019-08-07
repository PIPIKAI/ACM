#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
#define N 100005
ll n;
ll q[N]={-1},w[N];/// ×ó¿í
int main()
{
    while(cin>>n,n)
    {
        int top=0;
        ll ans=0;
        for(int i=1;i<=n+1;i++)
        {
            ll t;
            if(i!=n+1)
                cin>>t;
            else
                t=0;
            if(t>q[top])
            {
                q[++top]=t;w[top]=1;
            }
            else
            {
                ll cnt=0;
                while(t<=q[top])
                {
                    ans=max(ans,(w[top]+cnt)*q[top]);
                    cnt+=w[top--];///ÓÒ¿í
                }
                q[++top]=t;
                w[top]=cnt+1;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
