#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-017 森森快递
 *
 * 题目描述：
 *   森森快递有 N-1 条运输线路，每条线路有一个容量限制。
 *   有 Q 个订单，每个订单需要从线路 l 到线路 r（包含两端）之间的所有线路运输货物。
 *   要求最大化所有订单的货物总量，每个订单可以选择运输任意数量的货物（不超过每条线路的剩余容量）。
 *   输入格式：第一行给出整数 N 和 Q。第二行给出 N-1 个整数，表示每条线路的容量。
 *   接下来 Q 行，每行给出两个整数 l 和 r，表示订单的线路范围。
 *   输出格式：输出最大货物总量。
 *
 * 实现原理：
 *   使用贪心算法，按订单的右端点排序，依次处理每个订单。
 *   1. 将订单按右端点 r 从小到大排序。
 *   2. 对于每个订单 [l, r]，取该区间内所有线路剩余容量的最小值作为运输量。
 *   3. 将该运输量从区间内所有线路的剩余容量中扣除。
 *   4. 累加到总运输量中。
 *   这种贪心策略利用了区间矩阵的连续 1 性质，保证了最优解。
 *
 * 时间复杂度：O(Q * N)，可以通过线段树优化到 O(Q * log N)
 */
typedef struct {int l,r;} Order;
static int cmp(const void*a,const void*b){return ((Order*)a)->r-((Order*)b)->r;}
int main(void){int n,q,i;long long ans=0,*cap;Order *a;scanf("%d%d",&n,&q);cap = (decltype(cap))malloc((n-1)*sizeof(long long));a = (decltype(a))malloc(q*sizeof(Order));for(i=0;i<n-1;++i)scanf("%lld",&cap[i]);for(i=0;i<q;++i){scanf("%d%d",&a[i].l,&a[i].r);if(a[i].l>a[i].r){int t=a[i].l;a[i].l=a[i].r;a[i].r=t;}}qsort(a,q,sizeof(Order),cmp);for(i=0;i<q;++i){int j;long long take=cap[a[i].l];for(j=a[i].l+1;j<a[i].r;++j)if(cap[j]<take)take=cap[j];for(j=a[i].l;j<a[i].r;++j)cap[j]-=take;ans+=take;}printf("%lld\n",ans);free(cap);free(a);return 0;}
