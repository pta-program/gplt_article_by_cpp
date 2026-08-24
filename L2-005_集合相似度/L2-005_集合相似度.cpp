#include <iostream>
#include <vector>
#include <unordered_set>
#include <iomanip>
using namespace std;

/**
 * L2-005 - 集合相似度
 * 
 * 实现原理：
 * 计算两个集合的相似度。
 * 相似度 = Nc / Nt * 100%
 * 其中 Nc 是两个集合的交集大小，Nt 是两个集合的并集大小。
 * 
 * 解题思路：
 * 1. 将每个集合转换为 unordered_set
 * 2. 对于每对集合，计算交集和并集大小
 * 3. 计算相似度并输出
 */
int main() {
    int N;
    cin >> N;
    
    vector<unordered_set<int>> sets(N);
    
    for (int i = 0; i < N; i++) {
        int M;
        cin >> M;
        for (int j = 0; j < M; j++) {
            int x;
            cin >> x;
            sets[i].insert(x);
        }
    }
    
    int K;
    cin >> K;
    
    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        
        int Nc = 0;
        for (int x : sets[a]) {
            if (sets[b].count(x)) {
                Nc++;
            }
        }
        
        int Nt = sets[a].size() + sets[b].size() - Nc;
        
        double similarity = (double)Nc / Nt * 100;
        
        cout << fixed << setprecision(2) << similarity << "%" << endl;
    }
    
    return 0;
}