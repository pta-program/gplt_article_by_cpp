#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * L2-031 - 深入虎穴
 * 
 * 实现原理：
 * 找到距离入口最远的门。
 * 迷宫是一个树形结构，入口是根节点。
 * 
 * 解题思路：
 * 1. 使用 BFS 遍历整个迷宫
 * 2. 记录每个门的距离
 * 3. 找出距离最大的门
 */
int main() {
    int N;
    cin >> N;
    
    vector<vector<int>> doors(N + 1);
    vector<int> indegree(N + 1, 0);
    
    for (int i = 1; i <= N; i++) {
        int K;
        cin >> K;
        
        for (int j = 0; j < K; j++) {
            int d;
            cin >> d;
            doors[i].push_back(d);
            indegree[d]++;
        }
    }
    
    int entrance = 1;
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            entrance = i;
            break;
        }
    }
    
    vector<int> distance(N + 1, 0);
    queue<int> q;
    
    q.push(entrance);
    distance[entrance] = 0;
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        for (int next_door : doors[curr]) {
            distance[next_door] = distance[curr] + 1;
            q.push(next_door);
        }
    }
    
    int max_dist = -1;
    int result = 1;
    
    for (int i = 1; i <= N; i++) {
        if (distance[i] > max_dist) {
            max_dist = distance[i];
            result = i;
        }
    }
    
    cout << result << endl;
    
    return 0;
}