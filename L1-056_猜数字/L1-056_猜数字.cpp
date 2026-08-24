#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/**
 * L1-056 - 猜数字
 * 
 * 实现原理：
 * 计算所有玩家猜测数字的平均数的一半（只取整数部分）。
 * 找到最接近这个值的玩家。
 * 
 * 解题思路：
 * 1. 读取玩家人数N
 * 2. 读取每个玩家的名字和猜测的数字
 * 3. 计算所有数字的总和和平均数
 * 4. 计算平均数的一半（取整数部分）
 * 5. 找到最接近这个值的玩家
 * 6. 输出结果
 */
int main() {
    int N;
    cin >> N;
    
    string names[10000];
    int guesses[10000];
    
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> names[i] >> guesses[i];
        sum += guesses[i];
    }
    
    // 计算平均数的一半（取整数部分）
    int target = sum / N / 2;
    
    // 找到最接近target的玩家
    string winner;
    int min_diff = 101;  // 猜测的数字最大是100
    
    for (int i = 0; i < N; i++) {
        int diff = abs(guesses[i] - target);
        if (diff < min_diff) {
            min_diff = diff;
            winner = names[i];
        }
    }
    
    cout << target << " " << winner << endl;
    
    return 0;
}