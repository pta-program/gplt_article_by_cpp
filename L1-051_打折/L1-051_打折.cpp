#include <iostream>
#include <iomanip>
using namespace std;

/**
 * L1-051 - 打折
 * 
 * 实现原理：
 * 根据原价和折扣计算折扣价。
 * 折扣价 = 原价 * 折扣 / 10
 * 
 * 解题思路：
 * 1. 读取原价和折扣
 * 2. 计算折扣价
 * 3. 输出结果，保留2位小数
 */
int main() {
    int price, discount;
    cin >> price >> discount;
    
    // 计算折扣价
    double result = price * discount / 10.0;
    
    // 输出结果，保留2位小数
    cout << fixed << setprecision(2) << result << endl;
    
    return 0;
}