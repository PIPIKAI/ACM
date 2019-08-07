#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
typedef struct{
    int x,y;
}cc;
inline bool cmp(cc a,cc b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;

}
int main()
{

    int i,j,n,ans=0;
    while(cin>>n)
    {
        cc f[2005];
        for(i=0;i<n;i++)
        {
            cin>>f[i].x>>f[i].y;
            if(f[i].x>f[i].y)
                swap(f[i].x,f[i].y);
        }
        sort(f,f+n,cmp);

        int a=f[0].y;
        for(i=1;i<n;i++)
        {
            if(f[i].x<a)
            {
            ans++;a=min(a,f[i].y);
            }
            else
                a=f[i].y;


        }
    cout<<n-ans<<endl;
    }

    return 0;
}
