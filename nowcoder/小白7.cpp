#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
    double l,k,a,b;
    scanf("%lf%lf%lf%lf",&l,&k,&a,&b);
        double  ans1=l/a,ans2;
        bool flag=0;
            for(int i=1;i<=l/a;i++)
            {
                if(k<=i*a-i*b)
                {
                    if(l/b>i*2)
                    {
                        ans2=i*2;
                        flag=1;
                        break;
                    }

                }
            }
        if(!flag)
        ans2=l/b;
        printf("%.2lf\n",ans2-ans1);

   return 0;
}

