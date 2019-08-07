#include<bits/stdc++.h>
using namespace std;
string add(string s,string f)
{
	string sum;
	int len= max(s.length(),f.length());
    for(int i=s.length();i<len;i++)
    s="0"+s;
    for(int i=f.length();i<len;i++)
    f="0"+f;
    int wei=0,temp;
   	for(int i=len-1;i>=0;i--)
   	{
   		temp=f[i]+s[i]-'0'-'0'+wei;
   		 wei=temp/10;
   		temp%=10;
   		sum=char(temp+'0')+sum;
	}
	if(wei!=0)
		sum=char(wei+'0')+sum;
	return sum;
}
int main()
{
    int n;
    cin>>n;       
    while(n--)
    {
	    string s="0",f;
    	while(cin>>f)
    	{
    		if(f=="0") 
    		break;
			else
    		s=add(s,f);
		}
		cout<<s<<endl;
        if(n>0) cout<<endl;
    }
    return 0;
}
