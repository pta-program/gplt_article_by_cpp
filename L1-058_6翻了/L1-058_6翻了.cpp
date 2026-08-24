#include <iostream>
#include <string>
using namespace std;

/**
 * L1-058 - 6翻了
 * 
 * 实现原理：
 * 扫描字符串，识别连续的6序列。
 * 根据连续6的个数进行替换：
 * - 超过9个连续的6：替换为"27"
 * - 超过3个连续的6：替换为"9"
 * - 3个及以下：保持原样
 * 
 * 解题思路：
 * 1. 读取输入字符串
 * 2. 扫描字符串，统计连续6的个数
 * 3. 遇到非6字符时，根据统计结果输出
 * 4. 处理字符串末尾的连续6
 */
int main() {
    string s;
    getline(cin, s);
    
    int count_6 = 0;
    
    for (char c : s) {
        if (c == '6') {
            count_6++;
        } else {
            // 处理之前连续的6
            if (count_6 > 9) {
                cout << "27";
            } else if (count_6 > 3) {
                cout << "9";
            } else {
                for (int i = 0; i < count_6; i++) {
                    cout << "6";
                }
            }
            count_6 = 0;
            cout << c;
        }
    }
    
    // 处理字符串末尾的连续6
    if (count_6 > 9) {
        cout << "27";
    } else if (count_6 > 3) {
        cout << "9";
    } else {
        for (int i = 0; i < count_6; i++) {
            cout << "6";
        }
    }
    
    cout << endl;
    
    return 0;
}