#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int a=0,b=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        if(t==25) a++;
        else if(t==50) { a--,b++;}
		else if(t==100)
		{
			if(b>0)
			b--,a--;
			else
			a-=3;
		}
		if(a<0)
		return cout<<"NO"<<endl,0;
    }
    return cout<<"YES"<<endl,0;
}
