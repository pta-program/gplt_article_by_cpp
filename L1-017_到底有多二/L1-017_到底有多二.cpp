#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/**
 * L1-017 - 到底有多二
 * 
 * 实现原理：
 * 犯二程度 = (2的个数 / 总位数) × 系数1 × 系数2 × 100%
 * 其中：
 * - 系数1：如果是负数则为1.5，否则为1
 * - 系数2：如果是偶数则为2，否则为1
 * 
 * 解题思路：
 * 1. 读取输入的大整数（以字符串形式）
 * 2. 统计数字2出现的次数
 * 3. 计算总位数（注意负数的负号不算位数）
 * 4. 判断是否为负数（首字符为'-'）
 * 5. 判断是否为偶数（最后一位数字能被2整除）
 * 6. 计算犯二程度并格式化输出
 */
int main() {
    string N;
    cin >> N;
    
    int count_2 = 0;  // 数字2出现的次数
    int length = N.length();
    bool is_negative = false;
    
    // 判断是否为负数
    if (N[0] == '-') {
        is_negative = true;
        length--;  // 负号不算位数
    }
    
    // 统计数字2出现的次数
    for (char c : N) {
        if (c == '2') {
            count_2++;
        }
    }
    
    // 判断是否为偶数（最后一位数字）
    char last_digit = N.back();
    bool is_even = (last_digit - '0') % 2 == 0;
    
    // 计算犯二程度
    double rate = (double)count_2 / length;
    
    // 应用系数
    if (is_negative) {
        rate *= 1.5;
    }
    if (is_even) {
        rate *= 2;
    }
    
    // 转换为百分比并输出，保留两位小数
    cout << fixed << setprecision(2) << rate * 100 << "%" << endl;
    
    return 0;
}