#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-011 直捣黄龙
 *
 * 题目描述：
 *   给定一个城镇网络，每个城镇有敌人数量。要求从起点出发，找到到达终点的最优路径：
 *   1. 路程最短（第一优先级）。
 *   2. 解放城镇数量最多（第二优先级）。
 *   3. 歼灭敌人数量最多（第三优先级）。
 *   输入格式：第一行给出四个整数 N、K 和两个字符串，分别表示城镇数量、道路数量、起点和终点名称。
 *   接下来 N-1 行，每行给出城镇名称和该城镇的敌人数量。
 *   接下来 K 行，每行给出一条道路连接的两个城镇和道路长度。
 *   输出格式：第一行输出路径（城镇名称用 -> 连接），第二行输出解放城镇数、路程、歼敌数。
 *
 * 实现原理：
 *   使用改进的 Dijkstra 算法，维护三个优先级：距离、解放城镇数、歼敌数。
 *   1. 使用邻接矩阵 graph[][] 存储道路长度。
 *   2. 使用 name[][] 和 id_of() 函数进行城镇名称和编号的映射。
 *   3. Dijkstra 算法更新规则：
 *      a. 如果距离更短，更新所有值。
 *      b. 如果距离相等，比较解放城镇数。
 *      c. 如果距离和城镇数都相等，比较歼敌数。
 *   4. 使用 pre[] 数组记录路径前驱，用于回溯输出路径。
 *
 * 时间复杂度：O(N^2)，其中 N 是城镇数量
 */
#define MAXN 205
#define INF 0x3f3f3f3f
static char name[MAXN][4]; static int graph[MAXN][MAXN], enemy[MAXN];
static int id_of(char s[], int n) { int i; for(i=0;i<n;++i)if(!strcmp(name[i],s))return i; strcpy(name[n],s);return n; }
int main(void) {
    int n,k,s,t,i,j,dist[MAXN],town[MAXN],kill[MAXN],pre[MAXN],used[MAXN]={0}; char a[4],b[4];
    scanf("%d%d%s%s",&n,&k,name[0],b); s=0;
    for(i=1;i<n;++i){scanf("%s%d",name[i],&enemy[i]);if(!strcmp(name[i],b))t=i;}
    for(i=0;i<n;++i)for(j=0;j<n;++j)graph[i][j]=i==j?0:INF;
    while(k--){int x,y,w;scanf("%s%s%d",a,b,&w);x=id_of(a,n);y=id_of(b,n);if(w<graph[x][y])graph[x][y]=graph[y][x]=w;}
    for(i=0;i<n;++i)dist[i]=INF,town[i]=kill[i]=0,pre[i]=-1;dist[s]=0;
    for(i=0;i<n;++i){int u=-1;for(j=0;j<n;++j)if(!used[j]&&(u<0||dist[j]<dist[u]))u=j;if(u<0)break;used[u]=1;for(j=0;j<n;++j)if(graph[u][j]<INF){int d=dist[u]+graph[u][j],c=town[u]+1,e=kill[u]+enemy[j];if(d<dist[j]||(d==dist[j]&&(c>town[j]||(c==town[j]&&e>kill[j]))))dist[j]=d,town[j]=c,kill[j]=e,pre[j]=u;}}
    {int path[MAXN],cnt=0;for(i=t;i>=0;i=pre[i])path[cnt++]=i;while(cnt--)printf("%s%s",name[path[cnt]],cnt?"->":"\n");}
    printf("%d %d %d\n",town[t],dist[t],kill[t]); return 0;
}
