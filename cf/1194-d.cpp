#include<iostream>
using namespace std;
int main() {
    int n, k, t;
    cin >> t;
    while(t--) cin >> n >> k, cout << (((k % 3) ? (n % 3) : (n % (k + 1) % 3 || !((n + 1) % (k + 1)))) ? "Alice\n" : "Bob\n");
}
