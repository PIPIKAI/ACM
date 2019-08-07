#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,flag;
    string s1,s2;
    while(cin>>n>>m)
    {
        cin>>s1>>s2;
        string c="*";
        int j=s1.find(c);
        if(s1[j]=='*')
        {
             string ts=s1.substr(0,j);
            string tts=s2.substr(0,j);

            if(ts==tts)
            {
                if(j==n-1)
                {
                    cout<<"YES"<<endl;
                }
                else{
                        if(m-j>=n-j-1)
                      {
                        int len=n-j-1;
                     ts=s1.substr(j+1,len);
                     tts=s2.substr(m-len,len);
                    //cout<<ts<<" "<<tts<<endl;
                    if(ts==tts)
                        cout<<"YES"<<endl;
                    else
                        cout<<"NO"<<endl;
                      }
                    else
                    {
                        cout<<"NO"<<endl;
                    }

                }

            }
            else
            {
                cout<<"NO"<<endl;
            }

        }
        else
        {
            if(s1==s2)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}


