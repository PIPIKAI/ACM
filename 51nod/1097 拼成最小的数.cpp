#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
string f[10050];
bool cmp(string a,string b){
    return a+b<b+a;
}
string ans;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>f[i];
    }
    sort(f,f+n,cmp);
    for(int i=0;i<n;i++){
        ans+=f[i];
    }
    for(int i=0;i<ans.size();i+=1000){
        cout<<ans.substr(i,1000)<<endl;
    }
    return 0;
}
