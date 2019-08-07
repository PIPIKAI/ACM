#include<bits/stdc++.h>
using namespace std;
const int maxn=999;
int f[maxn];
int main()
{
    int n;
    cin>>n;
    int a;
    for(int i=1;i<=n;i++){
        cin>>f[i];
    }
    a=f[1];
    double ans;
    sort(f+1,f+n+1);
    int j=lower_bound(f+1,f+n+1,a)-f;
    int r=n/20;
    if(n%20){
        r++;
    }
    //cout<<r<<" "<<j<<endl;
    if(r==1 || j==n){
        ans=1.0;
    }
    else if( n-j < r ){
        ans=0.00;
    }
    else{
        ans= (r-1)*1.0/(r*r);
        //cout<<ans<<endl;
    }
    cout<<fixed<<setprecision(5)<<ans<<endl;
    return 0;
}