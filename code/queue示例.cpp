#include <iostream>
#include <queue>
#include <assert.h>
/*
���õ�ʱ��Ҫ��ͷ�ļ��� #include<stdlib.h> �� #include<cstdlib> +
#include<queue>       #include<queue>
��ϸ�÷�:
����һ��queue�ı���     queue<Type> M
�鿴�Ƿ�Ϊ�շ���        M.empty()    �ǵĻ�����1�����Ƿ���0;
������Ԫ�غ�������Ԫ��   M.push()
�������Ԫ�صĸ���      M.size()
��ʾ��һ��Ԫ��          M.front()
��ʾ���һ��Ԫ��        M.back()
�����һ��Ԫ��          M.pop()
*/
using namespace std;
void dispaly(queue<int > q)
{
    while(!q.empty())
    {
        cout<<q.front();
        q.pop();
    }
}
int main()
{
    int n;
    cin>>n;
    cout<<"input  "<<n<<"number"<<endl;
    queue<int>q;
    while(n)
    {
        int temp;
        cin>>temp;
        q.push(temp);
        n--;
    }
    dispaly(q);

    return 0;
}
