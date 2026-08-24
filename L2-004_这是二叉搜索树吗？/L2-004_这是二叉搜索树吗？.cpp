#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * L2-004 - 这是二叉搜索树吗？
 * 
 * 实现原理：
 * 判断一个序列是否是二叉搜索树或其镜像的前序遍历结果。
 * 
 * 解题思路：
 * 1. 方法一：递归验证
 *    - 对于二叉搜索树：左子树 < 根 <= 右子树
 *    - 对于镜像二叉搜索树：左子树 >= 根 > 右子树
 * 2. 方法二：将序列排序后对比中序遍历
 *    - 二叉搜索树的中序遍历是升序的
 *    - 镜像二叉搜索树的中序遍历是降序的
 * 
 * 采用递归验证的方法：
 * 1. 判断是否是二叉搜索树的前序遍历
 * 2. 判断是否是镜像二叉搜索树的前序遍历
 * 3. 如果是其中之一，输出后序遍历结果
 */
vector<int> pre;
vector<int> post;
bool is_bst = true;
bool is_mirror = true;

void verify_bst(int start, int end) {
    if (start >= end || !is_bst) {
        return;
    }
    
    int root = pre[start];
    int mid = start + 1;
    
    while (mid <= end && pre[mid] < root) {
        mid++;
    }
    
    for (int i = mid; i <= end; i++) {
        if (pre[i] < root) {
            is_bst = false;
            return;
        }
    }
    
    verify_bst(start + 1, mid - 1);
    verify_bst(mid, end);
}

void verify_mirror(int start, int end) {
    if (start >= end || !is_mirror) {
        return;
    }
    
    int root = pre[start];
    int mid = start + 1;
    
    while (mid <= end && pre[mid] >= root) {
        mid++;
    }
    
    for (int i = mid; i <= end; i++) {
        if (pre[i] >= root) {
            is_mirror = false;
            return;
        }
    }
    
    verify_mirror(start + 1, mid - 1);
    verify_mirror(mid, end);
}

void postorder_bst(int start, int end) {
    if (start > end) {
        return;
    }
    
    int root = pre[start];
    int mid = start + 1;
    
    while (mid <= end && pre[mid] < root) {
        mid++;
    }
    
    postorder_bst(start + 1, mid - 1);
    postorder_bst(mid, end);
    post.push_back(root);
}

void postorder_mirror(int start, int end) {
    if (start > end) {
        return;
    }
    
    int root = pre[start];
    int mid = start + 1;
    
    while (mid <= end && pre[mid] >= root) {
        mid++;
    }
    
    postorder_mirror(start + 1, mid - 1);
    postorder_mirror(mid, end);
    post.push_back(root);
}

int main() {
    int N;
    cin >> N;
    
    pre.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> pre[i];
    }
    
    if (N <= 1) {
        cout << "YES" << endl;
        cout << pre[0] << endl;
        return 0;
    }
    
    verify_bst(0, N - 1);
    verify_mirror(0, N - 1);
    
    if (is_bst) {
        postorder_bst(0, N - 1);
        cout << "YES" << endl;
        for (size_t i = 0; i < post.size(); i++) {
            if (i > 0) {
                cout << " ";
            }
            cout << post[i];
        }
        cout << endl;
    } else if (is_mirror) {
        postorder_mirror(0, N - 1);
        cout << "YES" << endl;
        for (size_t i = 0; i < post.size(); i++) {
            if (i > 0) {
                cout << " ";
            }
            cout << post[i];
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}