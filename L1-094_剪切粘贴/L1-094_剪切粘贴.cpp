#include <iostream>
#include <string>
using namespace std;

/**
 * L1-094 - 剪切粘贴
 * 
 * 实现原理：
 * 模拟文本编辑的剪切粘贴操作。
 * 每次操作分为两步：
 * 1. 剪切：从起始位置到结束位置的字符串放入剪贴板，并删除原位置内容
 * 2. 粘贴：查找插入位置，将剪贴板内容插入，并清空剪贴板
 * 
 * 解题思路：
 * 1. 读取原始字符串
 * 2. 读取操作次数N
 * 3. 对每次操作：
 *    - 执行剪切操作
 *    - 执行粘贴操作
 * 4. 输出最终结果
 */
int main() {
    string s;
    cin >> s;
    
    int N;
    cin >> N;
    
    string clipboard = "";
    
    for (int i = 0; i < N; i++) {
        int start, end;
        string before, after;
        cin >> start >> end >> before >> after;
        
        // 剪切操作（位置从1开始）
        string cut = s.substr(start - 1, end - start + 1);
        s = s.substr(0, start - 1) + s.substr(end);
        
        // 粘贴操作
        string insert_str = cut;
        
        size_t pos = s.find(before + after);
        if (pos != string::npos) {
            // 找到插入位置，在before和after之间插入
            s.insert(pos + before.length(), insert_str);
        } else {
            // 找不到插入位置，在末尾插入
            s += insert_str;
        }
    }
    
    cout << s << endl;
    
    return 0;
}