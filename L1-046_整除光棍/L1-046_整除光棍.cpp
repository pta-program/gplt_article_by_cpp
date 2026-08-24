#include <iostream>
using namespace std;

/**
 * L1-046 - 整除光棍
 * 
 * 实现原理：
 * 找到最小的全1数（光棍）能被x整除。
 * 使用长除法思想：从高位到低位逐位计算商，避免直接处理超大数。
 * 
 * 解题思路：
 * 1. 初始化余数为0，位数为0
 * 2. 循环增加光棍的位数：
 *    - 余数 = 余数 * 10 + 1
 *    - 如果余数 >= x，输出商的一位（余数 / x）
 *    - 更新余数 = 余数 % x
 *    - 如果余数 == 0，找到答案
 * 3. 输出商和位数
 */
int main() {
    int x;
    cin >> x;
    
    int remainder = 0;  // 当前余数
    int digits = 0;     // 光棍的位数
    bool started = false;  // 是否已开始输出商
    
    while (true) {
        // 增加一位1
        remainder = remainder * 10 + 1;
        digits++;
        
        // 如果当前余数 >= x，输出商的一位
        if (remainder >= x) {
            cout << remainder / x;
            started = true;
            remainder = remainder % x;
        } else if (started) {
            // 余数 < x，但已经开始输出，需要补0
            cout << 0;
        }
        
        // 如果余数为0，找到答案
        if (remainder == 0) {
            break;
        }
    }
    
    cout << " " << digits << endl;
    
    return 0;
}