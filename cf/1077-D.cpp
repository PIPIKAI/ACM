#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
map<ll,ll> f;
priority_queue<pair <ll ,ll > > q;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int t,i=0;i<n;i++){
        cin>>t;f[t]++;
    }
    for(int i=0;i<f.size();i++){
        if(f[i]){
            for(int j=1;j<=f[i];j++){
                q.push(make_pair(f[i]/j,i));
            }
        }
    }
    for(int i=0;i<k;i++){
        cout<<q.top().second<<" ";q.pop();
    }
    return 0;
}
