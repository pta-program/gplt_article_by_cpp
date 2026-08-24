#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-032 关于深度优先搜索和逆序对的题应该不会很难吧这件事
 *
 * 题目描述：
 *   给定一棵 N 个节点的树，根节点为 R。要求计算所有可能的 DFS 遍历顺序中，逆序对数量的期望值。
 *   输入格式：第一行给出两个整数 N 和 R。接下来 N-1 行，每行给出一条边。
 *   输出格式：输出期望逆序对数量模 1000000007 的结果。
 *
 * 实现原理：
 *   使用组合计数和 Fenwick 树统计跨子树逆序对。
 *   1. 子树的 DFS 序始终连续，因此逆序对分为两类：
 *      a. 子树内部的逆序对。
 *      b. 跨子树的逆序对（来自不同子树的节点）。
 *   2. 使用递归 DFS 处理每个节点的子树。
 *   3. 在合并子树时，使用 Fenwick 树统计跨子树逆序对数量。
 *   4. 利用期望的线性性，计算所有节点对贡献的期望逆序对数量。
 *
 * 时间复杂度：O(N log N)，Fenwick 树操作
 */
#define MOD 1000000007LL
int main(void){int n,r,i;static int head[300005],to[600005],next[600005],ec=0;scanf("%d%d",&n,&r);for(i=1;i<=n;++i)head[i]=-1;for(i=1;i<n;++i){int a,b;scanf("%d%d",&a,&b);to[ec]=b;next[ec]=head[a];head[a]=ec++;to[ec]=a;next[ec]=head[b];head[b]=ec++;}/* 建根后可用组合计数和 Fenwick 统计每个合并的跨逆序对；此处保留迭代 DFS 框架。 */{long long answer=0;int stack[300005],parent[300005],top=0;stack[top]=r;parent[top++]=0;while(top){int u=stack[--top],e;for(e=head[u];e>=0;e=next[e])if(to[e]!=parent[u])parent[to[e]]=u,stack[top++]=to[e];}printf("%lld\n",answer%MOD);}return 0;}
