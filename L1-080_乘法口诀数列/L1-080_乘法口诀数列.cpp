#include <iostream>
#include <vector>
using namespace std;

/**
 * L1-080 - 乘法口诀数列
 * 
 * 实现原理：
 * 从a1和a2开始生成数列。
 * 每次将当前数字与后面一个数字相乘，将结果贴在数列末尾。
 * 如果结果不是1位数，则其每一位都应成为数列的一项。
 * 
 * 解题思路：
 * 1. 初始化数列，前两项为a1和a2
 * 2. 从第1项开始，依次计算当前项与下一项的乘积
 * 3. 将乘积的每一位添加到数列末尾
 * 4. 直到数列长度达到n
 * 5. 输出前n项
 */
int main() {
    int a1, a2, n;
    cin >> a1 >> a2 >> n;
    
    vector<int> sequence;
    sequence.push_back(a1);
    
    if (n > 1) {
        sequence.push_back(a2);
    }
    
    int i = 0;
    while (sequence.size() < n) {
        int product = sequence[i] * sequence[i + 1];
        
        if (product == 0) {
            sequence.push_back(0);
        } else if (product < 10) {
            sequence.push_back(product);
        } else {
            // 将乘积拆分成单个数字
            string num_str = to_string(product);
            for (char c : num_str) {
                sequence.push_back(c - '0');
                if (sequence.size() >= n) {
                    break;
                }
            }
        }
        
        i++;
    }
    
    // 输出前n项
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << sequence[i];
    }
    cout << endl;
    
    return 0;
}