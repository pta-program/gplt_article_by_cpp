#include <iostream>
#include <iomanip>
using namespace std;

/**
 * L1-029 - 是不是太胖了
 * 
 * 实现原理：
 * 根据公式计算标准体重：
 * 标准体重（公斤）= (身高 - 100) * 0.9
 * 标准体重（市斤）= 标准体重（公斤）* 2
 * 
 * 解题思路：
 * 1. 读取身高H（单位：厘米）
 * 2. 按照公式计算标准体重（市斤）
 * 3. 输出结果，保留1位小数
 */
int main() {
    int H;
    cin >> H;
    
    // 计算标准体重（市斤）
    // 公式：(H - 100) * 0.9 * 2 = (H - 100) * 1.8
    double weight = (H - 100) * 1.8;
    
    // 输出结果，保留1位小数
    cout << fixed << setprecision(1) << weight << endl;
    
    return 0;
}