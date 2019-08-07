#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
void read(int &x){
	char ch = getchar();x = 0;
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >='0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
int main()
{
	while(~scanf("%d%d",&n,&q))
    {
        list <int >f[n+10];
        for(int i=0;i<q;i++)
        {
            int ss, t,u,v,w;
            read(t);
            if(t==1)
            {
                read(u);
                read(w);
                read(ss);
                if(w)
                    f[u].push_back(ss);
                else
                    f[u].push_front(ss);
            }
            else if(t==2)
            {
                read(u);
                read(w);
                if(f[u].size()==0)
                    cout<<"-1"<<endl;
                else
                {
                    if(w)
                    {
                        cout<<f[u].back()<<endl;
                        f[u].pop_back();
                    }
                    else
                    {
                         cout<<f[u].front()<<endl;
                        f[u].pop_front();
                    }
                }

            }
            else if(t==3)
            {
                read(u);
                read(v);
                read(w);
                if(w)
                {
                     while(!f[v].empty())
                     {
                         f[u].push_back(f[v].back());
                         f[v].pop_back();
                     }
                }
                else
                {
                    while(!f[v].empty())
                     {
                         f[u].push_back(f[v].front());
                         f[v].pop_front();
                     }
                }
            }
        }
    }
   return 0;
}

