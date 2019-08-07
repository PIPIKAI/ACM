#include <cstdio>
#include <algorithm>
using namespace std;

const int N=100000007;

int visit[N/32+50];
unsigned int data[5800000];
int prime[5800000],np=0;

void Prime ()   //筛素数,数组从0开始
{
	prime[0]=data[0]=2;
	np=1;
	for (int i=3;i<N;i+=2)   //扫所有奇数
		if (!(visit[i/32] & (1 << ((i/2)%16))))
		{
			prime[np]=i;
			data[np]=data[np-1]*i;  //预处理
			np++;
			for (int j=3*i;j<N;j+=2*i)  //改成i*i会超int范围
				visit[j/32] |= (1 << ((j/2)%16));
		}
}

unsigned int Deal (int n)
{
	int p=upper_bound (prime, prime+np, n)-prime-1;  //定位比n小的第一个素数
	unsigned int ans = data[p];
	for (int i=0; i<np && prime[i]*prime[i] <= n; i++)//此时prime[i]最多10^4
	{//扫所有素数的整数次幂
		int mul = prime[i];
		int tmp = prime[i] * prime[i];
		while (tmp/mul == prime[i] && tmp<=n) //防止int越界
		{
			tmp *= prime[i];
			mul *= prime[i];
		}
		ans *= (mul/prime[i]);
	}
	return ans;
}

int main ()
{
#ifdef ONLINE_JUDGE
#else
	freopen("read.txt","r",stdin);
#endif
	int T,n;
	scanf("%d",&T);
	Prime ();
	for (int Cas=1;Cas<=T;Cas++)
	{
		scanf ("%d",&n);
		printf ("Case %d: %u\n",Cas,Deal(n));
	}
	return 0;
}
