#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int i,j,n,avr=0;
    int f[200];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>f[i];
        avr+=f[i];
    }
    avr/=n;
    int ans=0;
    for(i=0;i<n;i++)
        if(f[i]!=avr)
        {
            f[i+1]+=f[i]-avr;
            ans++;
        }
    cout<<ans<<endl;
    return 0;
}
