#include <iostream>
#include <string>
using namespace std;

/**
 * L1-032 - Left-pad
 * 
 * 实现原理：
 * 在字符串左侧填充指定字符，使字符串达到指定长度。
 * 如果原始字符串长度已经大于等于目标长度，则截取末尾的N个字符。
 * 
 * 解题思路：
 * 1. 读取目标长度N和填充字符
 * 2. 读取原始字符串
 * 3. 如果原始字符串长度 < N：
 *    - 在左侧填充 (N - len) 个字符
 * 4. 如果原始字符串长度 >= N：
 *    - 截取字符串末尾的N个字符
 * 5. 输出结果
 */
int main() {
    int N;
    char pad_char;
    cin >> N >> pad_char;
    
    // 忽略换行符
    cin.ignore();
    
    string s;
    getline(cin, s);
    
    string result;
    
    if (s.length() < N) {
        // 需要填充
        int pad_count = N - s.length();
        result = string(pad_count, pad_char) + s;
    } else {
        // 截取末尾N个字符
        result = s.substr(s.length() - N);
    }
    
    cout << result << endl;
    
    return 0;
}