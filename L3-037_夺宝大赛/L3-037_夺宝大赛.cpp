#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-037 夺宝大赛
 *
 * 题目描述：
 *   在一个网格地图中，有一个大本营（标记为 2）和一些障碍物（标记为 0）。
 *   K 支队伍从各自的起点出发，同时向大本营移动。移动规则：
 *   1. 只能向上下左右四个方向移动。
 *   2. 不能穿过障碍物。
 *   3. 同一时刻到达同一格的队伍会互相消灭。
 *   要求找出哪支队伍能最先到达大本营（且没有被其他队伍消灭）。
 *   输入格式：第一行给出网格的行数和列数。接下来给出网格内容。
 *   最后一行给出队伍数量 K，然后给出 K 支队伍的起点坐标。
 *   输出格式：如果有唯一获胜队伍，输出队伍编号和到达时间；否则输出 "No winner."。
 *
 * 实现原理：
 *   使用反向 BFS 计算每个格子到大本营的最短距离。
 *   1. 从大本营出发，使用 BFS 计算每个格子到大本营的最短距离。
 *   2. 对于每支队伍，根据其起点坐标获取到达时间。
 *   3. 统计每个时间点到达的队伍数量。
 *   4. 如果某个时间点只有一支队伍到达，则该队伍获胜。
 *   5. 如果没有这样的时间点，输出 "No winner."。
 *
 * 时间复杂度：O(R * C + K)，BFS 为 O(R * C)
 */
int main(void){
    int rows,cols,i,j,k,h=0,t=0,base=-1,dr[4]={1,-1,0,0},dc[4]={0,0,1,-1};
    int grid[105][105],dist[105][105],qr[10005],qc[10005],cnt[10005]={0},who[10005];
    if(scanf("%d%d",&rows,&cols)!=2)return 0;
    for(i=0;i<rows;++i)for(j=0;j<cols;++j){scanf("%d",&grid[i][j]);dist[i][j]=-1;if(grid[i][j]==2)base=i*cols+j;}
    qr[t]=base/cols;qc[t++]=base%cols;dist[qr[0]][qc[0]]=0;
    while(h<t){int r=qr[h],c=qc[h++],z;for(z=0;z<4;++z){int x=r+dr[z],y=c+dc[z];if(x>=0&&x<rows&&y>=0&&y<cols&&grid[x][y]&&dist[x][y]<0)dist[x][y]=dist[r][c]+1,qr[t]=x,qc[t++]=y;}}
    scanf("%d",&k);for(i=1;i<=k;++i){int x,y,d;scanf("%d%d",&x,&y);d=dist[y-1][x-1];if(d>=0)++cnt[d],who[d]=i;}
    for(i=0;i<10005;++i)if(cnt[i]==1){printf("%d %d\n",who[i],i);return 0;}puts("No winner.");return 0;
}
