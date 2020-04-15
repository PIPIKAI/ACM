#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""

TSP问题，请用不同的算法实现（遗传、动态规划，回溯，分支限界，模拟退火），并比较结果和时间复杂度

"""
from time import time
import sys
def find_vertex(j):
    vertex = []
    for v in range(n-1):
        if 2**v & j != 0:
            vertex.append(v+1)
    return vertex
def DP(C):
    n=len(C)
    dp = [[sys.maxsize for j in range(n)] for i in range(1<<n)]
    for i in range(0,n):
        for j in range(0,n):
            if C[i][j] == 0:
                C[i][j] = sys.maxsize
    n = len(C)
    dp = [[sys.maxsize for j in range(2 ** (n - 1))] for i in range(n)]
    for i in range(0, n):
        dp[i][0] = C[i][0]

    for j in range(1, 2**(n-1)):
        for i in range(0, n):
            temp_1 = []
            vertexs = find_vertex(j)
            if i not in vertexs:
                for k in vertexs:
                    if C[i][k] == -1:
                        continue
                    temp_1.append(C[i][k] + dp[k][j - 2**(k-1)])
            if temp_1:
                dp[i][j] = min(temp_1)
            del temp_1
    return dp
def DFS(w, now, vised ,lenth ):
    global ans;

    if( vised +1 == 1<<n):
        ans=min(ans,lenth+w[0][now]) 
    for i in range(0,n):
        if(vised >> i & 1):
            continue
        if(w[now][i] == 0):
            continue;
        DFS(w,i, vised + (1<<i), lenth + w[now][i] )
        
    return 
if __name__ == "__main__":
    s = [
        [0,2,4,5,1,],
        [2,0,6,5,3,],
        [4,6,0,8,3,],
        [5,5,8,0,5,],
        [1,3,3,5,0,]]
    n = len(s) # n nodes
    
    # a[x,x]=0，a[x,y]=a[y,x] 并且 a[x,y]+a[y,z]>=a[x,z]。
    start = time()
    dp = DP(s) # the  final result
    end = time()
    print("答案：",dp[0][2**(n-1)-1],"动态规划运行时间",end-start)
    
    start = time()
    ans=sys.maxsize
    DFS(s , 0 , 1, 0 )
    end = time()
    print("答案：",ans,"回溯运行时间",end-start)

