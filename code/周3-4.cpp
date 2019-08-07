#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
ll f[50],n;
int main()
{
    std::ios::sync_with_stdio(false);
    f[0]=0;
    f[1]=0;
    f[2]=3;
    int cnt=1;
    for(int i=4;i<=50;i++)
    {
        if(i%2==0)
        {
            f[i]=f[i/2]*f[i/2]+pow(3,cnt);cnt++;
        }
    }
	while(cin>>n,n!=-1)
    {
        cout<<f[n]<<endl;
    }
	return 0;
}
