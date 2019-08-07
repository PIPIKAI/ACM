#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[150001][2];
int gcd(int a,int b)
{
    return b>0? gcd( b , a%b ) : a;
}
int cc[28]={0};
int n;
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
   cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>f[i][0]>>f[i][1];
    }
    queue<int > q;

    for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                int s=(f[0][j],f[1][k]);
                if(s!=1&&)
                    q.push(s);
            }
        }

    for(int i=1;i<n;i++)
    {
        if(q.empty())
        {
            flag=0;
            break;
        }
        while(!q.empty)
        {
            int t=q.front();
            q.pop();
            int ss=gcd(t,f[i][0]);
            if(ss!=1)
                q.push(ss);
        }

    }
    if(flag)
        cout<<q.front()<<endl;
    else
        cout<<"-1"<<endl;
   return 0;
}

