#include <iostream>
#include <iomanip>
using namespace std;

/**
 * L1-008 - 求整数段和
 * 
 * 实现原理：
 * 从A到B遍历所有整数，同时进行格式化输出和求和运算。
 * 使用 setw(5) 设置每个数字的宽度为5，right 表示右对齐。
 * 
 * 解题思路：
 * 1. 读取A和B的值
 * 2. 初始化计数器 count 和总和 sum
 * 3. 遍历从A到B的每个整数：
 *    - 每5个数字换一行
 *    - 每个数字占5个字符宽度，右对齐
 *    - 累加求和
 * 4. 遍历结束后输出总和
 */
int main() {
    int A, B;
    cin >> A >> B;
    
    int count = 0;  // 当前行已输出的数字个数
    int sum = 0;    // 所有数字的和
    
    // 遍历从A到B的所有整数
    for (int i = A; i <= B; i++) {
        // 输出数字，宽度为5，右对齐
        cout << setw(5) << right << i;
        count++;
        sum += i;
        
        // 每5个数字换行
        if (count % 5 == 0 && i != B) {
            cout << endl;
        }
    }
    
    // 如果最后一行不满5个数字，换行
    if (count % 5 != 0) {
        cout << endl;
    }
    
    // 输出总和
    cout << "Sum = " << sum << endl;
    
    return 0;
}