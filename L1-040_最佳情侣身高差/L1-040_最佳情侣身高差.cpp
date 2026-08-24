#include <iostream>
#include <iomanip>
using namespace std;

/**
 * L1-040 - 最佳情侣身高差
 * 
 * 实现原理：
 * 根据公式计算最佳情侣身高：
 * - 如果是男性(M)：最佳女伴身高 = 男性身高 / 1.09
 * - 如果是女性(F)：最佳男伴身高 = 女性身高 * 1.09
 * 
 * 解题思路：
 * 1. 读取查询人数N
 * 2. 对每个人：
 *    - 读取性别和身高
 *    - 根据性别计算最佳情侣身高
 *    - 输出结果，保留2位小数
 */
int main() {
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        char gender;
        double height;
        cin >> gender >> height;
        
        double partner_height;
        
        if (gender == 'M') {
            // 男性，计算最佳女伴身高
            partner_height = height / 1.09;
        } else {
            // 女性，计算最佳男伴身高
            partner_height = height * 1.09;
        }
        
        cout << fixed << setprecision(2) << partner_height << endl;
    }
    
    return 0;
}