#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
int a,b=99999;
void  solve(int n,int step)
{
    while(1)
    {
        int t=sqrt(n);
        if(n==t*t)
        {
            step++;
            n=t;
        }
        else
        {
            int flag=1;
            for(int i=sqrt(n)-1;i*i>1;i--)
            {
                if(n%(i*i)==0)
                {
                    cout<<n<<"  "<<i*i<<endl;
                    flag=0;
                    n=i*(n/(i*i));
                    step+=2;
                    break;
                }
            }
            if(flag)
            {
                break;
            }
        }
    }
    cout<<n<<" "<<step<<endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    solve(n,0);
    return 0;
}
