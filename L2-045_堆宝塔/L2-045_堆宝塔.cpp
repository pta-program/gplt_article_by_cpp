#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * L2-045 - 堆宝塔
 * 
 * 实现原理：
 * 模拟堆宝塔的过程。
 * 规则：
 * 1. A柱串宝塔，B柱临时叠放
 * 2. 彩虹圈必须按从大到小顺序堆叠
 * 3. 三种情况处理新彩虹圈
 * 
 * 解题思路：
 * 1. 使用栈模拟A柱和B柱
 * 2. 按规则处理每个彩虹圈
 * 3. 最后统计宝塔数量和最高层数
 */
int main() {
    int N;
    cin >> N;
    
    vector<int> circles(N);
    for (int i = 0; i < N; i++) {
        cin >> circles[i];
    }
    
    stack<int> A, B;
    vector<int> towers;
    
    for (int C : circles) {
        if (A.empty()) {
            A.push(C);
        } else if (C < A.top()) {
            A.push(C);
        } else {
            if (B.empty() || C > B.top()) {
                B.push(C);
            } else {
                towers.push_back(A.size());
                
                while (!A.empty()) {
                    A.pop();
                }
                
                while (!B.empty() && B.top() > C) {
                    A.push(B.top());
                    B.pop();
                }
                
                A.push(C);
            }
        }
    }
    
    if (!A.empty()) {
        towers.push_back(A.size());
    }
    
    if (!B.empty()) {
        towers.push_back(B.size());
    }
    
    int max_height = 0;
    for (int height : towers) {
        if (height > max_height) {
            max_height = height;
        }
    }
    
    cout << towers.size() << " " << max_height << endl;
    
    return 0;
}