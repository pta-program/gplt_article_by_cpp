#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/**
 * L1-095 - 分寝室
 * 
 * 实现原理：
 * 分配寝室规则：
 * 1. 男女生不能混住
 * 2. 不允许单人住一间寝室
 * 3. 每种性别的每间寝室入住人数必须相同
 * 4. 在满足前三项的情况下，要求两种性别每间寝室人数差最小
 * 
 * 解题思路：
 * 1. 枚举女生寝室数（从1到n-1）
 * 2. 检查女生是否能被寝室数整除且每间人数>=2
 * 3. 检查男生寝室数=总寝室数-女生寝室数
 * 4. 检查男生是否能被寝室数整除且每间人数>=2
 * 5. 记录满足条件的方案中人数差最小的
 */
int main() {
    int n0, n1, n;
    cin >> n0 >> n1 >> n;
    
    int best_diff = INT_MAX;
    int best_rooms0 = -1, best_rooms1 = -1;
    
    // 枚举女生寝室数
    for (int rooms0 = 1; rooms0 < n; rooms0++) {
        int rooms1 = n - rooms0;
        
        // 检查女生分配
        if (n0 % rooms0 != 0) {
            continue;
        }
        int people0 = n0 / rooms0;
        if (people0 < 2) {
            continue;
        }
        
        // 检查男生分配
        if (n1 % rooms1 != 0) {
            continue;
        }
        int people1 = n1 / rooms1;
        if (people1 < 2) {
            continue;
        }
        
        // 计算人数差
        int diff = abs(people0 - people1);
        
        // 更新最优解
        if (diff < best_diff) {
            best_diff = diff;
            best_rooms0 = rooms0;
            best_rooms1 = rooms1;
        }
    }
    
    if (best_rooms0 == -1) {
        cout << "No Solution" << endl;
    } else {
        cout << best_rooms0 << " " << best_rooms1 << endl;
    }
    
    return 0;
}