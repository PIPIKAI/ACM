#include <bits/stdc++.h>

using namespace std;
//long long mod = 1000000000+7;

long long pow(long long a, long long b, long long mod)
{
    stack<int> k;
    int j = 2048;
    int l = 1;
    int an = 1;
    while (b)
    {
        if (b >= j)
        {
            k.push(j);
            b -= j;
        }
        j /= 2;
    }
    while (!k.empty())
    {
        if (k.top() == l)
        {
            an = (an * a) % mod;
            k.pop();
        }
        a = (a * a) % mod;
        l *= 2;
    }

    return an;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    // freopen("path.in","r",stdin);
    //freopen("palindrome.out","w",stdout);
    string s, t;
    cin >> s >> t;
    int ns = s.size();
    int nt = t.size();
    int mx = 0;
    for (int u = 0; u < ns; ++u)
    {
        int f[ns + 1]{0};
        for (int i = u, o = 1; i < ns; ++i, ++o)
        {
            int y = 0;
            f[i]++;
            for (int j = 0; j < ns; ++j)
            {
                if (!f[j])
                {
                    if (s[j] == t[y])
                    {
                        y++;
                    }
                }
            }
            // cout<<y<<endl;
            if (y != nt)
            {
                break;
            }
            mx = max(mx, o);
        }
    }
    cout << mx << endl;
    return 0;
}