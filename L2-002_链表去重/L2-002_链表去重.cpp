#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

/**
 * L2-002 - 链表去重
 * 
 * 实现原理：
 * 遍历链表，删除绝对值重复的节点。
 * 使用哈希表记录已经出现过的绝对值。
 * 将删除的节点保存到另一个链表中。
 * 
 * 解题思路：
 * 1. 读取所有节点，使用 map 存储节点信息
 * 2. 遍历原始链表，分离出保留的节点和删除的节点
 * 3. 输出两个链表
 */
struct Node {
    int key;
    int next;
};

int main() {
    int head, N;
    cin >> head >> N;
    
    map<int, Node> nodes;
    for (int i = 0; i < N; i++) {
        int addr, key, next;
        cin >> addr >> key >> next;
        nodes[addr] = {key, next};
    }
    
    vector<int> kept_list;
    vector<int> removed_list;
    map<int, bool> visited;
    
    int curr = head;
    while (curr != -1) {
        int abs_key = abs(nodes[curr].key);
        
        if (!visited[abs_key]) {
            visited[abs_key] = true;
            kept_list.push_back(curr);
        } else {
            removed_list.push_back(curr);
        }
        
        curr = nodes[curr].next;
    }
    
    // 输出保留的链表
    for (size_t i = 0; i < kept_list.size(); i++) {
        int addr = kept_list[i];
        int next_addr = (i < kept_list.size() - 1) ? kept_list[i + 1] : -1;
        printf("%05d %d ", addr, nodes[addr].key);
        if (next_addr == -1) {
            cout << -1 << endl;
        } else {
            printf("%05d\n", next_addr);
        }
    }
    
    // 输出删除的链表
    for (size_t i = 0; i < removed_list.size(); i++) {
        int addr = removed_list[i];
        int next_addr = (i < removed_list.size() - 1) ? removed_list[i + 1] : -1;
        printf("%05d %d ", addr, nodes[addr].key);
        if (next_addr == -1) {
            cout << -1 << endl;
        } else {
            printf("%05d\n", next_addr);
        }
    }
    
    return 0;
}