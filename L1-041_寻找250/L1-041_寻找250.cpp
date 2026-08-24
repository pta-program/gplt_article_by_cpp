#include <iostream>
using namespace std;

/**
 * L1-041 - 寻找250
 * 
 * 实现原理：
 * 从输入的一系列整数中找到第一次出现的250，并输出它的位置（从1开始计数）。
 * 
 * 解题思路：
 * 1. 读取整数，直到遇到250
 * 2. 记录当前数字的位置
 * 3. 找到250后立即输出位置并结束程序
 */
int main() {
    int num;
    int position = 0;
    
    while (cin >> num) {
        position++;
        if (num == 250) {
            cout << position << endl;
            break;
        }
    }
    
    return 0;
}