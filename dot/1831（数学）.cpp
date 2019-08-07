#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
int main()
{
    std::ios::sync_with_stdio(false);
    int ans=0,years;
    double s,t=INT_MIN;
    cin>>years>>s;
    while(abs(t-s)>=0.0001){
        ans++;
        t=ans + years + (ans-1)*(pow(2,years+1)-2);
    }
    cout<<ans<<endl;
    return 0;
}
/**
An=2*An-1 -1;
An - 1=2(An-1 -1)
(An - 1)/(An-1 -1) = 2
An - 1 = (A1 - 1)*2^(n-1)
An= (A1-1)*x^(n-1) + 1
Sn= A1+A2+....+An
Sn = A1 + .... + (A1-1)*x^(n-1) + 1 = A1 + n -1 + (A1-1) * (2*4*6....*2^(n-1) )
Sn = A1 + n - 1 + (A1 - 1) * (2^n - 2);
*/
