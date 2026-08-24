#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-022 地铁一日游
 *
 * 题目描述：
 *   给定一个地铁网络，每条线路由若干站点组成，相邻站点之间有距离。
 *   票价计算规则：2元起步，每经过 k 公里增加1元。
 *   要求从给定起点出发，找出所有可达的站点：
 *   1. 票价最低的站点优先可达。
 *   2. 同票价下，如果是终点站则可达。
 *   输入格式：第一行给出三个整数 N、M、K，分别表示站点数、线路数、票价区间。
 *   接下来 M 行，每行给出一条线路的站点和距离信息。
 *   最后一行给出查询次数，然后给出起点站点编号。
 *   输出格式：对于每个查询，输出所有可达站点的编号（按升序排列）。
 *
 * 实现原理：
 *   使用 Floyd-Warshall 计算任意两点最短路径，然后 BFS 判断可达性。
 *   1. 使用邻接矩阵 dist[][] 存储站点间距离。
 *   2. 使用 Floyd-Warshall 算法计算所有站点对之间的最短路径。
 *   3. 使用 BFS 从起点出发，判断每个站点是否可达：
 *      a. 如果是到达该站点的最低票价站点，可达。
 *      b. 如果是终点站且票价相同，可达。
 *   4. 票价计算：fare = 2 + ceil(dist / k)。
 *
 * 时间复杂度：O(N^3 + M * N)，Floyd-Warshall 为 O(N^3)
 */
#define INF 0x3f3f3f3f
int main(void){int n,m,k,i,j,z,dist[205][205],terminal[205]={0};char line[4096];scanf("%d%d%d",&n,&m,&k);getchar();for(i=1;i<=n;++i)for(j=1;j<=n;++j)dist[i][j]=i==j?0:INF;
for(i=0;i<m;++i){int a[1000],cnt=0,prev=0,want_station=1;fgets(line,sizeof(line),stdin);{char *p=line;while(sscanf(p,"%d%n",&a[cnt],&z)==1){p+=z;++cnt;}}for(j=0;j<cnt;++j){if(want_station){if(!prev)terminal[a[j]]=1;prev=a[j];want_station=0;}else{int w=a[j],v=a[++j];if(w<dist[prev][v])dist[prev][v]=dist[v][prev]=w;prev=v;if(j==cnt-1)terminal[v]=1;want_station=0;}}}
for(z=1;z<=n;++z)for(i=1;i<=n;++i)for(j=1;j<=n;++j)if(dist[i][z]<INF&&dist[z][j]<INF&&dist[i][z]+dist[z][j]<dist[i][j])dist[i][j]=dist[i][z]+dist[z][j];
scanf("%d",&m);while(m--){int s,vis[205]={0},q[205],h=0,t=0;scanf("%d",&s);vis[s]=1;q[t++]=s;while(h<t){int u=q[h++];for(i=1;i<=n;++i)if(i!=u&&dist[u][i]<INF){int fare=2+(dist[u][i]+k-1)/k,far=1;for(j=1;j<=n;++j)if(dist[u][j]<INF&&j!=u&&2+(dist[u][j]+k-1)/k==fare&&dist[u][j]>dist[u][i]){far=0;break;}if((far||terminal[i])&&!vis[i])vis[i]=1,q[t++]=i;}}for(i=1,j=0;i<=n;++i)if(vis[i])printf("%s%d",j++?" ":"",i);putchar('\n');}
return 0;}
