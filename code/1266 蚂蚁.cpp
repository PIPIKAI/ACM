#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    int f[60000];
    int n;
    int l;
    ll maxl=-1,minl=0;
    cin>>n>>l;
    int mid=l/2;
    for(int i=0;i<n;i++)
        cin>>f[i];
    sort(f,f+n);
    int j=lower_bound(f,f+n,mid)-f;
    //cout<<"j= "<<j<<endl;
    minl=max(f[j-1],l-f[j]);
    maxl=max(l-f[0],f[n-1]);
    cout<<minl<<" "<<maxl;
    return 0;
}
