#include <iostream>
using namespace std;

/**
 * L1-099 - 帮助色盲
 * 
 * 实现原理：
 * 根据交通灯颜色和前方行人状态给出提示。
 * 规则：
 * - 红灯(0)或绿灯(1)时：
 *   - 如果前方有人(B=1)：不提示，患者自己判断
 *   - 如果前方没人(B=0)：根据灯色给出提示
 * - 黄灯(2)：不提示，患者应该停下
 * 
 * 解题思路：
 * 1. 读取A和B
 * 2. 根据条件判断提示音和动作
 * 3. 输出结果
 */
int main() {
    int A, B;
    cin >> A >> B;
    
    string sound, action;
    
    if (A == 0) {
        // 红灯
        if (B == 1) {
            sound = "-";
            action = "stop";
        } else {
            sound = "biii";
            action = "stop";
        }
    } else if (A == 1) {
        // 绿灯
        if (B == 1) {
            sound = "-";
            action = "move";
        } else {
            sound = "dudu";
            action = "move";
        }
    } else {
        // 黄灯
        sound = "-";
        action = "stop";
    }
    
    cout << sound << endl;
    cout << action << endl;
    
    return 0;
}