#include <iostream>
#include <string>
using namespace std;

/**
 * L1-096 - 谁管谁叫爹
 * 
 * 实现原理：
 * 判断谁是爹的规则：
 * 1. 将两个整数的各位数字分别相加，得到S_A和S_B
 * 2. 如果N_A是S_B的整数倍，则A是爹
 * 3. 如果N_B是S_A的整数倍，则B是爹
 * 4. 如果同时满足或同时不满足，则数字大的是爹
 * 
 * 解题思路：
 * 1. 读取N组数据
 * 2. 对每组数据计算各位数字之和
 * 3. 判断谁是爹
 * 4. 输出结果
 */
long long sum_digits(long long num) {
    long long sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        long long A, B;
        cin >> A >> B;
        
        long long S_A = sum_digits(A);
        long long S_B = sum_digits(B);
        
        bool A_win = (A % S_B == 0);
        bool B_win = (B % S_A == 0);
        
        char result;
        if (A_win && !B_win) {
            result = 'A';
        } else if (!A_win && B_win) {
            result = 'B';
        } else {
            result = (A > B) ? 'A' : 'B';
        }
        
        cout << result << endl;
    }
    
    return 0;
}