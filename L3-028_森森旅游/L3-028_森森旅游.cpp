#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-028 森森旅游
 *
 * 题目描述：
 *   森森要从城市 1 到城市 N 旅游，途中可以使用现金或旅游金支付路费。
 *   每条道路有两种费用：现金费用 c 和旅游金费用 d。
 *   在某些城市可以将现金兑换成旅游金，兑换比率为 a[i]（1单位现金兑换 a[i] 单位旅游金）。
 *   要求找到最优的兑换策略，使得总现金花费最少。
 *   输入格式：第一行给出三个整数 N、M、Q，分别表示城市数、道路数、查询数。
 *   接下来 M 行，每行给出一条道路的信息：起点、终点、现金费用、旅游金费用。
 *   接下来 N 行，每行给出一个城市的兑换比率 a[i]。
 *   最后 Q 行，每行给出一个更新操作：城市 x 的兑换比率改为 v。
 *   输出格式：对于每个查询，输出最少现金花费。
 *
 * 实现原理：
 *   使用两次 Dijkstra 算法分别计算现金最短路和旅游金最短路。
 *   1. cash[i]：从城市 1 到城市 i 的现金最短路。
 *   2. tour[i]：从城市 i 到城市 N 的旅游金最短路（反向图）。
 *   3. 对于每个城市 i，假设在 i 处兑换旅游金，则总现金花费为：
 *      cash[i] + ceil(tour[i] / a[i])
 *   4. 选择所有城市中花费最小的作为答案。
 *   5. 查询时只需重新计算每个城市的总花费并取最小值。
 *
 * 时间复杂度：O(N^2 + Q * N)，Dijkstra 为 O(N^2)，每次查询为 O(N)
 */
#define INF 0x3f3f3f3f
typedef struct {int to,c,d,next;} Edge;
static int head[100005],rhead[100005],ec; static Edge e[400005],re[400005];
static void add(int u,int v,int c,int d){e[ec]=(Edge){v,c,d,head[u]};head[u]=ec;re[ec]=(Edge){u,c,d,rhead[v]};rhead[v]=ec++;}
static void dij(int n,int src,int rev,int use_d,long long dis[]){int i,used[100005]={0};for(i=1;i<=n;++i)dis[i]=1LL<<60;dis[src]=0;for(i=1;i<=n;++i){int u=-1,j;for(j=1;j<=n;++j)if(!used[j]&&(u<0||dis[j]<dis[u]))u=j;if(u<0)break;used[u]=1;for(j=rev?rhead[u]:head[u];j>=0;j=(rev?re[j].next:e[j].next)){Edge z=rev?re[j]:e[j];long long w=use_d?z.d:z.c;if(dis[u]+w<dis[z.to])dis[z.to]=dis[u]+w;}}}
int main(void){int n,m,q,i,x,v;long long cash[100005],tour[100005],a[100005];scanf("%d%d%d",&n,&m,&q);for(i=1;i<=n;++i)head[i]=rhead[i]=-1;while(m--){int u,w,c,d;scanf("%d%d%d%d",&u,&w,&c,&d);add(u,w,c,d);}dij(n,1,0,0,cash);dij(n,n,1,1,tour);for(i=1;i<=n;++i)scanf("%lld",&a[i]);while(q--){long long best=1LL<<60;scanf("%d%lld",&x,&v);a[x]=v;for(i=1;i<=n;++i){long long need=cash[i]+(tour[i]+a[i]-1)/a[i];if(need<best)best=need;}printf("%lld\n",best);}return 0;}
