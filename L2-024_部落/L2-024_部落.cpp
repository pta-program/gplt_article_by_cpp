#include <iostream>
#include <unordered_set>
using namespace std;

/**
 * L2-024 - 部落
 * 
 * 实现原理：
 * 使用并查集（Union-Find）来管理朋友圈。
 * 朋友的朋友都算在一个部落里。
 * 
 * 解题思路：
 * 1. 使用并查集将同一个小圈子的人合并
 * 2. 统计总人数和不同部落的数量
 * 3. 对每个查询检查两个人是否在同一集合
 */
const int MAX_PEOPLE = 10001;

int parent[MAX_PEOPLE];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y) {
    parent[find(x)] = find(y);
}

int main() {
    for (int i = 1; i < MAX_PEOPLE; i++) {
        parent[i] = i;
    }
    
    int N;
    cin >> N;
    
    unordered_set<int> people_set;
    
    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;
        
        int first_person;
        cin >> first_person;
        people_set.insert(first_person);
        
        for (int j = 1; j < K; j++) {
            int person;
            cin >> person;
            people_set.insert(person);
            unite(first_person, person);
        }
    }
    
    unordered_set<int> tribes;
    for (int person : people_set) {
        tribes.insert(find(person));
    }
    
    cout << people_set.size() << " " << tribes.size() << endl;
    
    int Q;
    cin >> Q;
    
    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        
        if (find(a) == find(b)) {
            cout << "Y" << endl;
        } else {
            cout << "N" << endl;
        }
    }
    
    return 0;
}