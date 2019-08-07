#include<iostream>
#include<algorithm>
using namespace std;
int f[1005];
int main()
{
    int n,sum,flag=1;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>f[i];
    sort(f,f+n);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            sum=f[i]+f[j];
            int k;
            k=lower_bound(f,f+n,0-sum)-f;
            if(f[k]+sum==0&&k>i&&k>j)
            {
                cout<<f[i]<<" "<<f[j]<<" "<<f[k]<<endl;
                flag=0;
            }

        }
    }
    if(flag)
        cout<<"No Solution"<<endl;
    return 0;
}
