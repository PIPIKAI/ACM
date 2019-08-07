#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
int main()
{
    long long  n,f[200];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>f[i];
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
            if(f[j]>f[j+1])
            swap(f[j],f[j+1]);
    }
    cout<<n<<endl;
    for(int i=0;i<n;i++)
        cout<<f[i]<<endl;
    return 0;
}
