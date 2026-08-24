#include <iostream>
using namespace std;

/**
 * L1-085 - 试试手气
 * 
 * 实现原理：
 * 模拟摇骰子过程。
 * 每个骰子每次摇出的点数都跟之前任何一次出现的点数不同。
 * 在满足条件的前提下，每次都能让每个骰子得到可能得到的最大点数。
 * 
 * 解题思路：
 * 1. 读取6个骰子的初始点数
 * 2. 读取摇的次数n
 * 3. 对于每个骰子，模拟n次摇动过程：
 *    - 每次选择之前没出现过的最大点数
 * 4. 输出第n次的结果
 */
int main() {
    int dice[6];
    for (int i = 0; i < 6; i++) {
        cin >> dice[i];
    }
    
    int n;
    cin >> n;
    
    // 记录每个骰子已经出现过的点数
    bool used[6][7];  // used[i][j] 表示第i个骰子是否用过点数j
    for (int i = 0; i < 6; i++) {
        for (int j = 1; j <= 6; j++) {
            used[i][j] = false;
        }
        used[i][dice[i]] = true;
    }
    
    // 模拟摇动过程
    for (int round = 1; round <= n; round++) {
        int current[6];
        
        for (int i = 0; i < 6; i++) {
            // 找到最大的未使用过的点数
            for (int j = 6; j >= 1; j--) {
                if (!used[i][j]) {
                    current[i] = j;
                    used[i][j] = true;
                    break;
                }
            }
        }
        
        // 如果是第n次，输出结果
        if (round == n) {
            for (int i = 0; i < 6; i++) {
                if (i > 0) {
                    cout << " ";
                }
                cout << current[i];
            }
            cout << endl;
        }
    }
    
    return 0;
}