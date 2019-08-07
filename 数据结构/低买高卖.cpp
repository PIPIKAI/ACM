#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue <int > q;
ll ans=0;
ll sum=0;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
       int t;
       cin>>t;
       q.push(-t);
       q.push(-t);
       ans+=t+q.top();
       cout<<"+ "<<t<<" + "<<q.top()<<endl;
       q.pop();
    }
        cout<<ans<<endl;
    return 0;
}
