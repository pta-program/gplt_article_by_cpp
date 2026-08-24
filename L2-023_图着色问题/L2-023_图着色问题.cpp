#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/**
 * L2-023 - 图着色问题
 * 
 * 实现原理：
 * 判断给定的颜色分配方案是否是图着色问题的一个解。
 * 条件：
 * 1. 使用的颜色数不超过K
 * 2. 相邻顶点颜色不同
 * 
 * 解题思路：
 * 1. 读取图的边信息
 * 2. 对每个方案检查两个条件
 * 3. 如果满足条件输出Yes，否则输出No
 */
int main() {
    int V, E, K;
    cin >> V >> E >> K;
    
    vector<vector<int>> adj(V + 1);
    
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        vector<int> color(V + 1);
        unordered_set<int> used_colors;
        
        bool valid = true;
        
        for (int j = 1; j <= V; j++) {
            cin >> color[j];
            used_colors.insert(color[j]);
        }
        
        if (used_colors.size() > K) {
            valid = false;
        }
        
        for (int j = 1; j <= V && valid; j++) {
            for (int neighbor : adj[j]) {
                if (color[j] == color[neighbor]) {
                    valid = false;
                    break;
                }
            }
        }
        
        if (valid) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}