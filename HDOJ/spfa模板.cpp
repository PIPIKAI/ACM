void spfa(int s){
	for(int i=0; i<=n; i++) dis[i]=99999999; //��ʼ��ÿ��i��s�ľ���
	dis[s]=0; vis[s]=1; q[1]=s;  ���г�ʼ��,sΪ���
	int i, v, head=0, tail=1;
	while (head<tail){   ���зǿ�
		head++;
		v=q[head];  ȡ����Ԫ��
		vis[v]=0;   �ͷŶ��׽�㣬��Ϊ��ڵ�����´������ɳ������ڵ㣬�������
		for(i=0; i<=n; i++)  �����ж���
		   if (a[v][i]>0 && dis[i]>dis[v]+a[v][i]){
				dis[i] = dis[v]+a[v][i];   �޸����·
				if (vis[i]==0){  �����չ���i���ڶ����У����
					tail++;
					q[tail]=i;
					vis[i]=1;
				}
		   }

	}
}
�����ڽ������u�Խ��v�ɳڵ�ͬʱ�������path[v]=u����¼�Ĺ���������ˡ�
    �������أ����Ǽ�¼����ÿ����ǰ��ĵ���ʲô�����ȴҪ����ǰ�浽�����������ܺð죬�ݹ�Ϳ����ˣ�

void printpath(int k){
	if (path[k]!=0) printpath(path[k]);
	cout << k << ' ';
}
void spfa(int s){
	for(int i=1; i<=b[s][0]; i++)  //b[s,0]�ǴӶ���s�����ıߵ�����
	   if (dis[b[s][i]>dis[s]+a[s][b[s][i]]){  //b[s,i]�Ǵ�s�����ĵ�i���ߵ���һ������
		dis[b[s][i]=dis[s]+a[s][b[s][i]];
		spfa(b[s][i]);
	   }
}

for(int i=0; i<m; i++){
		cin >> x >> y >> z;   x,yһ���ߵ��������;z�����ߵ�Ȩֵ
		if (a[x][y]!=0 && z>a[x][y]) continue;�����������ж����ߣ�������С��һ��
		b[x][0]++; b[x][b[x][0]]=y; a[x][y]=z;   b[x,0]��xΪһ�����ıߵ�����
		b[y][0]++; b[y][b[y][0]]=x; a[y][x]=z;
	}
	cin >> s >> t;   ����������յ�
	spfa(s);
	if (dis[t]!=99999999) cout << dis[t] << endl;
	else cout << -1 << endl;


