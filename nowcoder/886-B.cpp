#include<bits/stdc++.h>
using namespace std;
int n, m, T;
string mp = "0123456789abcdef";
string ans[20];
vector<string>out;
int flag[20], cnt;
vector<pair<int, int> > pp;
int to_10(string s) {
    int res = 0, er = 1;
    for(int i = s.size() - 1; i >= 0; i--) {
        if(s[i] == '1') res = res + er;
        er = er * 2;
    }
    return res;
}
char  dell(string ts) {
    char res;
    int tp = to_10(ts);
    res = mp[tp];
    return res;
}
void ____(int ll, int rr) {
    string wawawa;
    if(rr - ll > 0 && ll == 0) {
        wawawa += ':';
    }
    for(int i = 0; i < cnt; i++) {
        if( rr - ll > 0 && i >= ll && i <= rr) {
            if(i == rr)
                wawawa += ':';
        } else {
            wawawa += ans[i];
            if(i != cnt - 1)
                wawawa += ':';
        }
    }
    out.push_back(wawawa);
}
bool cmp(string a, string b) {
    a.size() == b.size() ? return a < b : return a.size() < b.size();
}
int main() {
    std::ios::sync_with_stdio(false);
    string ts = "", is = "";
    int ccase = 0;
    cin >> T;
    while(T--) {
        int maxl = 0, l = 0, r = 0, ml = 0, mr = 0;
        cnt = 0;
        ts = "", is = "";
        out.clear();
        pp.clear();
        mem(flag, 0);
        for(int i = 1; i <= 128; i++) {
            char c;
            cin >> c;
            is += c;
            if(i % 4 == 0) {
                char ad = dell(is);
                if(ad != '0') flag[cnt] = 1;
                if(flag[cnt]) ts += ad;
                is = "";
            }
            if(i % 16 == 0) {
                if(flag[cnt] == 0) {
                    ts += '0';
                }
                if(cnt != 0 && flag[cnt - 1] == 0 && flag[cnt] == 0) {
                    if(r + 1 == cnt) {
                        r++;
                        if(r - l + 1 >= mr - ml + 1) {
                            ml = l;
                            mr = r;
                            pp.push_back(make_pair(ml, mr));
                        }
                    } else {
                        if(ml == 0 && mr == 0) {
                            ml = cnt - 1;
                            mr = cnt;
                        }
                        l = cnt - 1;
                        r = cnt;
                        pp.push_back(make_pair(l, r));
                        pp.push_back(make_pair(ml, mr));
                    }
                }
                ans[cnt++] = ts;
                ts = "";
            }
        }
        ccase++;
        cout << "Case #" << ccase << ": ";
        int wa = pp.size();
        for(int i = 0; i < wa; i++) {
            int tl = pp[i].first, tr = pp[i].second;
            if(tr - tl + 1 == mr - ml + 1)
                ____(pp[i].first, pp[i].second);
        }
        if(out.size() == 0) {
            ____(0, 0);
        } else {
            sort(out.begin(), out.end(), cmp);
        }
        cout << out[0] << endl;
    }
    return 0;
}

