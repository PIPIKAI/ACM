#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int f[100002];
int main()
{
    int n,ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
        scanf("%d",f+i);
    sort(f,f+n);
    int i,j;
    for(i=0,j=n-1;i<=j;)
    {
        if(i!=j)
        {
            if(f[j]+f[i]>4)
        {
            ans++;
            j--;
        }
        else if(f[j]+f[i]<4)
        {
            f[j]+=f[i];
            i++;
        }
        else if(f[j]+f[i]==4)
        {
            j--;
            i++;
            ans++;
        }
        }
        else
        {
            ans++;
            break;
        }

    }
    cout<<ans<<endl;
    return 0;
}
