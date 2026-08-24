#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * L2-020 - 功夫传人
 * 
 * 实现原理：
 * 计算所有得道者的功力总值。
 * 每传一代功夫减弱r%，得道者的功夫会被放大N倍。
 * 
 * 解题思路：
 * 1. 使用广度优先搜索遍历整个师门谱系
 * 2. 计算每个弟子的功力值
 * 3. 如果是得道者，将其功力值加入总和
 */
int main() {
    int N;
    double Z, r;
    cin >> N >> Z >> r;
    
    vector<vector<int>> children(N);
    vector<bool> is_enlightened(N, false);
    vector<int> multiplier(N, 0);
    
    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;
        
        if (K == 0) {
            is_enlightened[i] = true;
            cin >> multiplier[i];
        } else {
            children[i].resize(K);
            for (int j = 0; j < K; j++) {
                cin >> children[i][j];
            }
        }
    }
    
    double total = 0;
    queue<pair<int, double>> q;
    q.push({0, Z});
    
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        
        int id = curr.first;
        double power = curr.second;
        
        if (is_enlightened[id]) {
            total += power * multiplier[id];
            continue;
        }
        
        double next_power = power * (1 - r / 100);
        for (int child : children[id]) {
            q.push({child, next_power});
        }
    }
    
    cout << (int)total << endl;
    
    return 0;
}