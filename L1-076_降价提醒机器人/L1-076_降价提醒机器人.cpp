#include <iostream>
#include <iomanip>
using namespace std;

/**
 * L1-076 - 降价提醒机器人
 * 
 * 实现原理：
 * 检查每条价格记录是否比设定价格便宜，如果是则发出提醒。
 * 
 * 解题思路：
 * 1. 读取N和M
 * 2. 读取N条价格记录
 * 3. 对每条价格记录，如果比M便宜，则输出提醒
 */
int main() {
    int N;
    double M;
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        double P;
        cin >> P;
        
        if (P < M) {
            cout << fixed << setprecision(1) << "On Sale! " << P << endl;
        }
    }
    
    return 0;
}