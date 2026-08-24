#include <iostream>
using namespace std;

/**
 * L1-010 - 比较大小
 * 
 * 实现原理：
 * 使用简单的比较交换方法将三个数按从小到大排序。
 * 也可以使用数组排序的方法。
 * 
 * 解题思路：
 * 1. 读取三个整数
 * 2. 通过比较交换确保 a <= b <= c
 * 3. 按照格式 a->b->c 输出
 */
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    // 使用临时变量进行排序
    int temp;
    
    // 确保a是最小的
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }
    if (a > c) {
        temp = a;
        a = c;
        c = temp;
    }
    
    // 确保b小于等于c
    if (b > c) {
        temp = b;
        b = c;
        c = temp;
    }
    
    // 按格式输出
    cout << a << "->" << b << "->" << c << endl;
    
    return 0;
}