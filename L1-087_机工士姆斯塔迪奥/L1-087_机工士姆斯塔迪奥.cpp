#include <iostream>
#include <unordered_set>
using namespace std;

/**
 * L1-087 - 机工士姆斯塔迪奥
 * 
 * 实现原理：
 * BOSS释放技能会覆盖若干行或列，玩家不能站在这些格子上。
 * 计算安全格子数量 = 总格子数 - 被覆盖的格子数。
 * 
 * 解题思路：
 * 1. 使用两个集合分别记录被覆盖的行和列
 * 2. 安全格子 = (总行数 - 被覆盖行数) * (总列数 - 被覆盖列数)
 */
int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    
    unordered_set<int> rows, cols;
    
    for (int i = 0; i < Q; i++) {
        int T, C;
        cin >> T >> C;
        
        if (T == 0) {
            rows.insert(C);
        } else {
            cols.insert(C);
        }
    }
    
    int safe_rows = N - rows.size();
    int safe_cols = M - cols.size();
    
    cout << safe_rows * safe_cols << endl;
    
    return 0;
}