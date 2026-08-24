#include <iostream>
#include <vector>
using namespace std;

/**
 * L2-035 - 完全二叉树的层序遍历
 * 
 * 实现原理：
 * 根据后序遍历重建完全二叉树，并输出层序遍历结果。
 * 完全二叉树特点：
 * - 第i个节点（从1开始）的左子节点是2i，右子节点是2i+1
 * 
 * 解题思路：
 * 1. 使用数组存储完全二叉树（索引从1开始）
 * 2. 后序遍历的最后一个元素是根节点
 * 3. 根据完全二叉树性质递归构建
 */
void build(int root, const vector<int>& postorder, int& idx, vector<int>& level) {
    if (root >= level.size()) return;
    
    build(2 * root, postorder, idx, level);
    build(2 * root + 1, postorder, idx, level);
    
    level[root] = postorder[idx++];
}

int main() {
    int N;
    cin >> N;
    
    vector<int> postorder(N);
    for (int i = 0; i < N; i++) {
        cin >> postorder[i];
    }
    
    vector<int> level(N + 1);
    int idx = 0;
    
    build(1, postorder, idx, level);
    
    for (int i = 1; i <= N; i++) {
        if (i > 1) {
            cout << " ";
        }
        cout << level[i];
    }
    cout << endl;
    
    return 0;
}