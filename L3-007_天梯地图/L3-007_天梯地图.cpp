#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-007 天梯地图
 *
 * 题目描述：
 *   给定一个城市的道路网络，每条道路有长度和通行时间两个属性。
 *   要求找出从起点到终点的两条最优路径：
 *   1. 时间最短路径（如果有多个，选择总长度最短的）。
 *   2. 距离最短路径（如果有多个，选择经过节点数最少的）。
 *   输入格式：第一行给出两个整数 N、M，分别表示城市节点数和道路数。
 *   接下来 M 行，每行给出一条道路的信息：起点、终点、是否单向、长度、时间。
 *   最后一行给出起点和终点编号。
 *   输出格式：分别输出时间最短路径和距离最短路径，如果两条路径相同则只输出一条。
 *
 * 实现原理：
 *   使用改进的 Dijkstra 算法，同时维护主关键字和次关键字。
 *   1. 使用邻接矩阵 len[][] 和 tim[][] 分别存储道路长度和时间。
 *   2. 定义 dijkstra 函数，接受权重矩阵和次关键字矩阵。
 *   3. 时间最短路径：主关键字为时间，次关键字为总长度。
 *   4. 距离最短路径：主关键字为长度，次关键字为经过节点数（每条边贡献 1）。
 *   5. 使用 pre[] 数组记录前驱节点，用于路径重建。
 *   6. 判断两条路径是否相同，如果相同则合并输出。
 *
 * 时间复杂度：O(N^2)，其中 N 是节点数量
 */
#define MAXN 505
#define INF 0x3f3f3f3f
static int len[MAXN][MAXN], tim[MAXN][MAXN];
static void dijkstra(int n, int source, int weight[MAXN][MAXN], int tie[MAXN][MAXN], int dist[], int pre[]) {
    int used[MAXN] = {0}, secondary[MAXN], i, turn;
    for (i = 0; i < n; ++i) dist[i] = weight[source][i], secondary[i] = tie[source][i], pre[i] = source;
    dist[source] = secondary[source] = 0; pre[source] = -1;
    for (turn = 0; turn < n; ++turn) {
        int u = -1, best = INF;
        for (i = 0; i < n; ++i) if (!used[i] && dist[i] < best) best = dist[i], u = i;
        if (u < 0) break; used[u] = 1;
        for (i = 0; i < n; ++i) if (!used[i] && weight[u][i] < INF) {
            int d = dist[u] + weight[u][i], s = secondary[u] + tie[u][i];
            if (d < dist[i] || (d == dist[i] && s < secondary[i])) dist[i] = d, secondary[i] = s, pre[i] = u;
        }
    }
}
static int build_path(int end, int pre[], int path[]) { int n = 0; while (end >= 0) path[n++] = end, end = pre[end]; return n; }
static void print_path(int path[], int count) { while (count--) printf("%d%s", path[count], count ? " => " : "\n"); }
int main(void) {
    int n, m, i, j, a, b, one, d, t, s, e, dt[MAXN], dd[MAXN], pt[MAXN], pd[MAXN], p1[MAXN], p2[MAXN], nodes[MAXN][MAXN];
    scanf("%d%d", &n, &m);
    for (i=0;i<n;++i) for(j=0;j<n;++j) len[i][j]=tim[i][j]= i==j ? 0 : INF;
    while(m--) { scanf("%d%d%d%d%d",&a,&b,&one,&d,&t); if(d<len[a][b]) len[a][b]=d; if(t<tim[a][b]) tim[a][b]=t; if(!one){ if(d<len[b][a])len[b][a]=d; if(t<tim[b][a])tim[b][a]=t; } }
    scanf("%d%d",&s,&e);
    /* 时间路径的次关键字为长度；距离路径的次关键字为边数。 */
    dijkstra(n,s,tim,len,dt,pt);
    for(i=0;i<n;++i) for(j=0;j<n;++j) nodes[i][j]=tim[i][j]<INF ? 1 : INF;
    dijkstra(n,s,len,nodes,dd,pd);
    i=build_path(e,pt,p1); j=build_path(e,pd,p2);
    if(i==j) { int same=1,k; for(k=0;k<i;++k)if(p1[k]!=p2[k])same=0; if(same){ printf("Time = %d; Distance = %d: ",dt[e],dd[e]); print_path(p1,i); return 0; } }
    printf("Time = %d: ",dt[e]); print_path(p1,i);
    printf("Distance = %d: ",dd[e]); print_path(p2,j);
    return 0;
}
