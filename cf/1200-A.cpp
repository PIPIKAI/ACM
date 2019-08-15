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
int f[20];
string s;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    char c;
    for(int i=0;i<n;i++){
        cin>>c;
        if(c>='0' && c<='9'){
            f[c-'0']=0;
        }
        else if(c=='L'){
            for(int j=0;j<10;j++){
                if(f[j]==0){
                    f[j]=1;
                    break;
                }
            }
        }
        else{
            for(int j=9;j>=0;j--){
                if(f[j]==0){
                    f[j]=1;
                    break;
                }
            }
        }
    }
    for(int i=0;i<10;i++){
        cout<<f[i];
    }
    return 0;
}