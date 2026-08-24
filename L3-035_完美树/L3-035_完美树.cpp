#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-035 完美树
 *
 * 题目描述：
 *   给定一棵 N 个节点的树，每个节点有一个颜色（黑或白）和一个翻转费用。
 *   要求通过翻转某些节点的颜色，使得每个节点的黑白颜色差的绝对值不超过 1。
 *   即对于每个节点，其所有后代（包括自身）中黑节点数与白节点数之差的绝对值 ≤ 1。
 *   输入格式：第一行给出整数 N。接下来 N 行，每行给出节点的颜色、翻转费用和子节点数量及子节点列表。
 *   输出格式：输出最小翻转费用。
 *
 * 实现原理：
 *   使用树形动态规划计算最小翻转费用。
 *   1. 定义 dp[u][d+1]：使节点 u 的子树中黑白差为 d（-1、0、1）的最小翻转费用。
 *   2. 使用背包 DP 合并子树状态：
 *      a. 对于每个子节点 v，将其 dp[v][*] 合并到当前节点的状态中。
 *   3. 状态转移：
 *      a. 选择当前节点的颜色（黑或白），计算所需的翻转费用。
 *      b. 确保最终黑白差在 [-1, 1] 范围内。
 *   4. 根节点的答案为 min(dp[1][0], dp[1][1], dp[1][2])。
 *
 * 时间复杂度：O(N)，每个节点的 DP 状态只有 3 种
 */
#define INF (1LL<<60)
typedef long long ll; static int n,ch[100005][20],cc[100005],color[100005];static ll cost[100005];
static void dfs(int u,ll dp[][3]){int i,j,k;ll f[205]={0},g[205];int off=100;for(i=0;i<201;++i)f[i]=INF;f[off]=0;for(i=0;i<cc[u];++i){int v=ch[u][i];dfs(v,dp);for(j=0;j<201;++j)g[j]=INF;for(j=0;j<201;++j)for(k=-1;k<=1;++k)if(f[j]<INF&&j+k>=0&&j+k<201&&dp[v][k+1]<INF&&f[j]+dp[v][k+1]<g[j+k])g[j+k]=f[j]+dp[v][k+1];for(j=0;j<201;++j)f[j]=g[j];}for(j=-1;j<=1;++j){dp[u][j+1]=INF;for(k=-1;k<=1;++k){int own=k;/* own is chosen color difference */if(j-own+off>=0&&j-own+off<201){ll add=(color[u]==(own==1)?0:cost[u]);if(f[j-own+off]+add<dp[u][j+1])dp[u][j+1]=f[j-own+off]+add;}}}}
int main(void){static ll dp[100005][3];int i,j;scanf("%d",&n);for(i=1;i<=n;++i){scanf("%d%lld%d",&color[i],&cost[i],&cc[i]);for(j=0;j<cc[i];++j)scanf("%d",&ch[i][j]);}dfs(1,dp);printf("%lld\n",dp[1][0]<dp[1][1]?(dp[1][0]<dp[1][2]?dp[1][0]:dp[1][2]):(dp[1][1]<dp[1][2]?dp[1][1]:dp[1][2]));return 0;}
