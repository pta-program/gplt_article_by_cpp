#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

/**
 * L2-022 - 重排链表
 * 
 * 实现原理：
 * 将链表重新排列为 L_n -> L_1 -> L_{n-1} -> L_2 -> ...
 * 
 * 解题思路：
 * 1. 使用数组存储链表节点
 * 2. 先遍历链表，按顺序存储所有节点
 * 3. 重排：从两端交替取节点
 * 4. 更新每个节点的Next指针
 */
struct Node {
    int data;
    int next;
};

int main() {
    int head, N;
    cin >> head >> N;
    
    vector<Node> nodes(100000);
    
    for (int i = 0; i < N; i++) {
        int addr, data, next;
        cin >> addr >> data >> next;
        nodes[addr].data = data;
        nodes[addr].next = next;
    }
    
    vector<int> list;
    int curr = head;
    while (curr != -1) {
        list.push_back(curr);
        curr = nodes[curr].next;
    }
    
    vector<int> result;
    int left = 0, right = list.size() - 1;
    bool take_right = true;
    
    while (left <= right) {
        if (take_right) {
            result.push_back(list[right]);
            right--;
        } else {
            result.push_back(list[left]);
            left++;
        }
        take_right = !take_right;
    }
    
    for (int i = 0; i < result.size(); i++) {
        if (i < result.size() - 1) {
            printf("%05d %d %05d\n", result[i], nodes[result[i]].data, result[i+1]);
        } else {
            printf("%05d %d -1\n", result[i], nodes[result[i]].data);
        }
    }
    
    return 0;
}