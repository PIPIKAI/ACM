#include<bits/stdc++.h>
using namespace std;
const int N = 1100000 + 5;
const int inf = 2147483647;

int cnt, len, ans = 0;
char s[N], ss[N * 2];
int p[N * 2];

void init() {
    len = strlen(s), cnt = 1;
    ss[0] = '!';
    ss[cnt] = '#';
    for(int i = 0; i < len; i++)
        ss[++cnt] = s[i], ss[++cnt] = '#';
}

void manacher() {
    int pos = 0, mx = 0;
    for(int i = 1; i <= cnt; i++) {
        if(i < mx) p[i] = min(p[pos * 2 - i], mx - i);
        else p[i] = 1;
        while(ss[i + p[i]] == ss[i - p[i]]) p[i]++;
        if(mx < i + p[i]) mx = i + p[i], pos = i;
        ans = max(ans, p[i] - 1);
    }
}

int main() {
    int n;
    scanf("%d%s", &n, s);
    init();
    manacher();
    if(ans > 1) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}
