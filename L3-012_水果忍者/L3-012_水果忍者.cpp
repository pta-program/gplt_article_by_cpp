#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-012 水果忍者
 *
 * 题目描述：
 *   在游戏水果忍者中，玩家需要用刀切开水果。每个水果占据一条竖直区间。
 *   给定 N 个水果的 x 坐标和各自的上下边界 y_lo、y_hi，要求找到一条直线，
 *   能够切到所有水果，并且输出直线上的两个整数点坐标。
 *   输入格式：第一行给出整数 N。接下来 N 行，每行给出三个整数 x、y_lo、y_hi。
 *   输出格式：输出直线上的两个整数点坐标 (x1, y1) 和 (x2, y2)。
 *
 * 实现原理：
 *   使用二分法（迭代）在斜率区间内搜索可行的直线斜率。
 *   1. 将直线表示为 y = a*x + b，其中 a 是斜率，b 是截距。
 *   2. 对固定斜率 a，截距 b 必须满足：lo[i] - a*x[i] <= b <= hi[i] - a*x[i]，对所有 i。
 *   3. 维护斜率区间 [low, up]，初始时 low = -∞，up = +∞。
 *   4. 每次迭代：
 *      a. 选择当前区间的中点作为候选斜率 cur。
 *      b. 计算所有水果对应的 b 区间的交集 [bestL, bestU]。
 *      c. 如果交集非空，找到可行直线，输出结果。
 *      d. 如果交集为空，根据约束条件缩小斜率区间。
 *   5. 使用分数表示斜率，避免浮点数精度问题。
 *
 * 时间复杂度：O(N * log(MAX_COORD))，其中 MAX_COORD 是坐标范围
 */
typedef struct { long long num, den; } Frac;
static int cmp(Frac a, Frac b) { __int128 x=(__int128)a.num*b.den,y=(__int128)b.num*a.den; return x>y?1:x<y?-1:0; }
static Frac norm(long long n,long long d){if(d<0)n=-n,d=-d;return (Frac){n,d};}
int main(void){
    int n,i,round; long long *x,*hi,*lo; Frac low={-1,0},up={1,0},cur={0,1};
    scanf("%d",&n);x = (decltype(x))malloc((size_t)n*sizeof(long long));hi = (decltype(hi))malloc((size_t)n*sizeof(long long));lo = (decltype(lo))malloc((size_t)n*sizeof(long long));
    for(i=0;i<n;++i)scanf("%lld%lld%lld",&x[i],&hi[i],&lo[i]);
    for(round=0;round<100;++round){
        int p=0,q=0; __int128 bestL=(__int128)lo[0]*cur.den-(__int128)cur.num*x[0],bestU=(__int128)hi[0]*cur.den-(__int128)cur.num*x[0];
        for(i=1;i<n;++i){__int128 L=(__int128)lo[i]*cur.den-(__int128)cur.num*x[i],U=(__int128)hi[i]*cur.den-(__int128)cur.num*x[i];if(L>bestL)bestL=L,p=i;if(U<bestU)bestU=U,q=i;}
        if(bestL<=bestU){ /* 取最紧下界，直线通过对应水果的下端点，故可输出整数点。 */
            long long dx=cur.den,dy=cur.num; printf("%lld %lld %lld %lld\n",x[p],lo[p],x[p]+dx,lo[p]+dy); free(x);free(hi);free(lo);return 0;
        }
        /* 违反的两条约束给出 a*(xq-xp) <= hi[q]-lo[p]，据此缩小斜率区间。 */
        {Frac bound=norm(hi[q]-lo[p],x[q]-x[p]);if(x[q]>x[p]){if(up.den==0||cmp(bound,up)<0)up=bound;}else if(x[q]<x[p]){if(low.den==0||cmp(bound,low)>0)low=bound;}}
        if(low.den&&cmp((Frac){0,1},low)<0)cur=low; else if(up.den&&cmp((Frac){0,1},up)>0)cur=up; else cur=(Frac){0,1};
    }
    free(x);free(hi);free(lo);return 0;
}
