#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-025 那就别担心了
 *
 * 题目描述：
 *   给定一个有向无环图（DAG），要求：
 *   1. 计算从节点 A 到节点 B 的路径数量。
 *   2. 判断从 A 出发是否一定能到达 B（即 A 可达的所有节点中，只有 B 是终点）。
 *   输入格式：第一行给出两个整数 N 和 M，分别表示节点数和边数。
 *   接下来 M 行，每行给出一条有向边 x->y。
 *   最后一行给出两个整数 A 和 B。
 *   输出格式：第一行输出路径数量和 "Yes" 或 "No"（表示是否一定能到达 B）。
 *
 * 实现原理：
 *   使用记忆化搜索计算路径数量，同时检查终点唯一性。
 *   1. 使用邻接表存储图结构。
 *   2. 使用 DFS 标记所有从 A 可达的节点。
 *   3. 使用记忆化搜索（动态规划）计算从 A 到 B 的路径数：
 *      paths(u, b) = sum(paths(v, b)) for all v in adj[u]
 *      边界条件：paths(b, b) = 1
 *   4. 检查 A 可达子图中是否存在除 B 以外的终点（出度为 0 的节点）。
 *
 * 时间复杂度：O(N + M)，DFS 和记忆化搜索各遍历一次
 */
static int n,head[505],to[5005],next[5005],ec,reach[505],memo[505];
static long long paths(int u,int b){int e;if(u==b)return 1;if(memo[u]>=0)return memo[u];memo[u]=0;for(e=head[u];e>=0;e=next[e])memo[u]+=paths(to[e],b);return memo[u];}
static void mark(int u){int e;if(reach[u])return;reach[u]=1;for(e=head[u];e>=0;e=next[e])mark(to[e]);}
int main(void){int m,a,b,i,u,ok=1;scanf("%d%d",&n,&m);for(i=1;i<=n;++i)head[i]=-1;while(m--){int x,y;scanf("%d%d",&x,&y);to[ec]=y;next[ec]=head[x];head[x]=ec++;}scanf("%d%d",&a,&b);mark(a);for(i=1;i<=n;++i)memo[i]=-1;for(u=1;u<=n;++u)if(reach[u]&&u!=b&&head[u]<0)ok=0;printf("%lld %s\n",paths(a,b),ok?"Yes":"No");return 0;}
