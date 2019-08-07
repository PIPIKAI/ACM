#include<bits/stdc++.h>
using namespace std;
long long reverse(long long x) {
        long long ans=0,f=1;
        if(x<0)
            x*=-1,f=-1;
        while(x)
        {
            ans = ans*10 + (x%10);
            if(ans>INT_MAX||ans*-1<INT_MIN)
                return 0;
            x/=10;
        }
        return f*ans;
}
int main()
{
    long long n;
    cin>>n;
    cout<<reverse(n)<<endl;
    return 0;
}
