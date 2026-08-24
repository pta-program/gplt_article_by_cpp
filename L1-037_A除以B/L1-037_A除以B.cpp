#include <iostream>
#include <iomanip>
using namespace std;

/**
 * L1-037 - A除以B
 * 
 * 实现原理：
 * 简单的除法运算，但需要注意输出格式：
 * 1. 如果分母为0，输出Error
 * 2. 如果分母为负数，要用括号括起来
 * 3. 商保留小数点后2位
 * 
 * 解题思路：
 * 1. 读取两个整数A和B
 * 2. 处理三种情况：
 *    - B == 0：输出Error
 *    - B < 0：用括号括起来分母
 *    - B > 0：正常输出
 * 3. 计算并输出商，保留2位小数
 */
int main() {
    int A, B;
    cin >> A >> B;
    
    cout << A << "/";
    
    if (B == 0) {
        cout << "0=Error" << endl;
    } else if (B < 0) {
        cout << "(" << B << ")=" << fixed << setprecision(2) << (double)A / B << endl;
    } else {
        cout << B << "=" << fixed << setprecision(2) << (double)A / B << endl;
    }
    
    return 0;
}