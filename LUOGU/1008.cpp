#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int result(int f[])
{
    int a=0,b=0,c=0;
    for(int i=0;i<3;i++) a=f[i]+10*a;
   for(int i=3;i<6;i++) b=f[i]+10*b;
   for(int i=6;i<9;i++) c=f[i]+10*c;
   if(b/a==2&&b%a==0&&c/a==3&&c%a==0)
   return 1;
   return 0;
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	int f[]={1,9,2,3,8,4,5,7,6};
	do{
        if(result( f ))
        {
            for(int i=0;i<9;i++)
            {
                cout<<f[i];
                if(i==2||i==5)
                    cout<<' ';
            }cout<<endl;
        }

	}while(next_permutation(f,f+9));
   return 0;
}
