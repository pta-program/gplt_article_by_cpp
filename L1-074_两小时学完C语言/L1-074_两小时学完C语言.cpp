#include <iostream>
using namespace std;

/**
 * L1-074 - 两小时学完C语言
 * 
 * 实现原理：
 * 计算宝宝还没看的字数。
 * 已看字数 = K * M
 * 剩余字数 = N - 已看字数
 * 
 * 解题思路：
 * 1. 读取N、K、M
 * 2. 计算已看字数
 * 3. 计算剩余字数
 * 4. 输出结果
 */
int main() {
    int N, K, M;
    cin >> N >> K >> M;
    
    // 计算已看字数
    int read = K * M;
    
    // 计算剩余字数
    int remaining = N - read;
    
    cout << remaining << endl;
    
    return 0;
}