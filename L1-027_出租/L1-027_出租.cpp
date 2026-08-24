#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * L1-027 - 出租
 * 
 * 实现原理：
 * 根据电话号码生成两段代码：
 * 1. arr数组：包含电话号码中出现的所有数字，按递减顺序排列，去重
 * 2. index数组：对于电话号码中的每个数字，记录它在arr数组中的下标
 * 
 * 解题思路：
 * 1. 读取11位手机号码
 * 2. 提取所有出现过的数字，去重并按递减排序得到arr数组
 * 3. 对于电话号码中的每个数字，查找其在arr数组中的下标，组成index数组
 * 4. 按格式输出两段代码
 */
int main() {
    string phone;
    cin >> phone;
    
    // 提取所有出现过的数字，去重
    vector<int> digits;
    bool seen[10] = {false};
    
    for (char c : phone) {
        int digit = c - '0';
        if (!seen[digit]) {
            seen[digit] = true;
            digits.push_back(digit);
        }
    }
    
    // 按递减顺序排序
    sort(digits.rbegin(), digits.rend());
    
    // 构建数字到下标的映射
    int pos[10];
    for (int i = 0; i < digits.size(); i++) {
        pos[digits[i]] = i;
    }
    
    // 构建index数组
    vector<int> index;
    for (char c : phone) {
        int digit = c - '0';
        index.push_back(pos[digit]);
    }
    
    // 输出arr数组
    cout << "int[] arr = new int[]{";
    for (int i = 0; i < digits.size(); i++) {
        if (i > 0) {
            cout << ",";
        }
        cout << digits[i];
    }
    cout << "};" << endl;
    
    // 输出index数组
    cout << "int[] index = new int[]{";
    for (int i = 0; i < index.size(); i++) {
        if (i > 0) {
            cout << ",";
        }
        cout << index[i];
    }
    cout << "};" << endl;
    
    return 0;
}