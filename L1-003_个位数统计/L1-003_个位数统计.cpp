#include <iostream>
#include <string>
using namespace std;

/**
 * L1-003 - 个位数统计
 * 
 * 实现原理：
 * 由于输入的数字可能非常大（最多1000位），无法用普通整数类型存储。
 * 因此将输入作为字符串处理，遍历每个字符即可。
 * 
 * 解题思路：
 * 1. 使用字符串读取输入的大数字
 * 2. 创建一个长度为10的数组 count[10]，用于统计每个数字出现的次数
 * 3. 遍历字符串中的每个字符，将其转换为对应的数字索引，增加计数
 * 4. 按数字0-9的顺序输出统计结果
 */
int main() {
    string num;
    cin >> num;
    
    // 初始化计数数组，count[i]表示数字i出现的次数
    int count[10] = {0};
    
    // 遍历字符串中的每个字符
    for (char c : num) {
        // 将字符转换为数字：'0' -> 0, '1' -> 1, ..., '9' -> 9
        int digit = c - '0';
        count[digit]++;
    }
    
    // 按数字升序输出统计结果
    for (int i = 0; i < 10; i++) {
        if (count[i] > 0) {
            cout << i << ":" << count[i] << endl;
        }
    }
    
    return 0;
}