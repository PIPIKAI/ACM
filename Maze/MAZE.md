写了一下午，从学习迷宫生成算法开始的。

##### 效果图

![Image text](https://raw.githubusercontent.com/PIPIKAI/img-folder/master/MAZE/show.gif)









```c++
// 生成迷宫
int find(int x){
    while(fa[x]!=x) x=fa[x];
    return x;
}
int merge(int x,int y){
    int f1=find(x);
    int f2=find(y);
    if(f1<f2) fa[f2]=f1;
    else if(f1>f2) fa[f1]=f2;
    else return 0;
    return 1;
}
int check_wall(int x,int y){
    if(x<=0||x>=X||y>=Y||y<=0){
        return 1;
    }
    return 0;
}
int check_choke(int x,int y){//检查是否全是阻塞的
    if(mz[x+1][y]==1 && mz[x-1][y]==1 &&mz[x][y+1]==1 &&mz[x][y-1]==1){
        return 1;
    }
    return 0;
}
void make_path(){
    srand(time(NULL));
    for(int p=0;p<cnt*8;p++){
        if(find(0)==find(cnt-1)){
            return ;
        }
        int road=vis[p%cnt];
        int next=rand()%4;
        int x=f[road].x,y=f[road].y;
        if(check_choke(x,y)){
            for(int i=0;i<4;i++){
                int cx=x+dir[next][0]*2,cy=y+dir[next][1]*2;
                int next_road=hs[cx][cy];
                if(!check_wall(cx,cy)){
                merge(road,next_road);
                mz[x+dir[next][0]][y+dir[next][1]]=0;
                }
            }
        }
        else{
            int cx=x+dir[next][0]*2,cy=y+dir[next][1]*2;
            int next_road=hs[cx][cy];
            if(!check_wall(cx,cy)){
                merge(road,next_road);
                mz[x+dir[next][0]][y+dir[next][1]]=0;
            }
        }
    }
    ppk=f[0];
}

```

 

 

　　