#include<iostream>
using namespace std;
int v[100003];
int main()
{
    int n,top=0;
    cin>>n;
    int ans=n;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        if(b==1)
        {
            v[++top]=a;
        }
        else
           while(top>0)
           {
               if(a>v[top])
               {
                   top--;
                   ans--;
               }
               else
               {
                   ans--;
                   break;
               }
           }

    }
    cout<<ans<<endl;
    return 0;
}
