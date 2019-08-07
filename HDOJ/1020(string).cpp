#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   ios::sync_with_stdio(false);
   int T_T;
	cin>>T_T;
    while(T_T--)
    {
        char s[10005];
        cin>>s;
        int len =strlen(s);
        int t=1;
        for(int i=1;i<=len;i++)
        {
            if(s[i-1]==s[i])
            {
                t++;
            }
            else
            {
                if(t<=1)
                    cout<<s[i-1];
                else
                    cout<<t<<s[i-1];
                    t=1;
            }

        }
        cout<<endl;
    }
   return 0;
}

