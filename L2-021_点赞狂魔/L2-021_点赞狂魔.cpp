#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/**
 * L2-021 - 点赞狂魔
 * 
 * 实现原理：
 * 找出点赞标签最分散的前3名用户。
 * 规则：
 * 1. 不同标签数量最大者优先
 * 2. 如果并列，选择标签出现次数平均值最小的
 * 
 * 解题思路：
 * 1. 使用 unordered_set 统计每个人的不同标签数量
 * 2. 使用排序找出前3名
 * 3. 不足3人用-补齐
 */
struct User {
    string name;
    int unique_count;
    double avg_count;
};

bool compare(const User& a, const User& b) {
    if (a.unique_count != b.unique_count) {
        return a.unique_count > b.unique_count;
    }
    return a.avg_count < b.avg_count;
}

int main() {
    int N;
    cin >> N;
    
    vector<User> users(N);
    
    for (int i = 0; i < N; i++) {
        string name;
        int K;
        cin >> name >> K;
        
        unordered_set<int> tags;
        for (int j = 0; j < K; j++) {
            int tag;
            cin >> tag;
            tags.insert(tag);
        }
        
        users[i].name = name;
        users[i].unique_count = tags.size();
        users[i].avg_count = (double)K / tags.size();
    }
    
    sort(users.begin(), users.end(), compare);
    
    for (int i = 0; i < 3; i++) {
        if (i > 0) {
            cout << " ";
        }
        if (i < N) {
            cout << users[i].name;
        } else {
            cout << "-";
        }
    }
    cout << endl;
    
    return 0;
}