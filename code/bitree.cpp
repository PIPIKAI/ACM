#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
typedef struct{
	int id;
	char name[20];
	//char position[20];
}DataType;

typedef struct node{
	DataType data;
	struct node *LeftChild,*RightChild;
}BiTreeNode;

BiTreeNode *CreatBiTree()
{
	BiTreeNode *root=NULL;
	int id;
	scanf("%d",&id);
	if(id == 0) { return root; }
	//creat root node
	root = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	root->data.id = id;
	scanf("%s",root->data.name);
	root->LeftChild = CreatBiTree();

	root->RightChild = CreatBiTree();
	return root;
}

void PreRootDisplay(BiTreeNode *root)
{
	if(root != NULL)
	{
		printf("%d %s \n",root->data.id,root->data.name);
		PreRootDisplay(root->LeftChild);
		PreRootDisplay(root->RightChild);
	}
	return;
}

void MidRootDisplay(BiTreeNode *root)
{
	if(root != NULL)
	{
		MidRootDisplay(root->LeftChild);
		printf("%d %s \n",root->data.id,root->data.name);
		MidRootDisplay(root->RightChild);
	}
	return;
}

void BehRootDisplay(BiTreeNode *root)
{
	if(root != NULL)
	{
		BehRootDisplay(root->LeftChild);
		BehRootDisplay(root->RightChild);
		printf("%d %s  \n",root->data.id,root->data.name);

	}
	return;
}

void CeilDisplay(BiTreeNode *root)
{
	BiTreeNode *pn[MAX];
	int h=0,r=0;
	pn[r] = root;
	r++;
	while(h!=r)
	{
		//output h node
		printf("%d %s \n",pn[h]->data.id,pn[h]->data.name);
		//if h->l !=NULL in
		if(pn[h]->LeftChild != NULL)
		 {
		 	pn[r] = pn[h]->LeftChild;
		 	r++;
		 }
		//if h->r !=NULL in
		if(pn[h]->RightChild != NULL)
		 {
		 	pn[r] = pn[h]->RightChild;
		 	r++;
		 }

		h++;
	}
	return;
}

int main()
{
	//freopen("bitree.txt","r",stdin);
	BiTreeNode *root;
	root = CreatBiTree();
	printf("first root:\n");
	PreRootDisplay(root);
	printf("\nmid root:\n");
	MidRootDisplay(root);
	printf("\nlast root:\n");
	BehRootDisplay(root);
	printf("\nceil tralvel root:\n");
	//CeilDisplay(root);
	return 0;
}
