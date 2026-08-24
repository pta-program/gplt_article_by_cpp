#include <iostream>
#include <set>
using namespace std;

/**
 * L1-104 - 九宫格
 * 
 * 实现原理：
 * 判断一个9x9的九宫格是否符合规则：
 * 1. 每一行的数字1-9不重复
 * 2. 每一列的数字1-9不重复
 * 3. 每个3x3宫位的数字1-9不重复
 * 4. 所有数字都必须是1-9之间的整数
 * 
 * 解题思路：
 * 1. 读取n个九宫格
 * 2. 对每个九宫格检查：
 *    - 检查每行是否符合规则
 *    - 检查每列是否符合规则
 *    - 检查每个3x3宫位是否符合规则
 *    - 检查所有数字是否在1-9范围内
 * 3. 输出结果
 */
bool isValid(int grid[9][9]) {
    // 检查每行
    for (int i = 0; i < 9; i++) {
        set<int> row;
        for (int j = 0; j < 9; j++) {
            int num = grid[i][j];
            if (num < 1 || num > 9) {
                return false;
            }
            if (row.count(num)) {
                return false;
            }
            row.insert(num);
        }
    }
    
    // 检查每列
    for (int j = 0; j < 9; j++) {
        set<int> col;
        for (int i = 0; i < 9; i++) {
            int num = grid[i][j];
            if (col.count(num)) {
                return false;
            }
            col.insert(num);
        }
    }
    
    // 检查每个3x3宫位
    for (int block = 0; block < 9; block++) {
        set<int> cell;
        int start_row = (block / 3) * 3;
        int start_col = (block % 3) * 3;
        for (int i = start_row; i < start_row + 3; i++) {
            for (int j = start_col; j < start_col + 3; j++) {
                int num = grid[i][j];
                if (cell.count(num)) {
                    return false;
                }
                cell.insert(num);
            }
        }
    }
    
    return true;
}

int main() {
    int n;
    cin >> n;
    
    for (int k = 0; k < n; k++) {
        int grid[9][9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cin >> grid[i][j];
            }
        }
        
        if (isValid(grid)) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    
    return 0;
}