#include <bits/stdc++.h>
using namespace std;
int main()
{
int i,a[100005] ;
int N ;
cin>>N;
for(int i=0;i<N;i++) cin>>a[i];
sort(a,a+N);
for(i=0; i<N; i++) printf("%d ", a[i]);
printf("\n");

return 0;
}
