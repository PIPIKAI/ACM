#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int cc[28]={0};
int n;
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
   cin>>n;
   int flag=0;
   if(n==1)
   {
       cout<<"Yes"<<endl;
       return 0;
   }
   else
   {
       for(int i=0;i<n;i++)
    {
        char c;
        cin>>c;
        cc[c-'a']++;
        if(cc[c-'a']>=2)
            flag=1;
    }
    if(flag)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
   }

   return 0;
}

