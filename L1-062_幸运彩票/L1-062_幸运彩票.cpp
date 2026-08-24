#include <iostream>
#include <string>
using namespace std;

/**
 * L1-062 - 幸运彩票
 * 
 * 实现原理：
 * 判断6位数字彩票是否幸运：前3位数字之和等于后3位数字之和。
 * 
 * 解题思路：
 * 1. 读取彩票数量N
 * 2. 对每张彩票：
 *    - 计算前3位数字之和
 *    - 计算后3位数字之和
 *    - 如果相等，输出"You are lucky!"
 *    - 否则输出"Wish you good luck."
 */
int main() {
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        string lottery;
        cin >> lottery;
        
        // 计算前3位数字之和
        int sum1 = (lottery[0] - '0') + (lottery[1] - '0') + (lottery[2] - '0');
        
        // 计算后3位数字之和
        int sum2 = (lottery[3] - '0') + (lottery[4] - '0') + (lottery[5] - '0');
        
        if (sum1 == sum2) {
            cout << "You are lucky!" << endl;
        } else {
            cout << "Wish you good luck." << endl;
        }
    }
    
    return 0;
}