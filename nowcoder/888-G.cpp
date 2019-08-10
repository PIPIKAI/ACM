#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<cstring>
using namespace std;
#define Max(x,y) y>x?x=y:x=x
#define mem(a,b)  memset( a,b,sizeof a)
typedef long long ll;
const int inf=0x7fffffff;
const int maxn = 1e5+7;
int n,m;
string s;
int ans;
bool juge(string ts){
    int res=1;
    for(int i=1;i<ts.size();i++){
        if(ts[i]==ts[i-1]){
            res++;
        }
    }
    return res==3;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>s;
    int l=0,r=0;
    for(int i=0;i<s.size();){
        string ts=s.substr(i,3);
        if(juge(ts)){
            l=i-1,r=i+3;
            s.erase(s.begin()+i,s.begin()+r);
            cout<<s<<endl;
            i=max(i-3,0);
            ans++;
        }
        else{
            i++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
/**
AAVVDDFFFDVA
AAAAAAAAAAAA
 * */