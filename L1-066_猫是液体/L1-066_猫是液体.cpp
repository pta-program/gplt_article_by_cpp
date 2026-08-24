#include <iostream>
using namespace std;

/**
 * L1-066 - 猫是液体
 * 
 * 实现原理：
 * 猫是液体，所以猫的体积等于容器的容积。
 * 容器容积 = 长 × 宽 × 高
 * 
 * 解题思路：
 * 1. 读取长、宽、高
 * 2. 计算体积
 * 3. 输出结果
 */
int main() {
    int length, width, height;
    cin >> length >> width >> height;
    
    // 计算体积
    int volume = length * width * height;
    
    cout << volume << endl;
    
    return 0;
}