#include <iostream>
#include <string>
using namespace std;

/**
 * L1-011 - A-B
 * 
 * 实现原理：
 * 从字符串A中删除所有在字符串B中出现的字符。
 * 使用布尔数组或哈希表快速判断某个字符是否在B中出现。
 * 
 * 解题思路：
 * 1. 读取字符串A和B
 * 2. 创建一个布尔数组（或使用set）记录B中出现过的字符
 * 3. 遍历字符串A的每个字符，如果该字符不在B中，则保留
 * 4. 输出处理后的字符串
 */
int main() {
    string A, B;
    getline(cin, A);
    getline(cin, B);
    
    // 创建字符出现标记数组
    bool inB[256] = {false};
    
    // 标记B中出现的字符
    for (char c : B) {
        inB[(unsigned char)c] = true;
    }
    
    // 构建结果字符串
    string result;
    for (char c : A) {
        if (!inB[(unsigned char)c]) {
            result += c;
        }
    }
    
    // 输出结果
    cout << result << endl;
    
    return 0;
}