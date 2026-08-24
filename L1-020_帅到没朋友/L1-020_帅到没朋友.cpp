#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

/**
 * L1-020 - 帅到没朋友
 * 
 * 实现原理：
 * 使用集合存储有朋友的人的ID。
 * 如果一个人在一个人数>1的朋友圈中，则他有朋友。
 * 如果一个人只出现在人数=1的朋友圈中，或者从未出现过，则他是"帅到没朋友"的人。
 * 
 * 解题思路：
 * 1. 创建一个集合存储有朋友的人的ID
 * 2. 读取N个朋友圈：
 *    - 如果朋友圈人数K>1，则将其中所有人加入集合
 *    - 如果朋友圈人数K=1，则不加入（因为这个人只有自己）
 * 3. 读取M个待查询的ID
 * 4. 对于每个待查询的ID：
 *    - 如果不在集合中且未输出过，则输出
 *    - 使用另一个集合记录已输出的ID，避免重复输出
 */
int main() {
    int N;
    cin >> N;
    
    unordered_set<string> has_friend;  // 存储有朋友的人的ID
    
    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;
        
        // 如果朋友圈人数大于1，则这些人都有朋友
        if (K > 1) {
            for (int j = 0; j < K; j++) {
                string id;
                cin >> id;
                has_friend.insert(id);
            }
        } else {
            // 只有自己一个人的朋友圈，这个人没有朋友
            string id;
            cin >> id;
        }
    }
    
    int M;
    cin >> M;
    
    unordered_set<string> output;  // 记录已输出的ID，避免重复
    bool first = true;
    bool found = false;
    
    for (int i = 0; i < M; i++) {
        string id;
        cin >> id;
        
        // 如果这个人没有朋友且未输出过
        if (has_friend.find(id) == has_friend.end() && output.find(id) == output.end()) {
            if (!first) {
                cout << " ";
            }
            first = false;
            cout << id;
            output.insert(id);
            found = true;
        }
    }
    
    if (!found) {
        cout << "No one is handsome" << endl;
    } else {
        cout << endl;
    }
    
    return 0;
}