#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-005 垃圾箱分布
 *
 * 题目描述：
 *   在一个城市中，有若干居民点和若干候选垃圾箱站点。
 *   要求选择一个候选站点安装垃圾箱，使得：
 *   1. 所有居民点到该站点的距离都不超过给定的限制。
 *   2. 所有居民点到该站点的最近距离尽可能大（第一目标）。
 *   3. 在满足条件 1 和 2 的情况下，所有居民点到该站点的平均距离尽可能小（第二目标）。
 *   输入格式：第一行给出四个整数 N、M、K、DS，分别表示居民点数量、候选站点数量、道路数量和距离限制。
 *   接下来 K 行，每行给出一条道路的信息（两个端点和长度）。
 *   输出格式：如果存在可行站点，输出站点编号、最近距离和平均距离；否则输出 "No Solution"。
 *
 * 实现原理：
 *   使用 Dijkstra 算法计算每个候选站点到所有居民点的最短距离。
 *   1. 构建邻接矩阵 graph[][] 存储道路信息。
 *   2. 居民点编号为 1~N，候选站点编号为 N+1~N+M。
 *   3. 对每个候选站点执行 Dijkstra 算法，计算到所有居民点的最短距离。
 *   4. 检查可行性：所有居民点距离 <= DS。
 *   5. 选择最优站点：
 *      a. 第一优先级：最大化最近居民点距离。
 *      b. 第二优先级：最小化平均距离。
 *      c. 第三优先级：选择编号最小的站点。
 *
 * 时间复杂度：O(M * (N+M)^2)，其中 M 是候选站点数量，N 是居民点数量
 */
#define MAXV 1015
#define INF 0x3f3f3f3f
static int graph[MAXV][MAXV];
static int get_id(const char *s, int n) { return s[0] == 'G' ? n + atoi(s + 1) : atoi(s); }
static void dijkstra(int source, int vertices, int dist[]) {
    int used[MAXV] = {0}, i, step;
    for (i = 1; i <= vertices; ++i) dist[i] = graph[source][i];
    dist[source] = 0;
    for (step = 1; step <= vertices; ++step) {
        int u = -1, best = INF;
        for (i = 1; i <= vertices; ++i) if (!used[i] && dist[i] < best) best = dist[i], u = i;
        if (u == -1) break;
        used[u] = 1;
        for (i = 1; i <= vertices; ++i)
            if (!used[i] && graph[u][i] < INF && dist[u] + graph[u][i] < dist[i]) dist[i] = dist[u] + graph[u][i];
    }
}
int main(void) {
    int n, m, k, limit, vertices, i, j, best_station = -1, best_min = -1;
    double best_average = INF;
    if (scanf("%d%d%d%d", &n, &m, &k, &limit) != 4) return 0;
    vertices = n + m;
    for (i = 1; i <= vertices; ++i) for (j = 1; j <= vertices; ++j) graph[i][j] = i == j ? 0 : INF;
    while (k--) {
        char a[12], b[12]; int x, y, length;
        scanf("%s%s%d", a, b, &length); x = get_id(a, n); y = get_id(b, n);
        if (length < graph[x][y]) graph[x][y] = graph[y][x] = length;
    }
    for (i = n + 1; i <= vertices; ++i) {
        int dist[MAXV], minimum = INF, feasible = 1; double sum = 0.0, average;
        dijkstra(i, vertices, dist);
        for (j = 1; j <= n; ++j) {
            if (dist[j] > limit) { feasible = 0; break; }
            if (dist[j] < minimum) minimum = dist[j];
            sum += dist[j];
        }
        if (!feasible) continue;
        average = sum / n;
        /* 第一目标最大化最近居民距离，第二目标最小化平均距离；同分时保留较小编号。 */
        if (minimum > best_min || (minimum == best_min && average < best_average)) best_station = i, best_min = minimum, best_average = average;
    }
    if (best_station == -1) printf("No Solution\n");
    else printf("G%d\n%.1f %.1f\n", best_station - n, (double)best_min + 1e-8, best_average + 1e-8);
    return 0;
}
