#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
#define Max(x,y) y>x?x=y:x=x
ll n,m,k,a,b,c;
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    string s;
    while(t--)
    {
       cin>>s;
       int a=0,b=0,ans=0,c=0;
       bool flag=0;
       for(int i=0;i<s.size();i++){
        if(s[i]=='A'){
            a++;
        }
        else if(s[i]=='B'){
            b++;
        }
        else if(s[i]=='?'){
            c++;
        }
            if((a>=11||b>=11) && flag==0){
                ans++;
                a=b=0;
            }
             if(a==10&&b==10&&flag==0){
                flag=1;
            }
             if(flag && abs(a-b)>=2){
                ans++;
                flag=0;
                a=b=0;
            }
            if(flag==0&&(a+c>=11 || b+c>=11)){
                a=b=0;
                c=0;
                ans++;
            }
             if(flag && (c+abs(a-b))>=2){
                b=a=0;
                c-=2;
                ans++;
                flag=0;
            }
    }
            if((a>=11||b>=11) && flag==0){
                ans++;
                a=b=0;
            }
             if(a==10&&b==10&&flag==0){
                flag=1;
            }
             if(flag && abs(a-b)>=2){
                ans++;
                flag=0;
                a=b=0;
            }
            if(flag==0&&(a+c>=11 || b+c>=11)){
                a=b=0;
                c=0;
                ans++;
            }
             if(flag && (c+abs(a-b))>=2){
                b=a=0;
                c-=2;
                ans++;
                flag=0;
            }
    cout<<ans<<endl;
    }
    return 0;
}
/**
???????????????????????????????????????????????????????
*/
