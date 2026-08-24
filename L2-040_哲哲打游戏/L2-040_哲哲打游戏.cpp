#include <iostream>
#include <vector>
using namespace std;

/**
 * L2-040 - 哲哲打游戏
 * 
 * 实现原理：
 * 模拟游戏操作流程。
 * 操作类型：
 * 0：做出选择，前往下一个剧情点
 * 1：存档到指定档位
 * 2：读取存档，回到存档点
 * 
 * 解题思路：
 * 1. 使用vector存储每个剧情点的选项
 * 2. 使用数组存储存档
 * 3. 按操作顺序模拟
 */
int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> choices(N + 1);
    
    for (int i = 1; i <= N; i++) {
        int K;
        cin >> K;
        choices[i].resize(K);
        for (int j = 0; j < K; j++) {
            cin >> choices[i][j];
        }
    }
    
    int current = 1;
    int save[101] = {0};
    
    for (int i = 0; i < M; i++) {
        int op, j;
        cin >> op >> j;
        
        if (op == 0) {
            current = choices[current][j - 1];
        } else if (op == 1) {
            save[j] = current;
            cout << current << endl;
        } else if (op == 2) {
            current = save[j];
        }
    }
    
    cout << current << endl;
    
    return 0;
}