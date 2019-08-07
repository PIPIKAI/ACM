#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double x[1000001],y[1000001];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    double ix,iy,mx,my;
    int n;
    while(cin>>n,n!=0)
    {
        for(int i=0;i<n;i++)
        {
            cin>>x[i]>>y[i];
        }
        sort(x,x+n);sort(y,y+n);
        printf("%.2lf %.2lf\n",x[(n+1)>>1],y[(n+1)>>1]);
    }
    return 0;
}
