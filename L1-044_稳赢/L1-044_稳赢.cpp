#include <iostream>
#include <string>
using namespace std;

/**
 * L1-044 - 稳赢
 * 
 * 实现原理：
 * 根据对方的出招，给出稳赢的招式。
 * 胜负规则：
 * - 锤子赢剪刀（ChuiZi > JianDao）
 * - 剪刀赢布（JianDao > Bu）
 * - 布赢锤子（Bu > ChuiZi）
 * 
 * 每隔K次就让一次平局，即第K+1次、第2K+1次、...输出相同的招式。
 * 
 * 解题思路：
 * 1. 读取K值
 * 2. 读取对方的出招，直到遇到"End"
 * 3. 记录对战次数，每隔K次输出平局
 * 4. 否则输出稳赢的招式
 */
int main() {
    int K;
    cin >> K;
    
    int count = 0;  // 对战次数
    
    while (true) {
        string opponent;
        cin >> opponent;
        
        if (opponent == "End") {
            break;
        }
        
        count++;
        
        // 判断是否需要平局（每隔K次）
        if (count % (K + 1) == 0) {
            // 平局，输出相同的招式
            cout << opponent << endl;
        } else {
            // 稳赢，输出克制对方的招式
            if (opponent == "ChuiZi") {
                cout << "Bu" << endl;
            } else if (opponent == "JianDao") {
                cout << "ChuiZi" << endl;
            } else if (opponent == "Bu") {
                cout << "JianDao" << endl;
            }
        }
    }
    
    return 0;
}