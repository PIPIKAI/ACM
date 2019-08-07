#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
int main()
{
    std::ios::sync_with_stdio(false);
    double r;
    cin>>r;
    int ans=0;
    for(int i=-sqrt(r);i<=sqrt(r);i++)
    {
        int j =sqrt(r- i*i );
        if(j==0)
            ans++;
        else if( i*i +j*j == r )

        ans+=2;
    }
    cout<<ans<<endl;
    return 0;
}
