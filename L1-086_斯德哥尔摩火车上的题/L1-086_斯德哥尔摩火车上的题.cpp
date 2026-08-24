#include <iostream>
#include <string>
using namespace std;

/**
 * L1-086 - 斯德哥尔摩火车上的题
 * 
 * 实现原理：
 * 对字符串进行处理，从左到右遍历相邻两个字符：
 * 如果两个字符的奇偶性相同，则取较大的那个字符添加到结果字符串中。
 * 
 * 解题思路：
 * 1. 读取两个字符串
 * 2. 分别对每个字符串应用算法
 * 3. 比较两个结果，如果相同则输出一个，否则分别输出
 */
string process(string a) {
    string s = "";
    for (int i = 1; i < a.length(); i++) {
        int curr = a[i] - '0';
        int prev = a[i-1] - '0';
        
        if (curr % 2 == prev % 2) {
            s += max(curr, prev) + '0';
        }
    }
    return s;
}

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    
    string s1 = process(a);
    string s2 = process(b);
    
    if (s1 == s2) {
        cout << s1 << endl;
    } else {
        cout << s1 << endl;
        cout << s2 << endl;
    }
    
    return 0;
}