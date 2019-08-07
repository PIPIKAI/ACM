#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue <ll ,vector <ll >,greater <ll> >  q;//把小的放在头
ll n;
ll  sum=0;
int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;i++)
    {
        ll t;
        scanf("%lld",&t);
        q.push(t);
    }
    while(1)
     {
         ll v=q.top();
         q.pop();
         v+=q.top();
         sum+=v;
         q.pop();
         if(q.empty())
            break;
         q.push(v);
     }
    cout<<sum<<endl;
    return 0;
}
