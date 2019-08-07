#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
int n,m,p;
int main()
{
    std::ios::sync_with_stdio(false);
    int ca=0;
    cin>>p;
    for(int i=0;i<p;i++)
    {
        ca=0;
        while(cin>>n>>m,n!=0||m!=0)
        {
            int ans=0;
            ca++;
            for(int i= 1;i< n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    if((i*i+j*j+m)%(i*j)==0)
                        ans++;
                }
            }
            cout<<"Case "<<ca<<": "<<ans<<endl;
        }
        if(i<p-1)
            cout<<endl;
    }

    return 0;
}
