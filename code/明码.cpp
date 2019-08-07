#include<iostream>
#include<bitset>
using namespace std;
int main()
{
    //freopen("mm.txt","r",stdin);
    int n,m;
    int len;
    string temp;
    bitset<8> t;
        while(cin>>n>>m)
        {
            t=n;
            temp=t.to_string();
            for(int i=0;temp[i]!='\0';i++)
            {
                if(temp[i]=='0')
                    cout<<"  ";
                else
                    cout<<"¨€";
            }
            t=m;
            temp=t.to_string();
            for(int i=0;temp[i]!='\0';i++)
            {
                if(temp[i]=='0')
                    cout<<"  ";
                else
                    cout<<"¨€";
            }
            cout<<endl;
        }


    return 0;

}
