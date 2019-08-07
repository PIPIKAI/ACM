#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n;
    while(cin>>n,n)
    {
        int ans=0;
        int f[1050],k[1050];
        for(int i=0;i<n;i++ ) cin>>f[i];
        for(int i=0;i<n;i++ ) cin>>k[i];
        sort(k,k+n,cmp);sort(f,f+n,cmp);
        int tmin=n-1,tmax=0,kmin=n-1,kmax=0;
        while(tmin>=tmax)
        {
            if(f[tmax]>k[kmax])
            {
                tmax++,kmax++;
                ans++;
            }
            else if(f[tmax]<k[kmax])
            {
                tmin--,kmax++;
                ans--;
            }
            else if(f[tmax]==k[kmax])
            {
                if(f[tmin]>k[kmin])
                {
                    tmin--,kmin--;
                    ans++;
                }
                else if(f[tmin]<k[kmin])
                {
                    tmin--,kmax++;
                    ans--;
                }
                else if(f[tmin]==k[kmin])
                {
                    if(f[tmin]==k[kmax])
                        break;
                    else if(f[tmin]<k[kmax])
                    {
                        tmin--,kmax++;
                        ans--;
                    }
                }

            }
        }
        cout<<ans*200<<endl;
    }
    return 0;

}
