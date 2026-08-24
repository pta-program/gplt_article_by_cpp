#include <iostream>
#include <cmath>
using namespace std;

/**
 * L1-012 - 计算指数
 * 
 * 实现原理：
 * 使用位运算或乘法计算2的n次方。
 * 由于n不超过10，2^10 = 1024，可以直接用整数存储。
 * 
 * 解题思路：
 * 1. 读取输入的整数n
 * 2. 计算2^n，可以使用：
 *    - 位移运算：1 << n
 *    - 乘法循环
 *    - pow函数（需要注意精度问题）
 * 3. 按指定格式输出结果
 */
int main() {
    int n;
    cin >> n;
    
    // 使用位移运算计算2^n，效率最高
    int result = 1 << n;
    
    // 按格式输出
    cout << "2^" << n << " = " << result << endl;
    
    return 0;
}