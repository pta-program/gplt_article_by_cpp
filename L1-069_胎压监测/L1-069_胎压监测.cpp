#include <iostream>
using namespace std;

/**
 * L1-069 - 胎压监测
 * 
 * 实现原理：
 * 监测四轮的胎压，判断是否需要报警。
 * 报警规则：
 * 1. 如果所有轮胎压力与最大值误差在阈值内，且都不低于最低报警胎压，则正常
 * 2. 如果只有一个轮胎异常，输出该轮胎编号
 * 3. 如果有两个或以上轮胎异常，输出检查所有轮胎
 * 
 * 解题思路：
 * 1. 读取四个胎压、最低报警胎压、阈值
 * 2. 找出最大胎压值
 * 3. 检查每个轮胎是否异常
 * 4. 根据异常轮胎数量输出相应信息
 */
int main() {
    int pressure[4];
    int min_pressure, threshold;
    
    cin >> pressure[0] >> pressure[1] >> pressure[2] >> pressure[3];
    cin >> min_pressure >> threshold;
    
    // 找出最大胎压值
    int max_pressure = pressure[0];
    for (int i = 1; i < 4; i++) {
        if (pressure[i] > max_pressure) {
            max_pressure = pressure[i];
        }
    }
    
    // 检查每个轮胎是否异常
    int abnormal_count = 0;
    int abnormal_tire = -1;
    
    for (int i = 0; i < 4; i++) {
        bool is_abnormal = false;
        
        // 检查与最大值的误差是否超过阈值
        if (max_pressure - pressure[i] > threshold) {
            is_abnormal = true;
        }
        
        // 检查是否低于最低报警胎压
        if (pressure[i] < min_pressure) {
            is_abnormal = true;
        }
        
        if (is_abnormal) {
            abnormal_count++;
            abnormal_tire = i + 1;  // 轮胎编号从1开始
        }
    }
    
    // 输出结果
    if (abnormal_count == 0) {
        cout << "Normal" << endl;
    } else if (abnormal_count == 1) {
        cout << "Warning: please check #" << abnormal_tire << "!" << endl;
    } else {
        cout << "Warning: please check all the tires!" << endl;
    }
    
    return 0;
}