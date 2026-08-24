#include <iostream>
using namespace std;

/**
 * L1-072 - 刮刮彩票
 * 
 * 实现原理：
 * 模拟刮刮彩票游戏过程。
 * 彩票是一个3x3的九宫格，数字1-9各出现一次。
 * 初始时只有一个位置是可见的（输入中用0表示可见位置）。
 * 玩家刮开三个位置后，可以看到四个位置的数字。
 * 最后玩家选择一个方向，计算该方向上三个数字的和，根据表格获得金币。
 * 
 * 解题思路：
 * 1. 读取3x3的彩票数据
 * 2. 找到初始可见的位置（值为0的位置），保存其真实数字
 * 3. 读取玩家刮开的三个位置，输出刮开的数字
 * 4. 读取玩家选择的方向，计算该方向上三个数字的和
 * 5. 根据表格输出获得的金币
 */
int main() {
    // 读取彩票数据
    int lottery[3][3];
    int visible_row = -1, visible_col = -1;
    int visible_value = -1;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> lottery[i][j];
            if (lottery[i][j] == 0) {
                // 这个位置初始可见，需要找到真实数字
                visible_row = i;
                visible_col = j;
            }
        }
    }
    
    // 找到真实的九宫格数字（1-9）
    bool used[10] = {false};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (lottery[i][j] != 0) {
                used[lottery[i][j]] = true;
            }
        }
    }
    // 找到未使用的数字，即为可见位置的真实数字
    for (int i = 1; i <= 9; i++) {
        if (!used[i]) {
            visible_value = i;
            break;
        }
    }
    lottery[visible_row][visible_col] = visible_value;
    
    // 处理刮开操作
    for (int i = 0; i < 3; i++) {
        int x, y;
        cin >> x >> y;
        // 转换为0-based索引
        x--;
        y--;
        cout << lottery[x][y] << endl;
    }
    
    // 处理选择方向
    int direction;
    cin >> direction;
    
    int sum = 0;
    switch (direction) {
        case 1: // 第一行
            sum = lottery[0][0] + lottery[0][1] + lottery[0][2];
            break;
        case 2: // 第二行
            sum = lottery[1][0] + lottery[1][1] + lottery[1][2];
            break;
        case 3: // 第三行
            sum = lottery[2][0] + lottery[2][1] + lottery[2][2];
            break;
        case 4: // 第一列
            sum = lottery[0][0] + lottery[1][0] + lottery[2][0];
            break;
        case 5: // 第二列
            sum = lottery[0][1] + lottery[1][1] + lottery[2][1];
            break;
        case 6: // 第三列
            sum = lottery[0][2] + lottery[1][2] + lottery[2][2];
            break;
        case 7: // 主对角线
            sum = lottery[0][0] + lottery[1][1] + lottery[2][2];
            break;
        case 8: // 副对角线
            sum = lottery[0][2] + lottery[1][1] + lottery[2][0];
            break;
    }
    
    // 根据和计算金币
    int coins;
    switch (sum) {
        case 6: coins = 10000; break;
        case 7: coins = 36; break;
        case 8: coins = 720; break;
        case 9: coins = 360; break;
        case 10: coins = 80; break;
        case 11: coins = 252; break;
        case 12: coins = 108; break;
        case 13: coins = 72; break;
        case 14: coins = 54; break;
        case 15: coins = 180; break;
        case 16: coins = 72; break;
        case 17: coins = 180; break;
        case 18: coins = 119; break;
        case 19: coins = 36; break;
        case 20: coins = 306; break;
        case 21: coins = 1080; break;
        case 22: coins = 144; break;
        case 23: coins = 1800; break;
        case 24: coins = 3600; break;
        default: coins = 0;
    }
    
    cout << coins << endl;
    
    return 0;
}