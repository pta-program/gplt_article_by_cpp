#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-026 传送门
 *
 * 题目描述：
 *   机器人从 x 轴出发沿 y 轴正方向移动，途中会遇到传送门。
 *   每个传送门连接两个横坐标 a 和 b，当机器人到达传送门高度时，
 *   如果它的横坐标是 a，则被传送到 b；如果是 b，则被传送到 a。
 *   要求动态维护传送门（添加/删除），并计算最终每个初始位置 i 的机器人最终位置 f[i]，
 *   以及 sum(i * f[i]) 的值。
 *   输入格式：第一行给出两个整数 N 和 Q，分别表示初始位置数和操作数。
 *   接下来 Q 行，每行给出一个操作：
 *   "+ x1 x2 y" 添加一个传送门，连接 x1 和 x2，位于高度 y。
 *   "- x1 x2 y" 删除指定的传送门。
 *   输出格式：每次操作后，输出 sum(i * f[i]) 的值。
 *
 * 实现原理：
 *   将传送门视为横坐标的置换，按高度顺序依次应用。
 *   1. 维护当前活跃的传送门列表。
 *   2. 每次操作后，重建横坐标的置换映射 f[]：
 *      a. 初始时 f[i] = i。
 *      b. 按传送门高度从小到大排序。
 *      c. 依次应用每个传送门：交换 f[a] 和 f[b]。
 *   3. 计算 sum(i * f[i]) 并输出。
 *
 * 时间复杂度：O(Q * (K + N))，其中 K 是传送门数量
 */
typedef struct {int x,y,a,b,alive;} Gate;
static int cmp(const void*p,const void*q){return ((Gate*)p)->y-((Gate*)q)->y;}
int main(void){int n,q,i,gc=0;Gate *g;scanf("%d%d",&n,&q);g = (decltype(g))calloc((size_t)q,sizeof(Gate));while(q--){char op;int x1,x2,y,j;scanf(" %c%d%d%d",&op,&x1,&x2,&y);if(op=='+')g[gc++]=(Gate){x1,y,x1,x2,1};else for(j=0;j<gc;++j)if(g[j].alive&&g[j].x==x1&&g[j].a==x1&&g[j].b==x2&&g[j].y==y){g[j].alive=0;break;}/* 重建当前置换；正式大规模版本可把按 y 的置换维护在平衡树中。 */{int *f = (decltype(f))malloc((size_t)(n+1)*sizeof(int)),cnt=0;long long ans=0;for(i=1;i<=n;++i)f[i]=i;for(i=0;i<gc;++i)if(g[i].alive)g[cnt++]=g[i];qsort(g,cnt,sizeof(Gate),cmp);for(i=0;i<cnt;++i){int t=f[g[i].a];f[g[i].a]=f[g[i].b];f[g[i].b]=t;}for(i=1;i<=n;++i)ans+=(long long)i*f[i];printf("%lld\n",ans);free(f);}}
free(g);return 0;}
