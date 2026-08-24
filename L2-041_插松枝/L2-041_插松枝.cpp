#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * L2-041 - 插松枝
 * 
 * 实现原理：
 * 模拟插松枝的过程。
 * 规则：
 * 1. 每次插入的松针不能比前一个大
 * 2. 优先从盒子取，如果不满足要求则从推送器取
 * 3. 推送器取到不满足要求的放入盒子
 * 4. 三种结束条件
 * 
 * 解题思路：
 * 1. 使用栈模拟小盒子
 * 2. 使用指针模拟推送器
 * 3. 按规则模拟插松枝过程
 */
int main() {
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<int> needles(N);
    for (int i = 0; i < N; i++) {
        cin >> needles[i];
    }
    
    stack<int> box;
    int push_ptr = 0;
    
    while (push_ptr < N || !box.empty()) {
        vector<int> branch;
        
        int last_needle = 101;
        
        while (branch.size() < K) {
            bool found = false;
            
            if (!box.empty() && box.top() <= last_needle) {
                branch.push_back(box.top());
                last_needle = box.top();
                box.pop();
                found = true;
            } else {
                while (push_ptr < N) {
                    int needle = needles[push_ptr];
                    push_ptr++;
                    
                    if (needle <= last_needle) {
                        branch.push_back(needle);
                        last_needle = needle;
                        found = true;
                        break;
                    } else {
                        if (box.size() < M) {
                            box.push(needle);
                        } else {
                            push_ptr--;
                            found = false;
                            break;
                        }
                    }
                }
            }
            
            if (!found) {
                break;
            }
        }
        
        for (int i = 0; i < branch.size(); i++) {
            if (i > 0) {
                cout << " ";
            }
            cout << branch[i];
        }
        cout << endl;
    }
    
    return 0;
}