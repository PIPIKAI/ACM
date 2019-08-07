#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstring>
using namespace std;
long long  f[100005];
int main()
{
    memset(f,0,sizeof(f));
    long long n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>f[i];
    }
    sort(f,f+n);
    int c=1,flag=0;
     for(int i=0;i<=n-1;i++)
     {

         if(f[i]!=f[i+1])
         {
             if(c%2==1)
             {
                 if(flag==0)
                 {
                     cout<<f[i]<<" ";
                     flag++;
                 }
                 else
                 {
                     cout<<f[i]<<endl;
                     flag=0;
                 }
             }
             c=1;
         }
         else
            c++;

     }
    return 0;
}

