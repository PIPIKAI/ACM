#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
typedef long long ll;
ll f[10];
void init()
{
    for(int i=1;i<=9;i++)
        f[i]=i;
}
int main()
{
    ll n,ans=0;
    cin>>n;
    init();
    do
    {
        for(int i=1;i<=7;i++)
        {
            ll x=0;
            for(int c=1;c<=i;c++) x=x*10+f[c];

            for(int j=i+1;j<=8;j++)
            {
                ll y=0,z=0;
                for(int c=i+1;c<=j;c++) y=y*10+f[c];

                for(int k=j+1;k<=9;k++) z=z*10+f[k];
                //cout<<x<<" "<<y<<" "<<z<<endl;
                if(x*y-z==n)
                    ans++;
            }
        }

    }while(next_permutation(f+1,f+10));
    cout<<ans<<endl;
    return 0;
}
