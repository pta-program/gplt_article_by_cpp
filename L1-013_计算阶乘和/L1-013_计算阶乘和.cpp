#include <iostream>
using namespace std;

/**
 * L1-013 - 计算阶乘和
 * 
 * 实现原理：
 * 阶乘的定义：n! = n * (n-1) * (n-2) * ... * 1
 * 阶乘和：S = 1! + 2! + 3! + ... + N!
 * 由于N不超过10，10! = 3628800，可以用int存储（int最大值约为21亿）。
 * 
 * 解题思路：
 * 1. 读取输入的整数N
 * 2. 初始化总和sum为0，当前阶乘factorial为1
 * 3. 循环计算每个阶乘并累加到sum中
 * 4. 输出结果
 */
int main() {
    int N;
    cin >> N;
    
    int sum = 0;        // 阶乘和
    int factorial = 1;  // 当前阶乘值
    
    // 计算阶乘和
    for (int i = 1; i <= N; i++) {
        factorial *= i;  // 计算i!
        sum += factorial; // 累加到总和
    }
    
    // 输出结果
    cout << sum << endl;
    
    return 0;
}