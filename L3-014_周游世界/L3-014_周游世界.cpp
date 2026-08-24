#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-014 周游世界
 *
 * 题目描述：
 *   给定一个地铁网络，每条线路由若干站点组成。要求找到从起点到终点的最优路径：
 *   1. 经过的区间数最少（第一优先级）。
 *   2. 需要换乘的次数最少（第二优先级）。
 *   输入格式：第一行给出线路数量 N。接下来 N 行，每行先给出线路的站点数量 M 和第一个站点编号，
 *   然后给出其余 M-1 个站点编号。最后一行给出查询次数 K，接下来 K 行每行给出起点和终点。
 *   输出格式：对于每个查询，输出经过的区间数，然后输出具体的路径描述。
 *
 * 实现原理：
 *   使用改进的 Dijkstra 算法，以区间数为主关键字、换线次数为次关键字。
 *   1. 使用邻接表存储站点之间的连接关系，同时记录所属线路编号。
 *   2. Dijkstra 算法维护：
 *      a. dist[]：到达每个站点经过的区间数。
 *      b. change[]：到达每个站点需要的换乘次数。
 *      c. pline[]：到达每个站点时所在的线路。
 *      d. pre[]：路径前驱节点。
 *   3. 更新规则：如果当前边的线路与前一条边不同，则换乘次数 +1。
 *   4. 路径重建：根据 pre[] 和 pline[] 回溯，输出每段行程的线路和站点范围。
 *
 * 时间复杂度：O(K * S^2)，其中 S 是站点数量
 */
#define MAXS 10000
#define MAXE 20050
#define INF 0x3f3f3f3f
static int head[MAXS],to[MAXE],line[MAXE],next[MAXE],ec;
static void add(int a,int b,int l){to[ec]=b;line[ec]=l;next[ec]=head[a];head[a]=ec++;}
int main(void){
    int n,i,k;
    for(i=0;i<MAXS;++i)head[i]=-1;
    scanf("%d",&n);
    for(i=1;i<=n;++i){int m,pre,x;scanf("%d%d",&m,&pre);while(--m){scanf("%d",&x);add(pre,x,i);add(x,pre,i);pre=x;}}
    scanf("%d",&k);
    while(k--){
        int s,t,dist[MAXS],change[MAXS],pre[MAXS],pline[MAXS],used[MAXS]={0},v;
        scanf("%d%d",&s,&t);
        for(i=0;i<MAXS;++i)dist[i]=change[i]=INF,pre[i]=-1,pline[i]=-1;
        dist[s]=change[s]=0;
        for(i=0;i<MAXS;++i){int u=-1,e;for(v=0;v<MAXS;++v)if(!used[v]&&(u<0||dist[v]<dist[u]||(dist[v]==dist[u]&&change[v]<change[u])))u=v;if(u<0||dist[u]==INF)break;used[u]=1;for(e=head[u];e>=0;e=next[e]){v=to[e];{int d=dist[u]+1,c=change[u]+(pline[u]>=0&&pline[u]!=line[e]);if(d<dist[v]||(d==dist[v]&&c<change[v]))dist[v]=d,change[v]=c,pre[v]=u,pline[v]=line[e];}}}
        if(dist[t]==INF){puts("Sorry, no line is available.");continue;}
        printf("%d\n",dist[t]-1);
        {int path[MAXS],cnt=0,pos;for(v=t;v>=0;v=pre[v])path[cnt++]=v;pos=cnt-1;while(pos>0){int company=pline[path[pos-1]],begin=path[pos],end;while(pos>0&&pline[path[pos-1]]==company){end=path[pos-1];--pos;}printf("Go by the line of company #%d from %04d to %04d.\n",company,begin,end);}}
    }
    return 0;
}
