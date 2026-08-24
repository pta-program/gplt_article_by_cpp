#include <iostream>
#include <string>
using namespace std;

/**
 * L1-035 - 情人节
 * 
 * 实现原理：
 * 按照点赞顺序读取人名，直到遇到句点结束。
 * 记录第2个和第14个点赞的人。
 * 根据记录的结果输出相应的结论。
 * 
 * 解题思路：
 * 1. 读取人名，直到遇到句点
 * 2. 记录第2个和第14个点赞的人
 * 3. 根据情况输出：
 *    - 如果都存在：输出两人名字
 *    - 如果只有第2个存在：输出只有第2个
 *    - 如果都不存在：输出提示信息
 */
int main() {
    string name;
    string second, fourteenth;
    int count = 0;
    
    while (cin >> name) {
        if (name == ".") {
            break;
        }
        
        count++;
        if (count == 2) {
            second = name;
        } else if (count == 14) {
            fourteenth = name;
        }
    }
    
    if (!second.empty() && !fourteenth.empty()) {
        cout << second << " and " << fourteenth << " are inviting you to dinner..." << endl;
    } else if (!second.empty()) {
        cout << second << " is the only one for you..." << endl;
    } else {
        cout << "Momo... No one is for you ..." << endl;
    }
    
    return 0;
}