#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/**
 * L2-039 - 清点代码库
 * 
 * 实现原理：
 * 统计功能重复的代码模块。
 * 规则：
 * 1. 输出不同功能的个数
 * 2. 按模块个数非递增顺序输出
 * 3. 并列时按输出序列递增序输出
 * 
 * 解题思路：
 * 1. 使用map统计每个输出序列的出现次数
 * 2. 将结果存入vector并排序
 * 3. 按要求格式输出
 */
struct Func {
    int count;
    vector<int> outputs;
};

bool compare(const Func& a, const Func& b) {
    if (a.count != b.count) {
        return a.count > b.count;
    }
    return a.outputs < b.outputs;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    map<vector<int>, int> func_count;
    
    for (int i = 0; i < N; i++) {
        vector<int> outputs(M);
        for (int j = 0; j < M; j++) {
            cin >> outputs[j];
        }
        func_count[outputs]++;
    }
    
    vector<Func> result;
    for (auto& pair : func_count) {
        result.push_back({pair.second, pair.first});
    }
    
    sort(result.begin(), result.end(), compare);
    
    cout << result.size() << endl;
    for (const Func& f : result) {
        cout << f.count;
        for (int val : f.outputs) {
            cout << " " << val;
        }
        cout << endl;
    }
    
    return 0;
}