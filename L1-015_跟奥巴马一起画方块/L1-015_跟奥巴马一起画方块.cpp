#include <iostream>
using namespace std;

/**
 * L1-015 - 跟奥巴马一起画方块
 * 
 * 实现原理：
 * 由于行间距比列间距大，输出的行数是列数的50%（四舍五入）。
 * 例如：列数为10，则行数为5；列数为11，则行数为6。
 * 
 * 解题思路：
 * 1. 读取正方形边长N和字符C
 * 2. 计算行数：round(N * 0.5) = (N + 1) / 2（整数除法实现四舍五入）
 * 3. 每行输出N个字符C，共输出计算得到的行数
 */
int main() {
    int N;
    char C;
    cin >> N >> C;
    
    // 计算行数：列数的50%，四舍五入
    int rows = (N + 1) / 2;
    
    // 输出正方形
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < N; j++) {
            cout << C;
        }
        cout << endl;
    }
    
    return 0;
}