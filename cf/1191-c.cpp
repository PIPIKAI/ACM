#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;

    while(cin>>n>>k){
        int x=0;
        for(int t,i=0;i<n;i++){
            cin>>t;
            x^=t;
        }
         x==0 ? cout<<"Yes"<<endl : cout<<"No" <<endl;
    }
    return 0;
}
