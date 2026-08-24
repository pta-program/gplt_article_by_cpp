#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

/**
 * L2-011 - 玩转二叉树
 * 
 * 实现原理：
 * 根据中序遍历和前序遍历构建二叉树，然后进行镜面反转（交换左右子树），最后输出层序遍历。
 * 
 * 解题思路：
 * 1. 前序遍历的第一个节点是根节点
 * 2. 在中序遍历中找到根节点，左边是左子树，右边是右子树
 * 3. 递归构建二叉树
 * 4. 进行镜面反转（交换左右子树）
 * 5. 使用队列进行层序遍历
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(vector<int>& preorder, int pre_start, int pre_end,
                   vector<int>& inorder, int in_start, int in_end,
                   unordered_map<int, int>& in_map) {
    if (pre_start > pre_end || in_start > in_end) {
        return nullptr;
    }
    
    int root_val = preorder[pre_start];
    TreeNode* root = new TreeNode(root_val);
    
    int in_root = in_map[root_val];
    int left_size = in_root - in_start;
    
    root->left = buildTree(preorder, pre_start + 1, pre_start + left_size,
                          inorder, in_start, in_root - 1, in_map);
    root->right = buildTree(preorder, pre_start + left_size + 1, pre_end,
                           inorder, in_root + 1, in_end, in_map);
    
    return root;
}

void mirror(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
}

int main() {
    int N;
    cin >> N;
    
    vector<int> inorder(N);
    vector<int> preorder(N);
    
    for (int i = 0; i < N; i++) {
        cin >> inorder[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> preorder[i];
    }
    
    unordered_map<int, int> in_map;
    for (int i = 0; i < N; i++) {
        in_map[inorder[i]] = i;
    }
    
    TreeNode* root = buildTree(preorder, 0, N - 1, inorder, 0, N - 1, in_map);
    
    mirror(root);
    
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