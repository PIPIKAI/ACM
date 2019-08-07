#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn = 1e6 + 7;
int n, heap_size;
int heap[maxn];
void put(int x) {
    int now, next;
    heap[++heap_size] = x;
    now = heap_size;
    while(now > 1) {
        next = now >> 1;
        if(heap[now] >= heap[next]) return ;
        swap(heap[now], heap[next]);
        now = next;
    }
}
int get() {
    return heap[1];
}
int del() {
    int now, next, res;
    res = heap[1];
    heap[1] = heap[heap_size--];
    now = 1;
    while(now * 2 <= heap_size) {
        next = now << 1;
        if(next < heap_size && heap[next + 1] < heap[next]) {
            next++;
        }
        if(heap[now] <= heap[next]) {
            return res;
        }
        swap(heap[now], heap[next]);
        now = next;
    }
    return res;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0, c, x; i < n; i++) {
        cin >> c;
        if(c == 1) {
            cin >> x;
            put(x);
        } else if(c == 2) {
            cout << get() << endl;
        } else {
            del();
        }
    }
    return 0;
}
