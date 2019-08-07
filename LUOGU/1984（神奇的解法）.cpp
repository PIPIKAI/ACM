#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
double n, m;
int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    double cost = 0, t = (4200 * 100)*1.0 / n;
    for(int i=1;i<=n;i++){
        cost+=  t;
        t*=(1- 0.5/i);
    }
    cout <<fixed<<setprecision(2)<< cost << endl;
    return 0;
}
