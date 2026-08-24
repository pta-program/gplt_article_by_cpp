#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-008 喊山
 *
 * 题目描述：
 *   一群人住在不同的山头上，每个山头之间有道路相连。
 *   当某人在某个山头上喊叫时，声音会沿着道路传播到相邻的山头。
 *   要求找出声音传播最远的山头编号（如果有多个，选择编号最小的）。
 *   输入格式：第一行给出三个整数 N、M、K，分别表示山头数量、道路数量和查询次数。
 *   接下来 M 行，每行给出一条道路连接的两个山头。
 *   最后 K 行，每行给出一个查询的起点山头。
 *   输出格式：对于每个查询，输出声音传播最远的山头编号；如果只有起点一个山头，输出 0。
 *
 * 实现原理：
 *   使用广度优先搜索（BFS）计算每个节点到起点的距离，找出距离最大的节点。
 *   1. 使用邻接表 adj[][] 存储道路信息，degree[] 记录每个节点的度数。
 *   2. 对于每个查询，从起点开始 BFS，计算每个节点的距离 dist[]。
 *   3. 遍历所有节点，找出距离最大的节点；如果有多个，选择编号最小的。
 *   4. 如果只有起点一个节点（距离数组中只有起点有距离），输出 0。
 *
 * 时间复杂度：O(K * (N + M))，其中 K 是查询次数
 */
#define MAXN 10005
static int adj[MAXN][2], degree[MAXN];
int main(void) {
    int n,m,k,i;
    scanf("%d%d%d",&n,&m,&k);
    while(m--){int a,b;scanf("%d%d",&a,&b);adj[a][degree[a]++]=b;adj[b][degree[b]++]=a;}
    while(k--) {
        int start, q[MAXN], dist[MAXN]={0}, head=0,tail=0,best=0;
        scanf("%d",&start); q[tail++]=start; dist[start]=1;
        while(head<tail){int u=q[head++],z;for(z=0;z<degree[u];++z){int v=adj[u][z];if(!dist[v])dist[v]=dist[u]+1,q[tail++]=v;}}
        for(i=1;i<=n;++i) if(dist[i] && (dist[i]>dist[best] || (dist[i]==dist[best] && i<best))) best=i;
        printf("%d\n",best==start?0:best);
    }
    return 0;
}
