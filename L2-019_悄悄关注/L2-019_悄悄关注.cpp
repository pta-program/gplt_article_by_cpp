#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * L2-019 - 悄悄关注
 * 
 * 实现原理：
 * 找出可能被悄悄关注的人。
 * 条件：
 * 1. 点赞次数大于平均数
 * 2. 不在关注列表上
 * 
 * 解题思路：
 * 1. 读取关注列表
 * 2. 读取点赞信息，计算平均数
 * 3. 找出符合条件的用户
 * 4. 按字母序排序输出
 */
int main() {
    int N;
    cin >> N;
    
    unordered_set<string> follows;
    for (int i = 0; i < N; i++) {
        string user;
        cin >> user;
        follows.insert(user);
    }
    
    int M;
    cin >> M;
    
    unordered_map<string, int> likes;
    int total_likes = 0;
    
    for (int i = 0; i < M; i++) {
        string user;
        int count;
        cin >> user >> count;
        likes[user] = count;
        total_likes += count;
    }
    
    double avg = (double)total_likes / M;
    
    vector<string> candidates;
    for (auto& pair : likes) {
        if (pair.second > avg && !follows.count(pair.first)) {
            candidates.push_back(pair.first);
        }
    }
    
    if (candidates.empty()) {
        cout << "Bing Mei You" << endl;
    } else {
        sort(candidates.begin(), candidates.end());
        for (string user : candidates) {
            cout << user << endl;
        }
    }
    
    return 0;
}