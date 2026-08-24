#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/**
 * L2-010 - 排座位
 * 
 * 实现原理：
 * 使用并查集处理朋友关系（朋友的朋友也是朋友），使用邻接表处理敌对关系。
 * 
 * 解题思路：
 * 1. 使用并查集维护朋友关系
 * 2. 使用邻接表维护敌对关系
 * 3. 对于每个查询：
 *    - 判断是否是朋友
 *    - 判断是否是敌人
 *    - 判断是否有共同朋友
 *    - 根据规则输出结果
 */
const int MAXN = 110;

int parent[MAXN];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    
    if (fx != fy) {
        parent[fy] = fx;
    }
}

int main() {
    for (int i = 0; i < MAXN; i++) {
        parent[i] = i;
    }
    
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<unordered_set<int>> enemies(N + 1);
    
    for (int i = 0; i < M; i++) {
        int a, b, r;
        cin >> a >> b >> r;
        
        if (r == 1) {
            unite(a, b);
        } else {
            enemies[a].insert(b);
            enemies[b].insert(a);
        }
    }
    
    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        
        bool is_friend = (find(a) == find(b));
        bool is_enemy = (enemies[a].count(b) > 0);
        
        if (is_friend && !is_enemy) {
            cout << "No problem" << endl;
        } else if (!is_friend && !is_enemy) {
            cout << "OK" << endl;
        } else if (is_enemy && is_friend) {
            cout << "OK but..." << endl;
        } else {
            cout << "No way" << endl;
        }
    }
    
    return 0;
}