#include <iostream>
using namespace std;

/**
 * L1-108 - 零头就抹了吧
 * 
 * 实现原理：
 * 将数字抹掉零头，保留到最接近的2的幂次。
 * 
 * 解题思路：
 * 1. 读取整数N
 * 2. 找到小于等于N的最大2的幂次
 * 3. 如果N等于该幂次，输出N
 * 4. 否则，输出该幂次的前一个2的幂次
 */
int main() {
    int N;
    cin >> N;
    
    int power = 1;
    while (power * 2 <= N) {
        power *= 2;
    }
    
    cout << power << endl;
    
    return 0;
}