#include <iostream>
using namespace std;

/**
 * L1-053 - 电子汪
 * 
 * 实现原理：
 * 计算两个数的和，然后输出对应数量的"Wang!"。
 * 
 * 解题思路：
 * 1. 读取两个正整数A和B
 * 2. 计算和
 * 3. 输出和个"Wang!"
 */
int main() {
    int A, B;
    cin >> A >> B;
    
    int sum = A + B;
    
    // 输出sum个"Wang!"
    for (int i = 0; i < sum; i++) {
        cout << "Wang!";
    }
    cout << endl;
    
    return 0;
}