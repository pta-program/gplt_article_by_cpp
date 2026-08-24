#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

/**
 * L2-015 - 互评成绩
 * 
 * 实现原理：
 * 计算每个学生的互评成绩，去掉一个最高分和一个最低分，取平均分。
 * 然后输出最高分的M个成绩。
 * 
 * 解题思路：
 * 1. 读取每个学生的k个评审成绩
 * 2. 去掉最高分和最低分，计算平均分
 * 3. 将所有学生的成绩排序
 * 4. 输出最高的M个成绩
 */
int main() {
    int N, k, M;
    cin >> N >> k >> M;
    
    vector<double> scores;
    
    for (int i = 0; i < N; i++) {
        vector<int> marks(k);
        for (int j = 0; j < k; j++) {
            cin >> marks[j];
        }
        
        sort(marks.begin(), marks.end());
        
        int sum = 0;
        for (int j = 1; j < k - 1; j++) {
            sum += marks[j];
        }
        
        double avg = (double)sum / (k - 2);
        scores.push_back(avg);
    }
    
    sort(scores.begin(), scores.end());
    
    bool first = true;
    for (int i = scores.size() - M; i < scores.size(); i++) {
        if (first) {
            first = false;
        } else {
            cout << " ";
        }
        cout << fixed << setprecision(3) << scores[i];
    }
    cout << endl;
    
    return 0;
}