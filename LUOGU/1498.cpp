#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[1050]={1};
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
    (cin>>n);
       {
            for(int i=0;i<1<<n;++i){
        for(int j=1;j<(1<<n)-i;++j)cout<<" ";
        for(int j=i;j>=0;--j)a[j]^=a[j-1];
        if(!(i%2))for(int j=0;j<=i;++j)cout<<(a[j]?"/\\":"  ");
        else for(int j=0;j<=i;j+=2)cout<<(a[j]?"/__\\":"    ");
        cout<<endl;
        }
       }

   return 0;
}
