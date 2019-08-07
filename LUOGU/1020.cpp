#include<bits/stdc++.h>
#define mem(x,y) memset(x,y,sizeof(x))
#define LL long long
#define inf 0x3f3f3f3f
#define pt printf
using namespace std;
int intread() {int x;scanf("%d",&x);return x;}
int a[100005],f[100005],l[100005];
struct cmp{bool operator()(int a,int b){return a>b;}};
int main()
{
    ios::sync_with_stdio(false);
    int n=1;
    while(cin>>a[n])
        {
            n++;
        }
    n-=1;
    int cc=1,cnt=1;
    l[1]=f[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        if(l[cnt]>=a[i])
            l[++cnt]=a[i];
        else
            l[upper_bound(l+1,l+cnt+1,a[i],cmp())-l]=a[i];

        if(f[cc]<a[i])
            f[++cc]=a[i];
        else
            f[lower_bound(f+1,f+cc+1,a[i])-f]=a[i];
    }
    cout<<cnt<<endl<<cc;
    return 0;
}
