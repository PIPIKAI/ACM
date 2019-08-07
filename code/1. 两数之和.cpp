#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char str[1005];
    int i,j,z;
    cin>>str;
    int len=strlen(str);
    int a=0,b=0;
    int maxl=0;
    for( i=1;i<len-1;i++)
    {
        for( j=len-2;j>i;j--)
        {
            if(str[j]==str[i])
            {
                int flag=1;
                for( z=i;z<(j+i-1)/2;z++)
                {
                    if(str[z]!=str[j-z-1])
                    {
                        flag=0;
                         break;
                    }
                }
                if(flag)
                {
                   // cout<<"i="<<i<<endl;
                        if(maxl<(j-i))
                    {

                        maxl=j-i;
                        a=i,b=j;
                    }
                }

            }
        }
    }
    cout<<'"';
    for(int i=a;i<=b;i++)
        cout<<str[i];
    cout<<'"';
    return 0;
}
