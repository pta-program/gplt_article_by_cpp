#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * L2-014 - 列车调度
 * 
 * 实现原理：
 * 使用贪心算法，模拟列车调度过程。
 * 每条轨道上的列车编号必须是递减的。
 * 对于每个列车，找到第一条末尾列车编号大于当前列车编号的轨道。
 * 如果没有这样的轨道，新建一条轨道。
 * 
 * 解题思路：
 * 1. 维护一个数组，记录每条轨道末尾的列车编号
 * 2. 对于每个列车：
 *    - 使用二分查找找到第一条末尾列车编号大于当前列车编号的轨道
 *    - 更新该轨道的末尾编号
 *    - 如果没有找到，新建一条轨道
 * 3. 返回轨道数量
 */
int main() {
    int N;
    cin >> N;
    
    vector<int> rails;
    
    for (int i = 0; i < N; i++) {
        int train;
        cin >> train;
        
        auto it = lower_bound(rails.begin(), rails.end(), train);
        
        if (it == rails.end()) {
            rails.push_back(train);
        } else {
            *it = train;
        }
    }
    
    cout << rails.size() << endl;
    
    return 0;
}