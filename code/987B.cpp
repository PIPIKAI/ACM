#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    double a,b;
    cin>>a>>b;
    a=b*log(a)-a*log(b);
    cout<<(a>0?">":a<0?"<":"=");
    return 0;
}
