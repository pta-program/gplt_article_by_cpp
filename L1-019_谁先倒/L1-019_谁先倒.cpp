#include <iostream>
using namespace std;

/**
 * L1-019 - 谁先倒
 * 
 * 实现原理：
 * 划拳规则：
 * 1. 甲喊的数字 + 乙喊的数字 = 和
 * 2. 如果甲划出的数字 == 和，甲输（喝一杯）
 * 3. 如果乙划出的数字 == 和，乙输（喝一杯）
 * 4. 两人同赢或同输则继续
 * 5. 当某人喝的杯数超过酒量时，该人倒下
 * 
 * 解题思路：
 * 1. 读取甲、乙两人的酒量
 * 2. 读取划拳轮数N和N轮划拳记录
 * 3. 模拟每一轮划拳：
 *    - 判断谁输
 *    - 输家喝一杯
 *    - 检查是否有人倒下
 *    - 如果有人倒下，输出结果并终止程序
 */
int main() {
    int capacityA, capacityB;  // 甲、乙的酒量
    cin >> capacityA >> capacityB;
    
    int N;  // 划拳轮数
    cin >> N;
    
    int drunkA = 0;  // 甲已喝的杯数
    int drunkB = 0;  // 乙已喝的杯数
    
    for (int i = 0; i < N; i++) {
        int shoutA, drawA, shoutB, drawB;
        cin >> shoutA >> drawA >> shoutB >> drawB;
        
        int sum = shoutA + shoutB;
        
        bool A_lose = (drawA == sum);
        bool B_lose = (drawB == sum);
        
        // 只有一人输的情况下才罚酒
        if (A_lose && !B_lose) {
            drunkA++;
        } else if (B_lose && !A_lose) {
            drunkB++;
        }
        
        // 检查是否有人倒下
        if (drunkA > capacityA) {
            cout << "A" << endl;
            cout << drunkB << endl;
            return 0;
        }
        if (drunkB > capacityB) {
            cout << "B" << endl;
            cout << drunkA << endl;
            return 0;
        }
    }
    
    return 0;
}