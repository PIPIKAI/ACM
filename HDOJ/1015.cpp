#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int tar,flag;
int vis[50];
char  a[7];
string s;
bool cmp(const char a,const char b)
{
	return a>b;
}
void dfs(int step,int sum)
{
	if(step==5)
	{
		if(sum==tar)
        {
            a[5]='\0';
            cout<<a<<endl;
            flag=1;
        }
		return ;
	}
	int temp;
	if(0==step%2)
	temp=1;
	else
	temp=-1;
	if(flag)
        return ;
	for(int i=0;i<s.length();i++)
	{
		if(!vis[i])
		{
			int x=s[i]-'A'+1;
			vis[i]=1;
			a[step]=s[i];
			dfs(step+1,sum+temp*pow(x,step+1));
			vis[i]=0;
		}
	}
}
int main()
{

	while(cin>>tar>>s,tar!=0||s!="END")
	{
	    flag=0;
		memset(vis,0,sizeof vis);
		sort(s.begin(),s.end(),cmp);
		dfs(0,0);
		if(!flag)
		cout<<"no solution"<<endl;
	}
	return 0;
}
