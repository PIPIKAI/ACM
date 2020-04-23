# ACM 图论的学习

### 1.拓扑排序

```c++
void topsort(){ // 基本操作
	for(int i=1;i<=n;i++) if(d[i]==0) q.push(i);
	while(!q.empty()){
		int tp=q.top();
		q.pop();
		for(int i=0;i<f[tp].size();i++){
			int j=f[tp][i];
			d[j]--;
			if(!d[j]) q.push(j);
		}		
	}
}
```

####  hdu-1285 确定比赛名次:

 把度为0的入队(优先队列，题目要求)然后把0度的点的连边度减一，重复

#### hdu-2647  Reward:

带权值的top排序，可能有相等关系，作法和上面大概一致，只是在入队时，所增加的钱为，父节点的钱+1 ，（结果要从哪个算起，就是对面那个入度）

#### HDU - 1811 Rank of Tetris :

带等号的top排序，先要用并查集把等号的情况排除掉，然后top排序来判断







