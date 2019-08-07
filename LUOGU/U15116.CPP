#include<bits/stdc++.h>
#define pi   3.1415926535897932384
using namespace std;
int main()
{
    int n,a=0,b=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<s.length();j++)
        {
            if('s'==s[j])
                a++;
            if('c'==s[j])
                b++;
        }
    }
    double s;
    if(a>b)
    {
        int k=a-b;
         s=k*1.0*cos(pi/7.0);
    }
    else
    {
        int k=b-a;
         s=k*1.0*cos(pi/7.0);
    }
    int ans=min(a,b)+s;
    printf("%d\n",ans);
    return 0;
}
