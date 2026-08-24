#include <iostream>
using namespace std;

/**
 * L1-092 - 进化论
 * 
 * 实现原理：
 * 判断C是A*B还是A+B。
 * 如果是A*B：吕严算的
 * 如果是A+B：土豆算的
 * 否则：两者都不是
 * 
 * 解题思路：
 * 1. 读取N组数据
 * 2. 对每组数据判断C的来源
 * 3. 输出结果
 */
int main() {
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        
        if (C == A * B) {
            cout << "Lv Yan" << endl;
        } else if (C == A + B) {
            cout << "Tu Dou" << endl;
        } else {
            cout << "zhe du shi sha ya!" << endl;
        }
    }
    
    return 0;
}