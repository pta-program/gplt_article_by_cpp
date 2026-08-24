#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-003 社交集群
 *
 * 题目描述：
 *   在社交网络中，如果两个人有共同的兴趣，他们就会成为朋友，从而形成社交集群。
 *   给定每个人的兴趣爱好列表，求社交集群的数量及每个集群的人数。
 *   输入格式：第一行给出人数 N。接下来 N 行，每行先给出一个整数 K，表示该人有 K 个兴趣，
 *   然后给出 K 个整数表示具体的兴趣编号。
 *   输出格式：第一行输出社交集群的数量，第二行按降序输出每个集群的人数。
 *
 * 实现原理：
 *   使用并查集（Union-Find）数据结构求解连通分量问题。
 *   1. 初始化：每个人初始时属于自己的集合（parent[i] = i）。
 *   2. 使用 owner[h] 记录兴趣 h 的第一个拥有者。
 *   3. 遍历每个人的兴趣列表：
 *      a. 如果兴趣 h 还没有拥有者，记录当前人为该兴趣的拥有者。
 *      b. 如果兴趣 h 已有拥有者，将当前人与该拥有者合并到同一集合。
 *   4. 统计每个根节点对应的集合大小。
 *   5. 按集合大小降序排序并输出。
 *
 * 时间复杂度：O(N * K * α(N))，其中 α 是阿克曼函数的反函数，近似为常数
 */
int parent[1001], size[1001];
static int find_set(int x) { return parent[x] == x ? x : (parent[x] = find_set(parent[x])); }
static void unite(int a, int b) { a = find_set(a); b = find_set(b); if (a != b) parent[b] = a; }
static int cmp_desc(const void *a, const void *b) { return *(const int *)b - *(const int *)a; }
int main(void) {
    int n, owner[1001] = {0}, i, groups[1001], count = 0;
    if (scanf("%d", &n) != 1) return 0; for (i = 1; i <= n; ++i) parent[i] = i;
    for (i = 1; i <= n; ++i) { int k; scanf("%d:", &k); while (k--) { int h; scanf("%d", &h); if (owner[h]) unite(i, owner[h]); else owner[h] = i; } }
    for (i = 1; i <= n; ++i) ++size[find_set(i)];
    for (i = 1; i <= n; ++i) if (size[i]) groups[count++] = size[i]; qsort(groups, count, sizeof(int), cmp_desc);
    printf("%d\n", count); for (i = 0; i < count; ++i) printf("%s%d", i ? " " : "", groups[i]); putchar('\n'); return 0;
}
