#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <climits>
using namespace std;

/**
 * L2-036 - 网红点打卡攻略
 * 
 * 实现原理：
 * 判断攻略是否有效，并找出花费最少的有效攻略。
 * 有效攻略条件：
 * 1. 每个网红点打卡仅一次
 * 2. 能从家里出发并回到家里
 * 
 * 解题思路：
 * 1. 使用邻接矩阵存储图
 * 2. 对每个攻略检查有效性和计算花费
 * 3. 找出花费最少的有效攻略
 */
int main() {
    int N, M;
    cin >> N >> M;
    
    unordered_map<int, unordered_map<int, int>> graph;
    
    for (int i = 0; i < M; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        graph[u][v] = cost;
        graph[v][u] = cost;
    }
    
    int K;
    cin >> K;
    
    int valid_count = 0;
    int best_index = -1;
    int min_cost = INT_MAX;
    
    for (int idx = 1; idx <= K; idx++) {
        int n;
        cin >> n;
        
        vector<int> path(n);
        for (int i = 0; i < n; i++) {
            cin >> path[i];
        }
        
        unordered_set<int> visited;
        bool valid = true;
        
        for (int v : path) {
            if (visited.count(v)) {
                valid = false;
                break;
            }
            visited.insert(v);
        }
        
        if (!valid || visited.size() != N) continue;
        
        int total_cost = 0;
        
        if (graph[0].find(path[0]) == graph[0].end()) {
            valid = false;
        } else {
            total_cost += graph[0][path[0]];
        }
        
        for (int i = 0; i < n - 1 && valid; i++) {
            int u = path[i];
            int v = path[i + 1];
            if (graph[u].find(v) == graph[u].end()) {
                valid = false;
            } else {
                total_cost += graph[u][v];
            }
        }
        
        if (valid && graph[0].find(path.back()) == graph[0].end()) {
            valid = false;
        } else if (valid) {
            total_cost += graph[0][path.back()];
        }
        
        if (valid) {
            valid_count++;
            
            if (total_cost < min_cost || (total_cost == min_cost && idx < best_index)) {
                min_cost = total_cost;
                best_index = idx;
            }
        }
    }
    
    cout << valid_count << endl;
    cout << best_index << " " << min_cost << endl;
    
    return 0;
}