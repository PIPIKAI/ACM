#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
set<int > s;
int n, m;
int main() {
    std::ios::sync_with_stdio(false);
    s.insert(1);
    cout << "set.size() = " << s.size() << endl;
    cout << "1 �ĸ���set.count(1)" << s.count(1) << endl;
    /// ������
    set<int>::iterator it = s.begin();
    it++;
    it--;
    ///���� setset ���������е�Ԫ��
    ///set
    for(set<int>::iterator it = s.begin(); it != s.end(); it++){
        cout << *it << endl; ///ȡ�����������ָ���Ԫ��
    }
    ///setǶ��
    for(set<set<int> >::iterator it = s.begin(); it != s.end(); it++) {
        //����ȡ��set��Ƕ�׵�set
        for(set<int>::iterator rit = (*it).begin(); rit != (*it).end(); rit++)
            cout << *rit << ' '; //�������set
        cout << endl;
    }
    ///ɾ��������������Ԫ�ػ��ߵ�������������һ��Ԫ�صĵ�������ʱ�临�Ӷ�Ϊ O(log n)O(logn) ��
    ///ע���� multisetmultiset �� s.erase(x)s.erase(x) ��ɾ������ֵΪ xx ��Ԫ��
    ///�÷�������.erase(����);
    set<int>::iterator it = s.begin();
    s.erase(it);
    s.erase(3);
    ///�÷�������.find(x);
    if(s.find(x) != s.end())
        cout << "Have Found!" << endl;
    s.lower_bound(x);///��ʾ���� >= x >= x ��Ԫ������С��һ����������ָ���Ԫ�صĵ�����
    s.upper_bound(x); ///bound(x) ��ʾ���� > x > x ��Ԫ������С��һ����������ָ���Ԫ�صĵ�����
    return 0;
}
