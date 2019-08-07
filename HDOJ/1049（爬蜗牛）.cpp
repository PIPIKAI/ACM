#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,u,d;
    while(cin>>n>>u>>d,n!=0)
    {
        int i,t=n-u;	 
        for( i=0;i<n;i++)
        {
            if(i*(u-d)>=t)
                break;
        }
        cout<<2*i+1<<endl;
    }
    return 0;
}
