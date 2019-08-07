#include<bits/stdc++.h>
#define mem(x,y) memset(x,y,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
#define pt printf
using namespace std;
int read() {int x;scanf("%d",&x);return x;}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int t;
    t= read();
    while(t--)
    {
        priority_queue<int > q;
        int n;n=read();
        int ans=0,dd=0;
        for(int i=0;i<n;i++)
        {
            int x;x=read();
            q.push(-x);
            q.push(-x);
            if(x+q.top()>0)
                dd++;
            ans+=x+q.top();
            //cout<<ans<<endl;
            q.pop();
        }
        pt("%d %d\n",ans,dd*2);
    }
    return 0;
}
