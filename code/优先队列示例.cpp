#include<bits/stdc++.h>
using namespace std;
struct node
{
    int v,w;
    bool operator < ( node x)const {
        return v<x.v;/// ���Ǵ���������������
    }
};
int main()
{
    /*priority_queue <int> q;// �ȼ������
    priority_queue <int ,vector <int >,less<int > >q;//������ȼ���

    priority_queue <int ,vector <int >,greater <int> >  q;//��С�ķ���ͷ
    /**Ĭ�ϵ����ȶ��У��ṹ�壬����С�ڣ�*/
    priority_queue<node> q;
    q.push(node{1,2});
    q.push(node{2,2});
    q.push(node{3,2});
    q.push(node{4,2});
    q.push(node{5,2});
    while(!q.empty())
    {
        cout<<q.top().v<<endl;
        q.pop();
    }
    return 0;
}
