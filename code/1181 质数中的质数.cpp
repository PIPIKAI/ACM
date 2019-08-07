#include<iostream>
typedef long long ll;
using namespace std;
#define maxn 1000003
ll f[maxn],v[maxn];
void in()
{
    int c=1,i,j;
    f[1]=1;
    for( i=2;i<maxn;i++)
    {
        if(!f[i])
            for(j=2;i*j<=maxn;j++)
            f[i*j]=1;
    }
    for(i=1;i<maxn;i++)
        if(!f[i])
        v[c++]=i;
}
int main()
{
    in();
    int n;
    cin>>n;

        for(int i=n;;i++)
        if(!f[i])
        {
            for(int j=1;;j++)
                if(i==v[j])
                {
                    if(!f[j])
                    {
                    cout<<i<<endl;
                    return 0;
                    }
                    else
                        break;
                }
        }

    return 0;
}
