#include <iostream>
#include <string>
using namespace std;

/**
 * L1-045 - 宇宙无敌大招呼
 * 
 * 实现原理：
 * 简单的字符串输出程序。
 * 
 * 解题思路：
 * 1. 读取输入的星球名字
 * 2. 输出"Hello " + 星球名字
 */
int main() {
    string S;
    cin >> S;
    
    cout << "Hello " << S << endl;
    
    return 0;
}