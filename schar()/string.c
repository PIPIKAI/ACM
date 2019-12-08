#include<stdio.h>
#include<malloc.h>
#include<memory.h>
#define MAX_LEN 1000
int s_lenth(char *tp){//获得s长度
    int len=0;
    while(*tp) len++,*tp++;
    return len;
}
int s_find(char *c){

}
char * s_insert(char *s,int id,char *add){
    char *res=(char *)malloc(s_lenth(s)+s_lenth(add)+1);
    memset(res, '\0', sizeof(res));
    int j=0;
    for(int i=0;*add&&*s;){
            if(i<id){
                res[j]=*s;
                i++;j++;*s++;
            }else{
                res[j]=*add;j++;*add++;
            }
    }
    while(*s) res[j++]=*s++;
    res[j]='\0';
    return res;
}
char * s_sbustr(char *s,int id,int len){//截取从当前下标i到长度为len的字符串
    char *res=(char *)malloc(len+1);
    memset(res, '\0', sizeof(res));
    s+=id;
    for(int i=0,j=0;*s&&i<len;i++,*s++){
            res[j++]=*s;
    }
    res[j]='\0';
    return res;
}
char * s_add(char *a,char *b){//两个字符串相加
    char *res=(char *)malloc(s_lenth(a)+s_lenth(b)+1);
    memset(res, '\0', sizeof(res));
    int j=0;
    while(*a) res[j++]=*a++;
    while(*b) res[j++]=*b++;
    res[j]='\0';
    return res;
}
char* s_erase(char *s,int id,int len){//从当前下标i删除长度为len的字符串
    char *res=(char *)malloc(s_lenth(s)-len+1);
    memset(res, '\0', sizeof(res));
    int j;
    for(int i=0,j=0;*s;i++,*s++){
        if(i<id||i>=id+len){
            res[j++]=*s;
        }
    }
    res[j]='\0';
    return res;
}
int main(){
    char  *s=(char *)malloc(MAX_LEN);
    char *b="+++addd";
    gets(s);
    char *tp=s_insert(s,3,"insert,id=3");
    puts(tp);
    printf("len=%d\n",s_lenth(tp));
    return 0;
}