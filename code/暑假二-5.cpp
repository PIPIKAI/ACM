#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;
using namespace std;
int f[2000];
int main()
{
    int n;
    while(cin>>n)
    {
        memset(f,0,sizeof(f));
        for(int i=0;i<n;i++)
            cin>>f[i];
        for(int i=0;i<n;i++)
        {
            if(f[i]%2)
                cout<<f[i]<<" ";
            else
                cout<<f[i]-1<<" ";
        }
        cout<<endl;
    }
    return 0;
}

