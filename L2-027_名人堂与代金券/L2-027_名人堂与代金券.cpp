#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/**
 * L2-027 - 名人堂与代金券
 * 
 * 实现原理：
 * 统计代金券总面值并列出名人堂成员。
 * 规则：
 * 1. 成绩>=60分可获得代金券
 * 2. [G, 100]区间：50元
 * 3. [60, G)区间：20元
 * 4. 名人堂取前K名，成绩相同并列排名
 * 5. 排名并列时按账号字母序升序
 * 
 * 解题思路：
 * 1. 计算代金券总额
 * 2. 按成绩降序、账号升序排序
 * 3. 处理并列排名
 */
struct Student {
    string id;
    int score;
};

bool compare(const Student& a, const Student& b) {
    if (a.score != b.score) {
        return a.score > b.score;
    }
    return a.id < b.id;
}

int main() {
    int N, G, K;
    cin >> N >> G >> K;
    
    vector<Student> students(N);
    int total_coupon = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> students[i].id >> students[i].score;
        
        int score = students[i].score;
        if (score >= G) {
            total_coupon += 50;
        } else if (score >= 60) {
            total_coupon += 20;
        }
    }
    
    sort(students.begin(), students.end(), compare);
    
    cout << total_coupon << endl;
    
    int rank = 1;
    for (int i = 0; i < N && rank <= K; i++) {
        if (i > 0 && students[i].score != students[i-1].score) {
            rank = i + 1;
        }
        
        if (rank <= K) {
            cout << rank << " " << students[i].id << " " << students[i].score << endl;
        }
    }
    
    return 0;
}