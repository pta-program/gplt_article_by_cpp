#include <iostream>
using namespace std;

/**
 * L1-090 - 什么是机器学习
 * 
 * 实现原理：
 * 模拟机器学习程序的行为。
 * 第1行输出正确结果 - 16
 * 第2行输出正确结果 - 3
 * 第3行输出正确结果 - 1
 * 第4行输出正确结果
 * 
 * 解题思路：
 * 1. 读取A和B
 * 2. 计算正确结果
 * 3. 按要求输出4行
 */
int main() {
    int A, B;
    cin >> A >> B;
    
    int correct = A + B;
    
    cout << correct - 16 << endl;
    cout << correct - 3 << endl;
    cout << correct - 1 << endl;
    cout << correct << endl;
    
    return 0;
}