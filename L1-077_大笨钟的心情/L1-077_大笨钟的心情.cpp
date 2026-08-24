#include <iostream>
using namespace std;

/**
 * L1-077 - 大笨钟的心情
 * 
 * 实现原理：
 * 读取24小时的心情指数，然后根据用户的查询输出对应的心情状态。
 * 如果心情指数 > 50，输出"Yes"，否则输出"No"。
 * 当输入非法时间点时停止处理。
 * 
 * 解题思路：
 * 1. 读取24个心情指数
 * 2. 循环读取查询时间点：
 *    - 如果时间点在0-23范围内，输出对应心情状态
 *    - 如果时间点不在范围内，停止处理
 */
int main() {
    int mood[24];
    
    // 读取24小时的心情指数
    for (int i = 0; i < 24; i++) {
        cin >> mood[i];
    }
    
    // 处理查询
    int time;
    while (cin >> time) {
        if (time < 0 || time >= 24) {
            break;
        }
        
        cout << mood[time] << " ";
        if (mood[time] > 50) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}