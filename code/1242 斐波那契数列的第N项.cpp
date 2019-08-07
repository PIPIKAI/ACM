#include<iostream>
#include<cstring>
#include<vector>
using namespce std;
typedef vector <int>  vec;
typedef vector<vec> mat;
typedef long long ll;
const int mod=1000000009;
mat chen(mat a,mat b)
{
    int i,j,k;
    mat k(a.size,vec(b.size()));
    for(i=0;i<a.size();i++)
    {
        for(j=0;j<b.size();j++)
        {
            for(k=0;k<b[i].size();k++)
            {
                k[i][j]+=a[k]*b[j][j]
            }
        }
    }
}
void mi(mat f,n)
{
    mat s(2,vec(2));
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
        if(i==j)
        s[i][j]=1;
    while(n>0)
    {
        if(n%1)
            s=chen(f,s)
        f=chen(f,f);
    }
    cout<<s[1][1];
}
void solve()
{
    ll n;
    mat f(2,vec(2));
    f[0][0]=1;
    f[0][1]=1;
    f[1][0]=1;
    f[1][1]=0;
    cin>>n;
    mi(f,n);
}
int main()
{
    solve();
    return 0;
}
