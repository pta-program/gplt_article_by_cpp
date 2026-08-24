#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
using namespace std;

/**
 * L2-007 - 家庭房产
 * 
 * 实现原理：
 * 使用并查集处理家庭关系，统计每个家庭的人口数和房产信息。
 * 
 * 解题思路：
 * 1. 使用并查集合并家庭成员
 * 2. 记录每个家庭的人口数、房产套数和总面积
 * 3. 按人均面积降序排序，若并列则按成员编号升序排序
 */
const int MAXN = 10000;

int parent[MAXN];
int min_id[MAXN];
int people[MAXN];
int houses[MAXN];
double area[MAXN];
bool exists[MAXN];

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
        min_id[fx] = min(min_id[fx], min_id[fy]);
        people[fx] += people[fy];
        houses[fx] += houses[fy];
        area[fx] += area[fy];
    }
}

struct Family {
    int min_id;
    int people;
    double avg_house;
    double avg_area;
};

bool compare(Family a, Family b) {
    if (a.avg_area != b.avg_area) {
        return a.avg_area > b.avg_area;
    }
    return a.min_id < b.min_id;
}

int main() {
    for (int i = 0; i < MAXN; i++) {
        parent[i] = i;
        min_id[i] = i;
        people[i] = 1;
        houses[i] = 0;
        area[i] = 0;
        exists[i] = false;
    }
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int id, father, mother, k;
        cin >> id >> father >> mother >> k;
        
        exists[id] = true;
        
        if (father != -1) {
            exists[father] = true;
            unite(id, father);
        }
        if (mother != -1) {
            exists[mother] = true;
            unite(id, mother);
        }
        
        for (int j = 0; j < k; j++) {
            int child;
            cin >> child;
            exists[child] = true;
            unite(id, child);
        }
        
        int h, a;
        cin >> h >> a;
        
        int root = find(id);
        houses[root] += h;
        area[root] += a;
    }
    
    map<int, Family> families;
    
    for (int i = 0; i < MAXN; i++) {
        if (exists[i]) {
            int root = find(i);
            families[root] = {min_id[root], people[root], 
                            (double)houses[root] / people[root],
                            area[root] / people[root]};
        }
    }
    
    vector<Family> result;
    for (auto& pair : families) {
        result.push_back(pair.second);
    }
    
    sort(result.begin(), result.end(), compare);
    
    cout << result.size() << endl;
    
    for (Family f : result) {
        printf("%04d %d %.3f %.3f\n", f.min_id, f.people, f.avg_house, f.avg_area);
    }
    
    return 0;
}