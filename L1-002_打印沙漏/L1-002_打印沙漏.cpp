#include <iostream>
using namespace std;

/**
 * L1-002 - 打印沙漏
 * 
 * 实现原理：
 * 沙漏形状由上半部分（递减）和下半部分（递增）组成，中间是一个单独的符号。
 * 每个完整沙漏的符号总数为：2 * (1 + 3 + 5 + ... + (2n-1)) - 1 = 2 * n^2 - 1
 * 其中 n 是从中间向上（或向下）的层数。
 * 
 * 解题思路：
 * 1. 计算能组成完整沙漏的最大层数 max_level
 *    公式：2 * max_level^2 - 1 <= N
 *    变形：max_level = floor(sqrt((N+1)/2))
 * 2. 计算实际使用的符号数：used = 2 * max_level^2 - 1
 * 3. 计算剩余符号数：remaining = N - used
 * 4. 打印上半部分（从 2*max_level-1 个符号递减到 1 个）
 * 5. 打印下半部分（从 3 个符号递增到 2*max_level-1 个）
 * 6. 输出剩余符号数
 */
int main() {
    int N;
    char symbol;
    cin >> N >> symbol;
    
    // 计算最大层数
    int max_level = 0;
    while (2 * (max_level + 1) * (max_level + 1) - 1 <= N) {
        max_level++;
    }
    
    // 上半部分：从最大宽度递减到1
    for (int i = max_level; i >= 1; i--) {
        // 输出前导空格，实现居中对齐
        for (int j = 0; j < max_level - i; j++) {
            cout << " ";
        }
        // 输出当前层的符号
        for (int j = 0; j < 2 * i - 1; j++) {
            cout << symbol;
        }
        cout << endl;
    }
    
    // 下半部分：从3递增到最大宽度
    for (int i = 2; i <= max_level; i++) {
        // 输出前导空格
        for (int j = 0; j < max_level - i; j++) {
            cout << " ";
        }
        // 输出当前层的符号
        for (int j = 0; j < 2 * i - 1; j++) {
            cout << symbol;
        }
        cout << endl;
    }
    
    // 输出剩余符号数
    cout << N - (2 * max_level * max_level - 1) << endl;
    
    return 0;
}