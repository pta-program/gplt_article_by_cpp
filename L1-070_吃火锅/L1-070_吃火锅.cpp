#include <iostream>
#include <string>
using namespace std;

/**
 * L1-070 - 吃火锅
 * 
 * 实现原理：
 * 检查朋友发来的信息中是否包含"chi1 huo3 guo1"关键词。
 * 
 * 解题思路：
 * 1. 读取朋友信息，直到遇到只有一个句点的行
 * 2. 统计信息总条数
 * 3. 统计包含"chi1 huo3 guo1"的信息条数和第一次出现的位置
 * 4. 输出结果
 */
int main() {
    string line;
    int total_count = 0;
    int special_count = 0;
    int first_special = -1;
    
    while (getline(cin, line)) {
        if (line == ".") {
            break;
        }
        
        total_count++;
        
        // 检查是否包含"chi1 huo3 guo1"
        if (line.find("chi1 huo3 guo1") != string::npos) {
            special_count++;
            if (first_special == -1) {
                first_special = total_count;
            }
        }
    }
    
    // 输出总条数
    cout << total_count << endl;
    
    // 输出结果
    if (special_count == 0) {
        cout << "-_-#" << endl;
    } else {
        cout << first_special << " " << special_count << endl;
    }
    
    return 0;
}