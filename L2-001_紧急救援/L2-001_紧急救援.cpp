#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

/**
 * L2-001 - 紧急救援
 * 
 * 实现原理：
 * 使用 Dijkstra 算法求解最短路径。
 * 需要同时记录：
 * 1. 最短路径的长度
 * 2. 最短路径的条数
 * 3. 最短路径上能召集的最多救援队数量
 * 4. 最短路径的具体路径
 * 
 * 解题思路：
 * 1. 构建邻接表表示图
 * 2. 使用 Dijkstra 算法：
 *    - dist[]: 记录最短距离
 *    - count[]: 记录最短路径条数
 *    - rescue[]: 记录最多救援队数量
 *    - prev[]: 记录路径前驱
 * 3. 从终点回溯得到路径
 * 4. 输出结果
 */
const int MAXN = 505;
const int INF = INT_MAX;

struct Edge {
    int to, length;
    Edge(int t, int l) : to(t), length(l) {}
};

vector<Edge> graph[MAXN];
int rescue_team[MAXN];
int dist[MAXN];
int count_path[MAXN];
int max_rescue[MAXN];
int prev_node[MAXN];
bool visited[MAXN];

int main() {
    int N, M, S, D;
    cin >> N >> M >> S >> D;
    
    for (int i = 0; i < N; i++) {
        cin >> rescue_team[i];
    }
    
    for (int i = 0; i < M; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        graph[a].push_back(Edge(b, l));
        graph[b].push_back(Edge(a, l));
    }
    
    // 初始化
    for (int i = 0; i < N; i++) {
        dist[i] = INF;
        count_path[i] = 0;
        max_rescue[i] = 0;
        prev_node[i] = -1;
        visited[i] = false;
    }
    
    dist[S] = 0;
    count_path[S] = 1;
    max_rescue[S] = rescue_team[S];
    
    // Dijkstra 算法
    for (int i = 0; i < N; i++) {
        // 找到距离最小的节点
        int u = -1, min_dist = INF;
        for (int j = 0; j < N; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }
        
        if (u == -1) break;
        visited[u] = true;
        
        for (Edge e : graph[u]) {
            int v = e.to;
            int w = e.length;
            
            if (!visited[v]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    count_path[v] = count_path[u];
                    max_rescue[v] = max_rescue[u] + rescue_team[v];
                    prev_node[v] = u;
                } else if (dist[v] == dist[u] + w) {
                    count_path[v] += count_path[u];
                    if (max_rescue[v] < max_rescue[u] + rescue_team[v]) {
                        max_rescue[v] = max_rescue[u] + rescue_team[v];
                        prev_node[v] = u;
                    }
                }
            }
        }
    }
    
    // 输出结果
    cout << count_path[D] << " " << max_rescue[D] << endl;
    
    // 回溯路径
    vector<int> path;
    int curr = D;
    while (curr != -1) {
        path.push_back(curr);
        curr = prev_node[curr];
    }
    reverse(path.begin(), path.end());
    
    for (size_t i = 0; i < path.size(); i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << path[i];
    }
    cout << endl;
    
    return 0;
}