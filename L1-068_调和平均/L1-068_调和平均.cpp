#include <iostream>
#include <iomanip>
using namespace std;

/**
 * L1-068 - 调和平均
 * 
 * 实现原理：
 * N个正数的调和平均 = 1 / ( (1/a1 + 1/a2 + ... + 1/aN) / N )
 * = N / (1/a1 + 1/a2 + ... + 1/aN)
 * 
 * 解题思路：
 * 1. 读取N个正数
 * 2. 计算它们倒数的和
 * 3. 计算调和平均值
 * 4. 输出结果，保留2位小数
 */
int main() {
    int N;
    cin >> N;
    
    double sum_reciprocal = 0;
    
    for (int i = 0; i < N; i++) {
        double num;
        cin >> num;
        sum_reciprocal += 1.0 / num;
    }
    
    // 计算调和平均值
    double harmonic_mean = N / sum_reciprocal;
    
    // 输出结果，保留2位小数
    cout << fixed << setprecision(2) << harmonic_mean << endl;
    
    return 0;
}