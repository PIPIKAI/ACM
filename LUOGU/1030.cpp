#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void recover(string x,string y)
{
    if(x.size()<=0)
        return ;
    int i,r=y.length();
    char c=y[r-1];
    cout<<c;
    int k=x.find(c);
    recover(x.substr(0,k),y.substr(0,k));
    recover(x.substr(k+1),y.substr(k,x.size()-k-1));
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);string x,y;
   cin>>x>>y;
  recover(x,y);
   return 0;
}



