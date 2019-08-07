#include<bits/stdc++.h>
using namespace std;
char ch[28];
void init()
{
	for(int i=0;i<26;i++)
	{
	int temp=('A'+i-5);
	if(temp<'A')
	ch[i]=1+'Z'-'A'+temp;
	else
	ch[i]=temp;
	}
}
int main()
{
  init();
  string start="START",en="END",endd="ENDOFINPUT",s;
  while(cin>>s)
  {
  string b;
  	if(s==start)
  	{
  		getchar();
  		getline(cin,b);
  		cin>>s;
  	}
  	if(s==endd)
  	break;
  	if(s==en)
  	{
  		for(int i=0;i<b.length();i++)
  		{
  			if(b[i]>='A'&&b[i]<='Z')
  			{
  				int c=b[i]-'A';
  				cout<<ch[c];
			  }
  			else
  			cout<<b[i];
		  }
		  cout<<endl;
	  }

  }
    return 0;
}
