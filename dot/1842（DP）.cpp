#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define MAX 100001
int max(int a,int b){   //ѡ���ıȽϺ���
    return a>b?a:b;
}
int dp(int arr[],int n,int k,int maxsc){   //��̬�滮����
    int count = 0;   //���
    if(k==0){   //���K==0  ��������ÿ����������ֻ����һ������
        int i;
        for(i=0;i<=maxsc;i++){
            if(arr[i])count++;
        }
    }
    else{   //�������
        int i,dp[MAX];   //dp���������洢 �� i ����ʱ �����ͬʱ���ߵ�����
        for(i=0;i<k;i++){   //����  ��ÿһ���б�����ѭ��  ��������� �ο�ϣ�������һ��
            int m = 0;
            int val[MAX],j;
            for(j=i;j<=maxsc;j+=k){
                val[m++]=arr[j];  //�Ѹ÷����ֵ�ŵ�val����
            }
            dp[0]=val[0];  //��һ���˵�ʱ��  �϶�����  ֱ�ӷ����
            for(j=1;j<m;j++){
                if(j==1)dp[j]=max(dp[0],val[j]);  //�ڶ����˵�ʱ��  ֻ�������˵�ʱ��  ���������������Ӱ�죬ֱ��ѡ�ϴ��
                else dp[j]=max(dp[j-2]+val[j],dp[j-1]);  //�ӵ������˿�ʼ ���������ǰ��Ӱ�죬��֮ǰ��������������Ѿ���dp����������
            }
            count += dp[m-1];  //��ÿһ���������������ӵ�һ��
        }
    }
    return count;
}
int main(){
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        int arr[MAX];
        memset(arr,0,sizeof(arr));  //��������ʼ��
        int i,scor,maxscor=0;
        for(i=0;i<n;i++){  //������֯��ʽ�� �±��Ƿ���  ֵ�Ǹ÷���������
            scanf("%d",&scor);
            arr[scor]++;
            if(maxscor<scor)maxscor=scor;
        }
        int res = dp(arr,n,k,maxscor);  //��̬�滮
        printf("%d\n",res);  //���
    }
}
