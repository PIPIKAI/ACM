#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        while(n--)
        {
            string a,b="PERFECT";
        int i,flag;
        cin>>i;
        flag=i;
        for(;i>0;i--)
        {

            cin>>a;
            if(a==b)
                flag--;
        }
        if(!flag)
            cout<<"MILLION Master"<<endl;
        else
            cout<<"NAIVE Noob"<<endl;
        }
    }

    return 0;
}
