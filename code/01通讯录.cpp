#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 struct node
{
	char name[255];
	char tel[255];
	struct node *pnext;
};
typedef node  NODE;
NODE *initlist()
{
	NODE *head;
	head=(NODE* )malloc(sizeof(NODE));
	head->pnext=NULL;
	return head;
}
void add(NODE *Head)
{
	NODE *tp,*p;
	tp=(NODE* )malloc(sizeof(NODE));
	p=Head;
	printf("INput name:\n");scanf("%s",tp->name);
	printf("INput tel:\n");scanf("%s",tp->tel); 
	while(p->pnext!=NULL) 
	 {
	 	if(strcmp(p->pnext->name,tp->name)>0)
		 {
		 	tp->pnext=p->pnext;
			 p->pnext=tp; 
			 return ; 
		 } 
		 p=p->pnext; 
	 } 
	 p->pnext=tp;
	 tp->pnext=NULL; 
	return ;

}
NODE  *search(NODE *head)
 {
    char sname[20];
	NODE *t;
	printf("请输入名字：");
	scanf("%s",sname);
	t=head;
	while(t->pnext!=NULL&&strcmp(t->pnext->name,sname)!=0)
	{
		t=t->pnext; 
	} 
	if(t->pnext==NULL)
	{
		return NULL;
	} 
	return t; 
 }  
 void del(NODE *head)
 {
 	NODE *t;
    t=search(head);
	 if(t!=NULL)
	 {
	 	t->pnext=t->pnext->pnext; 
	 } 
	 return ; 
 } 
void disList(NODE*head)
{
	NODE *tp;
	tp=head;
	while(tp->pnext!=NULL)
	{
	    tp=tp->pnext;
		printf("name:%s\ntel:%s\n",tp->name,tp->tel);

	}

	return ;
}
int main()
{
	NODE *HEAD;
	HEAD=(NODE* )malloc(sizeof(NODE));
	HEAD=initlist();
	while(1)
	{
		system("cls");
		printf("-----欢迎使用通讯录----\n\n");
	printf("1:     增加联系人\n");
	printf("2:     查找联系人\n");
	printf("3:     删除联系人\n");
	printf("4:     退出通讯录\n");
		int p;
		scanf("%d",&p);
		switch(p)
		{
			case 1:add(HEAD);disList(HEAD);
					getchar();system("pause");
			break ;	
		case 2:search(HEAD);disList(HEAD);
		getchar();
		system("pause");
		break;
		case 3:del(HEAD);disList(HEAD);
		getchar();
		system("pause");
		break; 
		case 4:exit(-1);
		}


	}
	disList(HEAD);
	return 0;
}
