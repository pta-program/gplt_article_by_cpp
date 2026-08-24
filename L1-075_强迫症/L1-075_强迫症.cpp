#include <iostream>
#include <string>
using namespace std;

/**
 * L1-075 - 强迫症
 * 
 * 实现原理：
 * 将出生年月整理成标准格式"年年年年-月月"。
 * 如果输入是4位数（年份后两位+月份）：
 * - 年份后两位 < 22：前缀为20
 * - 年份后两位 >= 22：前缀为19
 * 如果输入是6位数（完整年份+月份）：
 * - 直接使用
 * 
 * 解题思路：
 * 1. 读取输入字符串
 * 2. 根据长度判断是4位还是6位
 * 3. 处理年份前缀
 * 4. 按格式输出
 */
int main() {
    string date;
    cin >> date;
    
    string year, month;
    
    if (date.length() == 4) {
        // 4位数：年份后两位+月份
        string year_part = date.substr(0, 2);
        month = date.substr(2, 2);
        
        int year_num = stoi(year_part);
        if (year_num < 22) {
            year = "20" + year_part;
        } else {
            year = "19" + year_part;
        }
    } else {
        // 6位数：完整年份+月份
        year = date.substr(0, 4);
        month = date.substr(4, 2);
    }
    
    cout << year << "-" << month << endl;
    
    return 0;
}