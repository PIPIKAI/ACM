#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstring>
using namespace std;
char k[8]={'A','B','C','D','E','F','G','H'};
char  ans[100000];
void ver(int len)
{
    char t;
    for(int i=0;i<len/2;i++)
    {
        t=ans[i];ans[i]=ans[len-1-i];ans[len-1-i]=t;
    }
    return ;
}
void f(long long n,long long b)
{

    int len=0;
    while(n>0)
          {
              int t=n%b;
              if(t<10)
              ans[len++]='0'+t;
              else
                ans[len++]=k[t-10];
            n/=b;
          }
          ver(len);
          cout<<ans<<endl;
}
using namespace std;
int main()
{
    long long  n,b;
    cin>>n>>b;
    if(n==0)
    {
        cout<<0<<endl;
        return 0;
    }
   f(n,b);
    return 0;
}

