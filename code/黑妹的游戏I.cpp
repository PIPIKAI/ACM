#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b,c,sum=0;
        cin>>a>>b>>c;
        a=max(a,b);
        a=max(a,c);
        cout<<a-3<<endl;
    }
    return 0;
}
