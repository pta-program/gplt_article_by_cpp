#include <iostream>
#include <string>
using namespace std;

/**
 * L1-007 - 念数字
 * 
 * 实现原理：
 * 将输入的整数转换为字符串处理，逐个字符进行映射。
 * 使用字符串数组存储每个数字对应的拼音，方便快速查找。
 * 
 * 解题思路：
 * 1. 创建字符串数组，索引对应数字，值对应拼音
 * 2. 读取输入的整数，转换为字符串
 * 3. 遍历字符串中的每个字符：
 *    - 如果是负号，输出"fu"
 *    - 否则，将字符转换为数字索引，输出对应的拼音
 * 4. 注意处理空格：每个拼音之间用空格分隔，行末没有空格
 */
int main() {
    // 数字到拼音的映射表
    string pinyin[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    
    string num;
    cin >> num;
    
    bool first = true;  // 标记是否是第一个输出的拼音
    
    // 遍历每个字符
    for (char c : num) {
        if (!first) {
            cout << " ";
        }
        first = false;
        
        if (c == '-') {
            // 负数情况，输出"fu"
            cout << "fu";
        } else {
            // 数字字符转换为索引，输出对应的拼音
            int digit = c - '0';
            cout << pinyin[digit];
        }
    }
    
    cout << endl;
    
    return 0;
}