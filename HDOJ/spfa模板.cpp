void spfa(int s){
	for(int i=0; i<=n; i++) dis[i]=99999999; //初始化每点i到s的距离
	dis[s]=0; vis[s]=1; q[1]=s;  队列初始化,s为起点
	int i, v, head=0, tail=1;
	while (head<tail){   队列非空
		head++;
		v=q[head];  取队首元素
		vis[v]=0;   释放队首结点，因为这节点可能下次用来松弛其它节点，重新入队
		for(i=0; i<=n; i++)  对所有顶点
		   if (a[v][i]>0 && dis[i]>dis[v]+a[v][i]){
				dis[i] = dis[v]+a[v][i];   修改最短路
				if (vis[i]==0){  如果扩展结点i不在队列中，入队
					tail++;
					q[tail]=i;
					vis[i]=1;
				}
		   }

	}
}
我们在借助结点u对结点v松弛的同时，标记下path[v]=u，记录的工作就完成了。
    如何输出呢？我们记录的是每个点前面的点是什么，输出却要从最前面到后面输出，这很好办，递归就可以了：

void printpath(int k){
	if (path[k]!=0) printpath(path[k]);
	cout << k << ' ';
}
void spfa(int s){
	for(int i=1; i<=b[s][0]; i++)  //b[s,0]是从顶点s发出的边的条数
	   if (dis[b[s][i]>dis[s]+a[s][b[s][i]]){  //b[s,i]是从s发出的第i条边的另一个顶点
		dis[b[s][i]=dis[s]+a[s][b[s][i]];
		spfa(b[s][i]);
	   }
}

for(int i=0; i<m; i++){
		cin >> x >> y >> z;   x,y一条边的两个结点;z这条边的权值
		if (a[x][y]!=0 && z>a[x][y]) continue;如果两顶点间有多条边，保留最小的一条
		b[x][0]++; b[x][b[x][0]]=y; a[x][y]=z;   b[x,0]以x为一个结点的边的条数
		b[y][0]++; b[y][b[y][0]]=x; a[y][x]=z;
	}
	cin >> s >> t;   读入起点与终点
	spfa(s);
	if (dis[t]!=99999999) cout << dis[t] << endl;
	else cout << -1 << endl;


