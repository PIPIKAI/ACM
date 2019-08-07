#include<iostream>
#include<algorithm>
using namespace std;
typedef struct
{
    int x,y;
}node;
bool cmp(node a,node b)
{
    if(a.x==b.x)
    return a.y<b.y;
    else
    return a.x<b.x;
}
int main()
{
    int n,ans=0;
    cin>>n;
    node f[n];
    int s[60000];
    for(int i=0;i<n;i++)
    {
        int ta,tb;
        cin>>ta>>tb;
        s[i]=f[i].x=ta-tb;
        f[i].y=ta+tb;
    }
    sort(f,f+n,cmp);
    sort(s,s+n);
    for(int i=0;i<n;i++)
        {
            int j=lower_bound(s+i,s+n,f[i].y+1)-s;
            if(f[j].x>f[i].y)
                ans+=(n-j);
        }
cout<<ans<<endl;
        return 0;

}

