#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
    return x%y ?  gcd(y,x%y) : y;
}
int main(){
    int ca=0,t,a,n,b,m;
    cin>>t;
    while(t--){
        ca++;
        a=b=m=0;
        cin>>n;
        for(int i=0,t;i<n;i++){
            cin>>t;
            t> 0 ? a+=t,m++ : b-=t;
        }
        cout<<"Case "<<ca<<": ";
        if(m){
            int k=gcd(a+b,m);
            cout<<(int)(a+b)/k<<"/"<<(m/k)<<endl;
        }
        else{
            cout<<"inf"<<endl;
        }
    }
    return 0;
}