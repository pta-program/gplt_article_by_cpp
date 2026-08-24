#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/**
 * L2-008 - 最长对称子串
 * 
 * 实现原理：
 * 使用中心扩展法寻找最长回文子串。
 * 回文子串有两种形式：
 * 1. 奇数长度：以单个字符为中心
 * 2. 偶数长度：以两个字符之间为中心
 * 
 * 解题思路：
 * 1. 遍历字符串中的每个字符
 * 2. 以每个字符为中心，向两边扩展，寻找最长回文子串
 * 3. 以每两个相邻字符之间为中心，向两边扩展，寻找最长回文子串
 * 4. 记录最长回文子串的长度
 */
int expandAroundCenter(string s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

int main() {
    string s;
    getline(cin, s);
    
    int max_len = 0;
    
    for (int i = 0; i < s.length(); i++) {
        // 奇数长度回文
        int len1 = expandAroundCenter(s, i, i);
        // 偶数长度回文
        int len2 = expandAroundCenter(s, i, i + 1);
        
        max_len = max(max_len, max(len1, len2));
    }
    
    cout << max_len << endl;
    
    return 0;
}