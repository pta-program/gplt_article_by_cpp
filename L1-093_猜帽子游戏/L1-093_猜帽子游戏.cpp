#include <iostream>
using namespace std;

/**
 * L1-093 - 猜帽子游戏
 * 
 * 实现原理：
 * 判断宝宝们能否获得大奖。
 * 获奖条件：
 * 1. 没有一个人猜错
 * 2. 至少有一个人猜对了
 * 
 * 解题思路：
 * 1. 读取帽子颜色数组
 * 2. 读取K组猜测结果
 * 3. 对每组猜测：
 *    - 检查是否有人猜错
 *    - 检查是否有人猜对
 *    - 根据条件输出结果
 */
int main() {
    int N;
    cin >> N;
    
    int hats[100];
    for (int i = 0; i < N; i++) {
        cin >> hats[i];
    }
    
    int K;
    cin >> K;
    
    for (int i = 0; i < K; i++) {
        int guess[100];
        for (int j = 0; j < N; j++) {
            cin >> guess[j];
        }
        
        bool has_error = false;
        bool has_correct = false;
        
        for (int j = 0; j < N; j++) {
            if (guess[j] == 0) {
                continue;
            }
            
            if (guess[j] == hats[j]) {
                has_correct = true;
            } else {
                has_error = true;
            }
        }
        
        if (!has_error && has_correct) {
            cout << "Da Jiang!!!" << endl;
        } else {
            cout << "Ai Ya" << endl;
        }
    }
    
    return 0;
}