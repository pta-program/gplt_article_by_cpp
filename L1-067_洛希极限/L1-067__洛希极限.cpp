#include <iostream>
#include <iomanip>
using namespace std;

/**
 * L1-067 - 洛希极限
 * 
 * 实现原理：
 * 洛希极限计算公式：
 * - 流体：洛希极限 = 密度比^(1/3) × 2.455 × 大天体半径
 * - 刚体：洛希极限 = 密度比^(1/3) × 1.26 × 大天体半径
 * 
 * 输入给出的是密度比^(1/3)的值，所以：
 * - 流体：洛希极限/大天体半径 = 密度比^(1/3) × 2.455
 * - 刚体：洛希极限/大天体半径 = 密度比^(1/3) × 1.26
 * 
 * 判断是否会被撕碎：
 * - 如果两个天体的距离/大天体半径 > 洛希极限/大天体半径，则不会被撕碎
 * - 否则会被撕碎
 * 
 * 解题思路：
 * 1. 读取三个值：密度比^(1/3)、小天体属性、距离比值
 * 2. 根据小天体属性计算洛希极限比值
 * 3. 判断是否会被撕碎
 * 4. 输出结果
 */
int main() {
    double density_ratio, distance_ratio;
    int type;
    cin >> density_ratio >> type >> distance_ratio;
    
    double roche_limit;
    
    if (type == 0) {
        // 流体
        roche_limit = density_ratio * 2.455;
    } else {
        // 刚体
        roche_limit = density_ratio * 1.26;
    }
    
    // 判断是否会被撕碎
    cout << fixed << setprecision(2) << roche_limit << " ";
    
    if (distance_ratio > roche_limit) {
        cout << "^_^" << endl;
    } else {
        cout << "T_T" << endl;
    }
    
    return 0;
}