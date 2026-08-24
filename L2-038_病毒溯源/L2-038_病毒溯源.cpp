#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * L2-038 - 病毒溯源
 * 
 * 实现原理：
 * 找出病毒变异的最长链。
 * 规则：
 * 1. 每一种病毒由唯一的一种病毒突变而来
 * 2. 不存在循环变异
 * 3. 如果最长链不唯一，输出最小序列
 * 
 * 解题思路：
 * 1. 使用邻接表存储病毒变异关系
 * 2. 找出病毒源头（入度为0的节点）
 * 3. 使用DFS或BFS找最长路径
 * 4. 路径长度相同选择字典序最小的
 */
vector<vector<int>> children;
vector<int> max_path;
vector<int> current_path;
int max_length = 0;

void dfs(int node) {
    current_path.push_back(node);
    
    if (current_path.size() > max_length) {
        max_length = current_path.size();
        max_path = current_path;
    } else if (current_path.size() == max_length) {
        for (int i = 0; i < current_path.size(); i++) {
            if (current_path[i] < max_path[i]) {
                max_path = current_path;
                break;
            } else if (current_path[i] > max_path[i]) {
                break;
            }
        }
    }
    
    sort(children[node].begin(), children[node].end());
    
    for (int child : children[node]) {
        dfs(child);
    }
    
    current_path.pop_back();
}

int main() {
    int N;
    cin >> N;
    
    children.resize(N);
    vector<int> in_degree(N, 0);
    
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        
        for (int j = 0; j < k; j++) {
            int child;
            cin >> child;
            children[i].push_back(child);
            in_degree[child]++;
        }
    }
    
    int root = -1;
    for (int i = 0; i < N; i++) {
        if (in_degree[i] == 0) {
            root = i;
            break;
        }
    }
    
    dfs(root);
    
    cout << max_length << endl;
    for (int i = 0; i < max_path.size(); i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << max_path[i];
    }
    cout << endl;
    
    return 0;
}