/*求小于等于n的素数的个数*/
#include<stdio.h>
#include<string.h>
using namespace std;
const int maxn=1e4+7;
int n=maxn,prime[maxn];//存素数 
bool vis[maxn];//保证不做素数的倍数 
int check[maxn];
void eur(){
    int num=0;
    for(int i=2;i<=n;i++)
		{
			if(check[i]==0)
			prime[num++]=i;
			for(int j=i+i;j<=n;j+=i)        //素数的倍数全部标记
			{
				check[j]=1;
			}
		}

}
void ini(){
    int cnt=0;
    for(int i = 2; i <= n; i++)
    {
        if(!vis[i])//不是目前找到的素数的倍数 
        prime[cnt++] = i;//找到素数~ 
        for(int j = 0; j<cnt && i*prime[j]<=n; j++)
        {
            vis[i*prime[j]] = true;//找到的素数的倍数不访问 
            if(i % prime[j] == 0) break;//关键！！！！ 
        }
    }
    for (int i = 0; i < maxn; ++i)
    {
        if(!vis[i])
        printf("%d\n",i );
    }
}
int main()
{
    ini();
    int n, cnt = 0;
    
    printf("%d\n", cnt);
    return 0;
}