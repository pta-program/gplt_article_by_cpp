#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-021 神坛
 *
 * 题目描述：
 *   给定 N 个点的坐标，要求找出面积最小的三角形（由三个点构成）。
 *   输入格式：第一行给出整数 N。接下来 N 行，每行给出两个整数表示点的坐标。
 *   输出格式：输出最小三角形面积，保留三位小数。
 *
 * 实现原理：
 *   枚举所有三点组合，使用叉积计算三角形面积。
 *   1. 三角形面积 = 1/2 * |(b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x)|。
 *   2. 使用两倍面积进行比较（避免浮点运算误差）。
 *   3. 枚举所有 i < j < k 的三点组合，计算面积并记录最小值。
 *   4. 最后将最小面积除以 2.0 输出。
 *
 * 时间复杂度：O(N^3)，其中 N 是点的数量
 */
typedef struct {long long x,y;} Point;
static long long area2(Point a,Point b,Point c){long long v=(b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);return v<0?-v:v;}
int main(void){int n,i,j,k;long long best=0x7fffffffffffffffLL;Point *p;scanf("%d",&n);p = (decltype(p))malloc((size_t)n*sizeof(Point));for(i=0;i<n;++i)scanf("%lld%lld",&p[i].x,&p[i].y);for(i=0;i<n;++i)for(j=i+1;j<n;++j)for(k=j+1;k<n;++k){long long s=area2(p[i],p[j],p[k]);if(s<best)best=s;}printf("%.3f\n",best/2.0);free(p);return 0;}
