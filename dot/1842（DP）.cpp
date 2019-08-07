#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define MAX 100001
int max(int a,int b){   //选最大的比较函数
    return a>b?a:b;
}
int dp(int arr[],int n,int k,int maxsc){   //动态规划函数
    int count = 0;   //结果
    if(k==0){   //如果K==0  单独处理，每个分数的人只允许一个在线
        int i;
        for(i=0;i<=maxsc;i++){
            if(arr[i])count++;
        }
    }
    else{   //其他情况
        int i,dp[MAX];   //dp数组用来存储 第 i 个人时 最多能同时在线的人数
        for(i=0;i<k;i++){   //分组  对每一进行遍历的循环  如果看不懂 参考希尔排序第一趟
            int m = 0;
            int val[MAX],j;
            for(j=i;j<=maxsc;j+=k){
                val[m++]=arr[j];  //把该分组的值放到val数组
            }
            dp[0]=val[0];  //就一个人的时候  肯定可以  直接放里边
            for(j=1;j<m;j++){
                if(j==1)dp[j]=max(dp[0],val[j]);  //第二个人的时候  只有两个人的时候  不会对其他结果造成影响，直接选较大的
                else dp[j]=max(dp[j-2]+val[j],dp[j-1]);  //从第三个人开始 最大人数受前面影响，但之前的最大在线人数已经在dp数组里面了
            }
            count += dp[m-1];  //把每一个分组的最大人数加到一起
        }
    }
    return count;
}
int main(){
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        int arr[MAX];
        memset(arr,0,sizeof(arr));  //这里必须初始化
        int i,scor,maxscor=0;
        for(i=0;i<n;i++){  //数组组织方式： 下标是分数  值是该分数的人数
            scanf("%d",&scor);
            arr[scor]++;
            if(maxscor<scor)maxscor=scor;
        }
        int res = dp(arr,n,k,maxscor);  //动态规划
        printf("%d\n",res);  //结果
    }
}
