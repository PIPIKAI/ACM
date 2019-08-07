#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int id;
    char name[20];
   // char position[20];
}data;
typedef struct node
{
    data a;
    struct node *left,*right;
}bnode;
// creat
bnode * creat_bitree()
{
    bnode *root=NULL;

    int id;
    scanf("%d",&id);

    if(id==0)
        return root;
    root=(bnode*)malloc(sizeof(bnode));
    root->a.id=id;
    scanf("%s",root->a.name);
    root->left=creat_bitree();
    root->right=creat_bitree();
    return root;
}
void xian_xu(bnode *root)
{
    if(root!=NULL)
    {
        printf("%d    %s  \n",root->a.id,root->a.name);
        xian_xu(root->left);
        xian_xu(root->right);
    }
}
void mid_xu(bnode *root)
{
    if(root!=NULL)
    {
        mid_xu(root->left);
        printf("%d    %s  \n",root->a.id,root->a.name);
        mid_xu(root->right);

    }
}
void hou_xu(bnode *root)
{

    if(root!=NULL)
    {
        hou_xu(root->left);
        hou_xu(root->right);
        printf("%d    %s \n",root->a.id,root->a.name);

    }
}
void ceil_display(bnode *root)
{

}
int main()
{
    //freopen("temp.txt","r",stdin);
    bnode *root;
    root=creat_bitree();

    printf("xian_xu is:\n");
    xian_xu(root);
    printf("\n");
    printf("mid_xu is:\n");
    mid_xu(root);
    printf("\n");
    printf("hou_xu is:\n\n");
    hou_xu(root);

    return 0;
}
