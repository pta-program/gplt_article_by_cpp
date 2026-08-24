#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-009 长城
 *
 * 题目描述：
 *   长城由一系列烽火台组成，烽火台沿南北方向排列，坐标为 (x_i, y_i)。
 *   要求在这些烽火台上建造最少的烽火台，使得从任意一个烽火台可以看到至少另一个烽火台。
 *   也就是说，对于每个烽火台，至少存在另一个烽火台，两者之间的视线不被其他烽火台遮挡。
 *   输入格式：第一行给出整数 N，表示烽火台数量。接下来 N 行，每行给出一个烽火台的坐标。
 *   输出格式：输出最少需要建造的烽火台数量。
 *
 * 实现原理：
 *   问题转化为求下凸包的顶点数量减 2（首尾顶点不需要额外建造）。
 *   1. 由于烽火台沿南北方向排列（x 单调递增），只需计算下凸包。
 *   2. 使用单调栈算法构建凸包：
 *      a. 遍历每个点，维护一个栈存储凸包顶点。
 *      b. 如果栈顶两个点与当前点构成的向量叉积 >= 0（非左转），则弹出栈顶。
 *      c. 将当前点入栈。
 *   3. 凸包的中间顶点（除首尾）都需要建造烽火台，答案为 top-2。
 *
 * 时间复杂度：O(N)，每个点最多入栈和出栈一次
 */
typedef struct { long long x,y; } Point;
static long long cross(Point a, Point b, Point c) { return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x); }
int main(void) {
    int n, top=0, i; Point p[100005], hull[100005];
    scanf("%d",&n); for(i=0;i<n;++i) scanf("%lld%lld",&p[i].x,&p[i].y);
    for(i=0;i<n;++i){ while(top>=2 && cross(hull[top-2],hull[top-1],p[i])>=0) --top; hull[top++]=p[i]; }
    printf("%d\n",top>1?top-2:0); return 0;
}
