#include <iostream>
using namespace std;

/**
 * L1-022 - 奇偶分家
 * 
 * 实现原理：
 * 判断一个整数是奇数还是偶数，只需要检查它除以2的余数。
 * 如果余数为0，则是偶数；否则是奇数。
 * 
 * 解题思路：
 * 1. 读取整数N
 * 2. 读取N个整数
 * 3. 统计奇数和偶数的个数
 * 4. 输出结果
 */
int main() {
    int N;
    cin >> N;
    
    int odd_count = 0;   // 奇数个数
    int even_count = 0;  // 偶数个数
    
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        
        if (num % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }
    
    cout << odd_count << " " << even_count << endl;
    
    return 0;
}