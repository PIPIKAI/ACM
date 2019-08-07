#include <cstdio>
#include <algorithm>
using namespace std;

const int N=100000007;

int visit[N/32+50];
unsigned int data[5800000];
int prime[5800000],np=0;

void Prime ()   //ɸ����,�����0��ʼ
{
	prime[0]=data[0]=2;
	np=1;
	for (int i=3;i<N;i+=2)   //ɨ��������
		if (!(visit[i/32] & (1 << ((i/2)%16))))
		{
			prime[np]=i;
			data[np]=data[np-1]*i;  //Ԥ����
			np++;
			for (int j=3*i;j<N;j+=2*i)  //�ĳ�i*i�ᳬint��Χ
				visit[j/32] |= (1 << ((j/2)%16));
		}
}

unsigned int Deal (int n)
{
	int p=upper_bound (prime, prime+np, n)-prime-1;  //��λ��nС�ĵ�һ������
	unsigned int ans = data[p];
	for (int i=0; i<np && prime[i]*prime[i] <= n; i++)//��ʱprime[i]���10^4
	{//ɨ������������������
		int mul = prime[i];
		int tmp = prime[i] * prime[i];
		while (tmp/mul == prime[i] && tmp<=n) //��ֹintԽ��
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
