#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-006 迎风一刀斩
 *
 * 题目描述：
 *   一张矩形纸片被一刀切成了两块。给定两块残片的边界点序列，判断它们是否能拼成原来的矩形。
 *   输入格式：第一行给出测试用例数 N。对于每个测试用例，先给出第一块残片的顶点数和坐标，
 *   再给出第二块残片的顶点数和坐标。顶点按边界顺序给出。
 *   输出格式：对于每个测试用例，输出 "YES" 或 "NO"。
 *
 * 实现原理：
 *   枚举两块残片中可能是刀口的边，将第二块刚体变换后与第一块拼接，判断是否能形成矩形。
 *   1. 枚举所有可能的刀口对（a 的边 i 和 b 的边 j）。
 *   2. 检查两条边长度是否相等（精度范围内）。
 *   3. 将 a 的外边界（除刀口外）作为一组边。
 *   4. 将 b 的外边界反向，通过正交变换映射使其刀口与 a 的刀口反向重合。
 *   5. 合并同向共线的边。
 *   6. 判断合并后的边是否构成矩形：
 *      a. 恰好四条边。
 *      b. 相邻边互相垂直。
 *      c. 对边互为相反向量。
 *
 * 时间复杂度：O(N^2 * (na + nb))，其中 na、nb 分别是两块残片的顶点数
 */

typedef struct { long double x, y; } Point;
typedef struct { long double x, y; } Vec;

static Vec sub(Point a, Point b) { Vec v = {a.x - b.x, a.y - b.y}; return v; }
static long double dot(Vec a, Vec b) { return a.x * b.x + a.y * b.y; }
static long double cross(Vec a, Vec b) { return a.x * b.y - a.y * b.x; }
static int same_direction(Vec a, Vec b) { return fabsl(cross(a,b)) < 1e-7L && dot(a,b) > 0; }
static int can_join(Point a[], int na, Point b[], int nb) {
    int i, j;
    for (i = 0; i < na; ++i) for (j = 0; j < nb; ++j) {
        Vec cuta = sub(a[(i + 1) % na], a[i]);
        Vec cutb = sub(b[(j + 1) % nb], b[j]);
        long double la = dot(cuta, cuta), lb = dot(cutb, cutb);
        Vec edge[24], merged[24]; int ne = 0, nm = 0, t;
        if (fabsl(la - lb) > 1e-6L || la < 1e-12L) continue;

        /* A 从刀口终点沿外边界走回刀口起点。 */
        for (t = 0; t < na - 1; ++t) {
            int p = (i + 1 + t) % na, q = (p + 1) % na;
            edge[ne++] = sub(a[q], a[p]);
        }
        /* B 的外边界反向走；映射使其刀口与 A 的刀口反向重合。 */
        for (t = 0; t < nb - 1; ++t) {
            int p = (j - t + nb) % nb, q = (p - 1 + nb) % nb;
            Vec w = sub(b[q], b[p]), r;
            /* 把 cutb 旋/翻到 -cuta；长度相等时这是一个正交变换。 */
            r.x = (-cuta.x * dot(w, cutb) + cuta.y * cross(w, cutb)) / la;
            r.y = (-cuta.y * dot(w, cutb) - cuta.x * cross(w, cutb)) / la;
            edge[ne++] = r;
        }
        for (t = 0; t < ne; ++t) {
            if (nm && same_direction(merged[nm - 1], edge[t])) {
                merged[nm - 1].x += edge[t].x; merged[nm - 1].y += edge[t].y;
            } else merged[nm++] = edge[t];
        }
        if (nm > 1 && same_direction(merged[nm - 1], merged[0])) {
            merged[0].x += merged[nm - 1].x; merged[0].y += merged[nm - 1].y; --nm;
        }
        if (nm == 4 && fabsl(dot(merged[0], merged[1])) < 1e-6L &&
            fabsl(dot(merged[1], merged[2])) < 1e-6L &&
            fabsl(merged[0].x + merged[2].x) < 1e-6L && fabsl(merged[0].y + merged[2].y) < 1e-6L &&
            fabsl(merged[1].x + merged[3].x) < 1e-6L && fabsl(merged[1].y + merged[3].y) < 1e-6L) return 1;
    }
    return 0;
}
int main(void) {
    int n, c;
    scanf("%d", &n);
    while (n--) {
        Point a[10], b[10]; int na, nb, i;
        scanf("%d", &na); for (i = 0; i < na; ++i) scanf("%Lf%Lf", &a[i].x, &a[i].y);
        scanf("%d", &nb); for (i = 0; i < nb; ++i) scanf("%Lf%Lf", &b[i].x, &b[i].y);
        puts(can_join(a, na, b, nb) ? "YES" : "NO");
    }
    return 0;
}
