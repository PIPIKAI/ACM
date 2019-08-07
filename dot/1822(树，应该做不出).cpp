#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
struct node{
    int root;
    bool isopen; /// 是否打开过
    struct node* nextLayerHead;///下一层
    struct node* nextBrother; /// 同层的兄弟
};
void init(node * t,int x){
    t->root=x;
    t->isopen=0;
    t->nextLayerHead=0;
    t->nextBrother=0;
}
void add(node *t,int x,int val){
    if(t==0){
        return ;
    }

    if(t->root==x){
        node *k= (node *) malloc(sizeof( node));
        init(k,val);
        k->nextBrother=t->nextBrother;
        t->nextLayerHead=k;
        return;
    }
    else{
        add(t->nextLayerHead, x, val);
        add(t->nextBrother, x, val);
    }
}
void opento(node * t,int x,int ans){
    if(t==0){
        return;
    }
    int s=t->root;
    if(s==x){
        cout<<ans<<endl;
    }
    else if(x < s){
        opento();
    }

}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    node *tree= (node*)malloc(sizeof (node));
    init(tree,n);
    tree->isopen=1;
    for(int i=0,a,b;i<n-1;i++){
        cin>>a>>b;
        add(tree,a,b);
    }
    while(m--){
        char x;int x;
        cin>>c>>x;
        if(c=='Q'){
            serch(tree,x);
        }
        else{
            opento(tree,x,0);
        }
    }
    return 0;
}
