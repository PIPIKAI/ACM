#include<bits/stdc++.h>
using namespace std;
struct node
{
    int v,w;
    bool operator < ( node x)const {
        return v<x.v;/// 这是大的优先输出很明显
    }
};
int main()
{
    /*priority_queue <int> q;// 等价下面的
    priority_queue <int ,vector <int >,less<int > >q;//大的优先级高

    priority_queue <int ,vector <int >,greater <int> >  q;//把小的放在头
    /**默认的优先队列（结构体，重载小于）*/
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
