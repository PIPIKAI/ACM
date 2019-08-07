#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[1050];
void creat(int l,int r)
{
    if(l<r)
    {
        creat(l,(l+r)>>1);
        creat((l+r+1)>>1,r);
    }
     int B=1,I=1;
     for(int i=l;i<=r;i++)
     {
         if(s[i]=='1')
            B=0;
         else if(s[i]=='0')
            I=0;
     }
    if(B)
        cout<<"B";
    else if(I)
        cout<<"I";
    else
        cout<<"F";
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
   int n;
	cin>>n>>s;
	creat(0,(1<<n)-1);
   return 0;
}
