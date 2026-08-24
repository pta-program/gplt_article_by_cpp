#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/**
 * L1-050 - 倒数第N个字符串
 * 
 * 实现原理：
 * 将字符串看作26进制数（a=0, b=1, ..., z=25）。
 * 整个序列共有26^L个字符串，从aaa...a（0）到zzz...z（26^L-1）。
 * 倒数第N个字符串 = 第(26^L - N)个字符串。
 * 将这个数字转换为26进制，每一位对应一个字母。
 * 
 * 解题思路：
 * 1. 计算总共有多少个字符串：total = 26^L
 * 2. 计算目标位置：target = total - N
 * 3. 将target转换为26进制，每一位对应一个字母
 * 4. 输出结果
 */
int main() {
    int L, N;
    cin >> L >> N;
    
    // 计算26^L
    long long total = 1;
    for (int i = 0; i < L; i++) {
        total *= 26;
    }
    
    // 目标位置
    long long target = total - N;
    
    string result;
    
    // 将target转换为26进制，每一位对应一个字母
    for (int i = 0; i < L; i++) {
        int digit = target % 26;
        result = char('a' + digit) + result;
        target /= 26;
    }
    
    cout << result << endl;
    
    return 0;
}