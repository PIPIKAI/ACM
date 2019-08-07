#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
map<string ,int >vis;
struct node
{
    string s;
    ll sum;
};
string bb(ll a)
{
    string s;
    while(a!=0)
    {
        ll t=a%10;
        char c=t+'0';
        s=c+s;
        a/=10;
    }
    return s;
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	queue <node > q;
	node t;
	t.s+='1';
	t.sum=1;
	q.push(t);

	while(!q.empty())
    {
        t=q.front();
        q.pop();
        node nn;
        if(t.sum%n==0)
        {
            return cout<<t.s<<endl,0;
        }
        nn.s=t.s+'0';
        nn.sum=(t.sum*10)%n;
        string ss=bb(nn.sum);
        if(!vis[ss])
        {
            q.push(nn);
            vis[ss]=1;
        }
        nn.s=t.s+'1';
        nn.sum=(t.sum*10+1)%n;
        ss=bb(nn.sum);
        if(!vis[ss])
        {
            q.push(nn);
            vis[ss]=1;
        }
    }
   return 0;
}

