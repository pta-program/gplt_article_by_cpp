#include <iostream>
using namespace std;

/**
 * L1-098 - 再进去几个人
 * 
 * 实现原理：
 * 根据数学家的逻辑计算需要再进去几个人。
 * 进去A人，出来B人，要让房子变空需要再进去 (B - A) 人。
 * 
 * 解题思路：
 * 1. 读取A和B
 * 2. 计算需要再进去的人数 = B - A
 * 3. 输出结果
 */
int main() {
    int A, B;
    cin >> A >> B;
    
    cout << B - A << endl;
    
    return 0;
}