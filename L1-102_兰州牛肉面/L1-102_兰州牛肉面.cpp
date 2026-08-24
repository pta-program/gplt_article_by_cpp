#include <iostream>
#include <iomanip>
using namespace std;

/**
 * L1-102 - 兰州牛肉面
 * 
 * 实现原理：
 * 统计一天内各种牛肉面的销售情况。
 * 读取品种数量、价格，然后读取销售记录，最后输出统计结果。
 * 
 * 解题思路：
 * 1. 读取牛肉面种类数量N
 * 2. 读取N个价格
 * 3. 读取销售记录，直到品种编号为0
 * 4. 统计每种牛肉面的销售数量
 * 5. 计算总营业额
 * 6. 输出结果
 */
int main() {
    int N;
    cin >> N;
    
    double price[101];
    for (int i = 1; i <= N; i++) {
        cin >> price[i];
    }
    
    int count[101] = {0};
    
    int id, num;
    while (cin >> id >> num) {
        if (id == 0) {
            break;
        }
        count[id] += num;
    }
    
    double total = 0;
    for (int i = 1; i <= N; i++) {
        cout << count[i] << endl;
        total += count[i] * price[i];
    }
    
    cout << fixed << setprecision(2) << total << endl;
    
    return 0;
}