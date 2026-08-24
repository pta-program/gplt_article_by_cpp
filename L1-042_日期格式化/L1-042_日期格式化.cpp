#include <iostream>
#include <string>
using namespace std;

/**
 * L1-042 - 日期格式化
 * 
 * 实现原理：
 * 将输入的美国格式日期（月-日-年）转换为中国格式日期（年-月-日）。
 * 
 * 解题思路：
 * 1. 读取输入的日期字符串
 * 2. 按照分隔符'-'分割字符串
 * 3. 提取月、日、年
 * 4. 按照年-月-日的格式输出
 */
int main() {
    string date;
    cin >> date;
    
    // 找到分隔符的位置
    size_t first_dash = date.find('-');
    size_t second_dash = date.find('-', first_dash + 1);
    
    // 提取月、日、年
    string month = date.substr(0, first_dash);
    string day = date.substr(first_dash + 1, second_dash - first_dash - 1);
    string year = date.substr(second_dash + 1);
    
    // 按中国格式输出
    cout << year << "-" << month << "-" << day << endl;
    
    return 0;
}