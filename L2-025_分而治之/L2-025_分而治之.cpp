#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/**
 * L2-025 - 分而治之
 * 
 * 实现原理：
 * 判断攻击方案是否可行。
 * 可行条件：攻击后剩余城市之间没有通路（即每个剩余城市都是孤立的）。
 * 
 * 解题思路：
 * 1. 读取图的边信息
 * 2. 对每个方案，检查每条边的两个端点是否至少有一个被攻击
 * 3. 如果所有边都满足条件，则方案可行
 */
int main() {
    int N, M;
    cin >> N >> M;
    
    vector<pair<int, int>> edges;
    
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    
    int K;
    cin >> K;
    
    for (int i = 0; i < K; i++) {
        int Np;
        cin >> Np;
        
        unordered_set<int> attacked;
        for (int j = 0; j < Np; j++) {
            int city;
            cin >> city;
            attacked.insert(city);
        }
        
        bool feasible = true;
        for (auto& edge : edges) {
            int u = edge.first;
            int v = edge.second;
            
            if (attacked.find(u) == attacked.end() && attacked.find(v) == attacked.end()) {
                feasible = false;
                break;
            }
        }
        
        if (feasible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}