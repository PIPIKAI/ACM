#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
set<int > s;
int n, m;
int main() {
    std::ios::sync_with_stdio(false);
    s.insert(1);
    cout << "set.size() = " << s.size() << endl;
    cout << "1 的个数set.count(1)" << s.count(1) << endl;
    /// 迭代器
    set<int>::iterator it = s.begin();
    it++;
    it--;
    ///遍历 setset 及访问其中的元素
    ///set
    for(set<int>::iterator it = s.begin(); it != s.end(); it++){
        cout << *it << endl; ///取出这个迭代器指向的元素
    }
    ///set嵌套
    for(set<set<int> >::iterator it = s.begin(); it != s.end(); it++) {
        //首先取出set中嵌套的set
        for(set<int>::iterator rit = (*it).begin(); rit != (*it).end(); rit++)
            cout << *rit << ' '; //遍历这个set
        cout << endl;
    }
    ///删除，参数可以是元素或者迭代器，返回下一个元素的迭代器，时间复杂度为 O(log n)O(logn) ，
    ///注意在 multisetmultiset 中 s.erase(x)s.erase(x) 会删除所有值为 xx 的元素
    ///用法：名称.erase(参数);
    set<int>::iterator it = s.begin();
    s.erase(it);
    s.erase(3);
    ///用法：名称.find(x);
    if(s.find(x) != s.end())
        cout << "Have Found!" << endl;
    s.lower_bound(x);///表示查找 >= x >= x 的元素中最小的一个，并返回指向该元素的迭代器
    s.upper_bound(x); ///bound(x) 表示查找 > x > x 的元素中最小的一个，并返回指向该元素的迭代器
    return 0;
}
