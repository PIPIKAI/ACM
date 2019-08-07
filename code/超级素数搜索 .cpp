#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;
int ispr(ll t)
{
    if(t==0||t==1)
        return 0;
    for(ll i=2;i<=sqrt(t);i++)
        if(t%i==0)
        return 0;
    return 1;
}
int main()
{
    ll i,n,s=1,sum=0;
    ll maxn=0;
    cin>>n;
    while(n>0)
    {
        n--;
        s*=10;

    }
    for(i=s/10;i<s;i++)
    {
        ll t=i;

        if(i>10)
        {
            if(ispr(i))
                {
                    int flag=0;
                    while(1)
                    {

                        int w=1;
                        ll a=t;
                        while(a>0)
                        {
                            if(a!=0&&a%10==0)
                                flag=1;
                            a/=10;

                            w*=10;
                        }
                        if(flag)
                            break;
                        t=t%(w/10);
                        if(t<10)
                        {
                            if(ispr(t))
                        {
                          //  cout<<i<<endl;
                            sum++;
                            maxn=max(maxn,i);
                        }
                        break;
                        }
                        if(ispr(t))
                            continue;
                        else
                            break;
                    }
                }
        }
        else
            if(ispr(i))
            {
                sum++;
                maxn=max(maxn,i);
            }
    }
    cout<<sum<<endl<<maxn<<endl;
    return 0;
}
