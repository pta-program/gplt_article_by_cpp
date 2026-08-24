#include <iostream>
using namespace std;

/**
 * L1-079 - 天梯赛的善良
 * 
 * 实现原理：
 * 找出所有参赛学生的最小和最大能力值，以及它们的人数。
 * 
 * 解题思路：
 * 1. 读取学生人数N
 * 2. 读取N个能力值
 * 3. 找出最小值和最大值
 * 4. 统计最小值和最大值的人数
 * 5. 输出结果
 */
int main() {
    int N;
    cin >> N;
    
    int abilities[20000];
    
    int min_val = 1000001;
    int max_val = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> abilities[i];
        
        if (abilities[i] < min_val) {
            min_val = abilities[i];
        }
        if (abilities[i] > max_val) {
            max_val = abilities[i];
        }
    }
    
    // 统计人数
    int min_count = 0;
    int max_count = 0;
    
    for (int i = 0; i < N; i++) {
        if (abilities[i] == min_val) {
            min_count++;
        }
        if (abilities[i] == max_val) {
            max_count++;
        }
    }
    
    // 输出结果
    cout << min_val << " " << min_count << endl;
    cout << max_val << " " << max_count << endl;
    
    return 0;
}