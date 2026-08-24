#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;

/**
 * L2-046 - 天梯赛的赛场安排
 * 
 * 实现原理：
 * 按照多轮次排座算法安排赛场。
 * 规则：
 * 1. 每轮处理人数最多的学校
 * 2. n>=C：新开赛场，安排C人
 * 3. n<C：找剩余空位>=n的编号最小赛场
 * 4. n<C且无合适赛场：新开赛场
 * 
 * 解题思路：
 * 1. 使用优先队列按人数排序
 * 2. 维护赛场列表和剩余空位
 * 3. 记录每个学校的监考人数
 */
struct School {
    string name;
    int count;
    int index;
    
    bool operator<(const School& other) const {
        if (count != other.count) {
            return count < other.count;
        }
        return index > other.index;
    }
};

int main() {
    int N, C;
    cin >> N >> C;
    
    vector<string> names(N);
    vector<int> counts(N);
    vector<int> proctors(N, 0);
    
    priority_queue<School> pq;
    
    for (int i = 0; i < N; i++) {
        cin >> names[i] >> counts[i];
        pq.push({names[i], counts[i], i});
    }
    
    vector<int> rooms;
    
    while (!pq.empty()) {
        School s = pq.top();
        pq.pop();
        
        int n = s.count;
        int idx = s.index;
        
        if (n >= C) {
            proctors[idx]++;
            rooms.push_back(C);
            n -= C;
            
            if (n > 0) {
                pq.push({names[idx], n, idx});
            }
        } else {
            bool placed = false;
            
            for (int i = 0; i < rooms.size(); i++) {
                int remaining = C - rooms[i];
                
                if (remaining >= n) {
                    rooms[i] += n;
                    proctors[idx]++;
                    placed = true;
                    break;
                }
            }
            
            if (!placed) {
                rooms.push_back(n);
                proctors[idx]++;
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        cout << names[i] << " " << proctors[i] << endl;
    }
    
    cout << rooms.size() << endl;
    
    return 0;
}