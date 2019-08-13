#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N], n;
bool jug()
{
    int cnt[3] = {0, 0, 0}, tot = 0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]%2 && b[i] == 2) return false;
        if(b[i] == 2)   cnt[2]++,   cnt[0]++;
        if(a[i] > 1 && b[i] == 1)   cnt[1]++,   cnt[0]++;
    }
    if(cnt[0]>1)    return false;
    if(cnt[1] == 1) {
        for(int i=1;i<=n;i++)
            if(b[i] == 1 && a[i] > 1)   tot ^= (a[i]%2?0:1);
            else    tot ^= a[i];
        return !(tot?1:0);
    }
    else if(cnt[2] == 1) {
        for(int i=1;i<=n;i++)
            if(b[i] != 2)
                tot ^= a[i];
        return !(tot?1:0);
    }
    else {
        for(int i=1;i<=n;i++)
            tot ^= a[i];
        return tot;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        printf("%s\n", jug() ? "Alice" : "Bob");
    }
}