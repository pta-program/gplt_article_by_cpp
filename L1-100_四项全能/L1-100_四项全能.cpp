#include <iostream>
using namespace std;

/**
 * L1-100 - 四项全能
 * 
 * 实现原理：
 * 计算至少有多少人m项技能都会。
 * 方法：假设每人最多会m-1项技能，计算总技能点数。
 * 如果总技能点数超过了每人m-1项的总和，则超出部分就是至少m项都会的人数。
 * 
 * 公式：max(0, sum(k_i) - n * (m - 1))
 * 
 * 解题思路：
 * 1. 读取n和m
 * 2. 读取m个技能人数
 * 3. 计算总技能点数
 * 4. 使用公式计算结果
 */
int main() {
    int n, m;
    cin >> n >> m;
    
    int sum_k = 0;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        sum_k += k;
    }
    
    int result = sum_k - n * (m - 1);
    if (result < 0) {
        result = 0;
    }
    
    cout << result << endl;
    
    return 0;
}