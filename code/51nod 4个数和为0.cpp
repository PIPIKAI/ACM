#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[1001];
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
   int  n;
	cin>>n;
	for(int i=0;i<n;i++)
    {
        cin>>f[i];
    }
    sort(f,f+n);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int t=-f[i]-f[j];
            int l=j+1,r=n-1;
            while(l<r)
            {
                if(f[l]+f[r]>t)
                    r--;
                else if(f[l]+f[r]<t)
                    l++;
                else
                    return cout<<"Yes"<<endl,0;
            }
        }
    }
    cout<<"No"<<endl;
   return 0;
}
