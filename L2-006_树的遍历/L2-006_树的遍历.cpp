#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

/**
 * L2-006 - 树的遍历
 * 
 * 实现原理：
 * 根据后序遍历和中序遍历构建二叉树，然后输出层序遍历。
 * 
 * 解题思路：
 * 1. 后序遍历的最后一个节点是根节点
 * 2. 在中序遍历中找到根节点，左边是左子树，右边是右子树
 * 3. 递归构建左子树和右子树
 * 4. 使用队列进行层序遍历
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(vector<int>& postorder, int post_start, int post_end,
                   vector<int>& inorder, int in_start, int in_end,
                   unordered_map<int, int>& in_map) {
    if (post_start > post_end || in_start > in_end) {
        return nullptr;
    }
    
    int root_val = postorder[post_end];
    TreeNode* root = new TreeNode(root_val);
    
    int in_root = in_map[root_val];
    int left_size = in_root - in_start;
    
    root->left = buildTree(postorder, post_start, post_start + left_size - 1,
                          inorder, in_start, in_root - 1, in_map);
    root->right = buildTree(postorder, post_start + left_size, post_end - 1,
                           inorder, in_root + 1, in_end, in_map);
    
    return root;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> postorder(N);
    vector<int> inorder(N);
    
    for (int i = 0; i < N; i++) {
        cin >> postorder[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> inorder[i];
    }
    
    unordered_map<int, int> in_map;
    for (int i = 0; i < N; i++) {
        in_map[inorder[i]] = i;
    }
    
    TreeNode* root = buildTree(postorder, 0, N - 1, inorder, 0, N - 1, in_map);
    
    // 层序遍历
    queue<TreeNode*> q;
    q.push(root);
    
    bool first = true;
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        
        if (first) {
            first = false;
        } else {
            cout << " ";
        }
        cout << node->val;
        
        if (node->left) {
            q.push(node->left);
        }
        if (node->right) {
            q.push(node->right);
        }
    }
    cout << endl;
    
    return 0;
}