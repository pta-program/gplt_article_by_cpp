#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * L2-032 - 彩虹瓶
 * 
 * 实现原理：
 * 判断工厂的发货顺序能否让工人顺利完成装填。
 * 规则：
 * 1. 按顺序装填1到N种颜色
 * 2. 不能装填的箱子堆在货架上（栈）
 * 3. 货架容量有限制
 * 4. 装填完一种颜色后，检查货架顶端是否是下一个颜色
 * 
 * 解题思路：
 * 1. 使用栈模拟货架
 * 2. 遍历发货顺序
 * 3. 如果当前货物是需要的颜色，直接装填
 * 4. 否则放入栈中（检查容量）
 * 5. 装填后检查栈顶是否是下一个颜色
 */
int main() {
    int N, M, K;
    cin >> N >> M >> K;
    
    for (int i = 0; i < K; i++) {
        vector<int> order(N);
        for (int j = 0; j < N; j++) {
            cin >> order[j];
        }
        
        stack<int> shelf;
        int target = 1;
        bool success = true;
        
        for (int color : order) {
            if (color == target) {
                target++;
                
                while (!shelf.empty() && shelf.top() == target) {
                    shelf.pop();
                    target++;
                }
            } else {
                if (shelf.size() >= M) {
                    success = false;
                    break;
                }
                shelf.push(color);
            }
        }
        
        while (!shelf.empty() && shelf.top() == target) {
            shelf.pop();
            target++;
        }
        
        if (success && shelf.empty() && target == N + 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}