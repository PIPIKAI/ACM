/* 
 * Author: kiappk
 * Time: 2020-07-10 12:13:20
**/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<cstring>
#define mem(x,y) memset(x, y, sizeof(x))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1e5+7;
const int inf = 0x3f3f3f3f;
int n,m,ans;
pair<int,int> f[maxn];
int main(int argc, char * argv[]) 
{
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>f[i].first>>f[i].second;
    }
    cin>>m;
    for(int i=0;i<n;i++){
        if(m>=f[i].first&&m<=f[i].second){
            ans=n-i;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}