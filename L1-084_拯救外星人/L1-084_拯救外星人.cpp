#include <iostream>
using namespace std;

/**
 * L1-084 - 拯救外星人
 * 
 * 实现原理：
 * 外星人用阶乘表示加法结果。
 * 需要计算 (A+B) 的阶乘。
 * 
 * 解题思路：
 * 1. 读取 A 和 B
 * 2. 计算 sum = A + B
 * 3. 计算 sum 的阶乘
 * 4. 输出结果
 */
int main() {
    int A, B;
    cin >> A >> B;
    
    int sum = A + B;
    
    // 计算阶乘
    int result = 1;
    for (int i = 2; i <= sum; i++) {
        result *= i;
    }
    
    cout << result << endl;
    
    return 0;
}