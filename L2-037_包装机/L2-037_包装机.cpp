#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/**
 * L2-037 - 包装机
 * 
 * 实现原理：
 * 模拟包装机的操作过程。
 * 规则：
 * 1. 按轨道按钮将物品推入筐（栈）
 * 2. 按0号按钮将筐顶部物品放到流水线
 * 3. 筐满时强制启动0号键
 * 4. 轨道空或筐空时对应操作无效
 * 
 * 解题思路：
 * 1. 使用队列存储每条轨道的物品（从左到右）
 * 2. 使用栈存储筐中的物品
 * 3. 按操作顺序模拟
 */
int main() {
    int N, M, Smax;
    cin >> N >> M >> Smax;
    
    vector<queue<char>> tracks(N + 1);
    
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (char c : s) {
            tracks[i].push(c);
        }
    }
    
    stack<char> basket;
    string result;
    
    int op;
    while (cin >> op) {
        if (op == -1) break;
        
        if (op == 0) {
            if (!basket.empty()) {
                result += basket.top();
                basket.pop();
            }
        } else {
            if (tracks[op].empty()) continue;
            
            if (basket.size() >= Smax) {
                result += basket.top();
                basket.pop();
            }
            
            basket.push(tracks[op].front());
            tracks[op].pop();
        }
    }
    
    cout << result << endl;
    
    return 0;
}