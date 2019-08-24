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
int f[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='.'){
            s.insert(s.begin()+i,'[');
            s.insert(s.begin()+i+2,']');
            i+=2;
        }
    }
    cout<<s<<endl;
    return 0;
}