//#pragma comment(linker, "/STACK:1024000000,1024000000")
/*
题目意思：给一个长度为n的数列，求长度>= m 的子序列的平均值的最大值
解题步骤：
1. 我们来二分一个平均值，然后用原数列减去它 （难点,数列的大小范围为0～2000）
2. 我们用前缀和保存起来
3. 此时只有n-m+1 种情况了，用一个双指针，只要用当前的 sum[j] -minv（最小值的前缀和）
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e5+7;
const int inf = 0x3f3f3f3f;
int n,m,f[maxn];
double sum[maxn];
bool check(double vag){
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+f[i]-vag;
	}
	double minv=0;
	for(int i=0,j=m;j<=n;i++,j++){
		minv=min(minv,sum[i]);
		if(sum[j]-minv>0){
			return true;
		} 
	}
	return false;
}
int main(int argc, char * argv[]) 
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>f[i];
    }
    double l=1,r=2000;
    while(r-l > 1e-5){
    	double mid=(l+r)/2;
    	if(check(mid)) l=mid;
    	else r = mid;
    }
    cout<< int(r*1000)<<endl;
    return 0;
}