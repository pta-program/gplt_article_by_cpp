#include <iostream>
#include <string>
using namespace std;

/**
 * L1-047 - 装睡
 * 
 * 实现原理：
 * 判断每个人的呼吸频率和脉搏是否在正常范围内。
 * 正常范围：
 * - 呼吸频率：15-20次/分钟
 * - 脉搏：50-70次/分钟
 * 如果至少一项不在正常范围内，则认为在装睡。
 * 
 * 解题思路：
 * 1. 读取人数N
 * 2. 对每个人：
 *    - 读取名字、呼吸频率、脉搏
 *    - 判断是否在正常范围内
 *    - 如果不在，输出名字
 */
int main() {
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        string name;
        int breathing, pulse;
        cin >> name >> breathing >> pulse;
        
        // 判断是否在装睡
        bool is_faking = false;
        
        // 呼吸频率不在15-20范围内
        if (breathing < 15 || breathing > 20) {
            is_faking = true;
        }
        
        // 脉搏不在50-70范围内
        if (pulse < 50 || pulse > 70) {
            is_faking = true;
        }
        
        if (is_faking) {
            cout << name << endl;
        }
    }
    
    return 0;
}