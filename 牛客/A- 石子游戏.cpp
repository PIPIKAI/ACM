#include<bits/stdc++.h>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int ji=0,ou=0,t,k=0,n,m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t;
        if(t!=1){
            if(t&1==0) ou++;
            else ji++;
        }
        else k++;
    }
    int to= ou + ji*2;
    if(k==n) return cout<<"Bob"<<endl,0;
    if(to&1)cout<<"Bob"<<endl;
        else cout <<"Alice"<<endl;
    return 0;
}
