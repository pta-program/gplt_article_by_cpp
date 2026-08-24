#include <iostream>
#include <iomanip>
using namespace std;

/**
 * L1-033 - 出生年
 * 
 * 实现原理：
 * 从出生年份开始，逐年检查是否满足"恰好n个不同数字"的条件。
 * 将年份视为4位数（不足4位前面补零），统计其中不同数字的个数。
 * 
 * 解题思路：
 * 1. 读取出生年份y和目标不同数字个数n
 * 2. 从y开始逐年检查：
 *    - 将年份转换为4位数格式
 *    - 统计不同数字的个数
 *    - 如果恰好等于n，则找到答案
 * 3. 输出年龄和年份（4位格式）
 */

// 统计年份中不同数字的个数
int countUniqueDigits(int year) {
    bool seen[10] = {false};
    int count = 0;
    
    // 将年份视为4位数，前面补零
    for (int i = 0; i < 4; i++) {
        int digit = year % 10;
        if (!seen[digit]) {
            seen[digit] = true;
            count++;
        }
        year /= 10;
    }
    
    return count;
}

int main() {
    int y, n;
    cin >> y >> n;
    
    int target_year = y;
    while (countUniqueDigits(target_year) != n) {
        target_year++;
    }
    
    int age = target_year - y;
    
    cout << age << " " << setw(4) << setfill('0') << target_year << endl;
    
    return 0;
}