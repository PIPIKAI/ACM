#include<bits/stdc++.h>
using namespace std;
int f[100021],top=0,n;
int main()
{
    cin>>n;
    for(int t,i=0;i<n;i++){
        cin>>t;
        if(i==0 || f[top-1]<t)
        f[top++]=t;
        else{
            int j=lower_bound(f,f+top,t)-f;
            f[j]=t;
        }
    }
    cout<<top<<endl;
    return 0;
}
