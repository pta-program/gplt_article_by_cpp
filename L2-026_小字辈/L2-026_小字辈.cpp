#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * L2-026 - 小字辈
 * 
 * 实现原理：
 * 找出家族中辈分最小的成员。
 * 老祖宗辈分为1，逐级递增。
 * 
 * 解题思路：
 * 1. 使用动态规划计算每个人的辈分
 * 2. 找到最大辈分值
 * 3. 收集所有辈分等于最大辈分的成员
 * 4. 排序输出
 */
int main() {
    int N;
    cin >> N;
    
    vector<int> parent(N + 1);
    vector<int> generation(N + 1, 0);
    
    for (int i = 1; i <= N; i++) {
        cin >> parent[i];
    }
    
    for (int i = 1; i <= N; i++) {
        if (generation[i] == 0) {
            vector<int> path;
            int curr = i;
            
            while (curr != -1 && generation[curr] == 0) {
                path.push_back(curr);
                curr = parent[curr];
            }
            
            int gen = (curr == -1) ? 1 : generation[curr] + 1;
            
            for (auto it = path.rbegin(); it != path.rend(); it++) {
                generation[*it] = gen;
                gen++;
            }
        }
    }
    
    int max_gen = 0;
    for (int i = 1; i <= N; i++) {
        if (generation[i] > max_gen) {
            max_gen = generation[i];
        }
    }
    
    vector<int> youngest;
    for (int i = 1; i <= N; i++) {
        if (generation[i] == max_gen) {
            youngest.push_back(i);
        }
    }
    
    sort(youngest.begin(), youngest.end());
    
    cout << max_gen << endl;
    for (int i = 0; i < youngest.size(); i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << youngest[i];
    }
    cout << endl;
    
    return 0;
}