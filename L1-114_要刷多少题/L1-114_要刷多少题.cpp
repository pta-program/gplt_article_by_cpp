#include <iostream>
using namespace std;

/**
 * L1-114 - 要刷多少题
 * 
 * 实现原理：
 * 根据输入的天数计算需要刷的题目数量。
 * 规律：第n天需要刷的题目数量 = n * 15
 * 
 * 解题思路：
 * 1. 读取天数
 * 2. 计算题目数量
 * 3. 输出结果
 */
int main() {
    int days;
    cin >> days;
    
    cout << days * 15 << endl;
    
    return 0;
}