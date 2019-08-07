#include<bits/stdc++.h>
#define mem(x,y) memset(x,y,sizeof(x))
#define LL long long
#define inf 0x3f3f3f3f
#define pt printf
using namespace std;
int intread() {int x;scanf("%d",&x);return x;}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int x,y,s=0;
    stack<int > q;
    char c;
    while(cin>>c,c!='@')
    {
        switch(c)
        {
            case '+' : x=q.top();q.pop();y=q.top();q.pop();q.push(x+y);break;
            case '-' : x=q.top();q.pop();y=q.top();q.pop();q.push(y-x);break;
            case '*' : x=q.top();q.pop();y=q.top();q.pop();q.push(x*y);break;
            case '/' : x=q.top();q.pop();y=q.top();q.pop();q.push(y/x);break;
            case '.' : q.push(s);s=0;break;
            default : s=s*10+c-'0';break;
        }
    }
    cout<<q.top()<<endl;
    return 0;
}
