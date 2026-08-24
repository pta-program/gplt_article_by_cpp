#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-010 是否完全二叉搜索树
 *
 * 题目描述：
 *   给定一个整数序列，表示按照某种规则插入到二叉搜索树中的顺序。
 *   规则是：新节点总是插入到当前节点的左子树（如果新值大于当前节点）或右子树（如果新值小于当前节点）。
 *   要求判断构建的二叉树是否是完全二叉搜索树，并输出层序遍历结果。
 *   输入格式：第一行给出整数 N，表示序列长度。第二行给出 N 个整数，表示插入序列。
 *   输出格式：第一行输出层序遍历结果，第二行输出 "YES" 或 "NO"。
 *
 * 实现原理：
 *   1. 按照题设规则构建二叉搜索树：
 *      a. 新值 > 当前节点值：插入到左子树。
 *      b. 新值 < 当前节点值：插入到右子树。
 *   2. 使用层序遍历（BFS）判断是否为完全二叉树：
 *      a. 如果在层序遍历中遇到空孩子，则标记 seen_empty = 1。
 *      b. 如果在 seen_empty = 1 之后又遇到非空孩子，则不是完全二叉树。
 *   3. 同时输出层序遍历结果。
 *
 * 时间复杂度：O(N)，构建树和层序遍历都是线性的
 */
typedef struct { int key,left,right; } Node;
int main(void) {
    Node tree[25]; int n,i,root=-1,count=0,q[25],head=0,tail=0,seen_empty=0,complete=1;
    scanf("%d",&n);
    for(i=0;i<n;++i){int x,cur,parent=-1;scanf("%d",&x);tree[i]=(Node){x,-1,-1};if(root<0){root=i;continue;}cur=root;while(cur>=0){parent=cur;cur=x>tree[cur].key?tree[cur].left:tree[cur].right;}if(x>tree[parent].key)tree[parent].left=i;else tree[parent].right=i;}
    q[tail++]=root;
    while(head<tail){int u=q[head++];printf("%s%d",count++?" ":"",tree[u].key);if(tree[u].left>=0){if(seen_empty)complete=0;q[tail++]=tree[u].left;}else seen_empty=1;if(tree[u].right>=0){if(seen_empty)complete=0;q[tail++]=tree[u].right;}else seen_empty=1;}
    printf("\n%s\n",complete?"YES":"NO");return 0;
}
