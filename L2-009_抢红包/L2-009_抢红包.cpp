#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

/**
 * L2-009 - 抢红包
 * 
 * 实现原理：
 * 统计每个人抢红包的收入。
 * 
 * 解题思路：
 * 1. 使用数组记录每个人的收入和抢到红包的个数
 * 2. 处理每个人发红包的记录
 * 3. 按规则排序并输出
 */
struct Person {
    int id;
    int money;
    int count;
};

bool compare(Person a, Person b) {
    if (a.money != b.money) {
        return a.money > b.money;
    }
    if (a.count != b.count) {
        return a.count > b.count;
    }
    return a.id < b.id;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> money(N + 1, 0);
    vector<int> count(N + 1, 0);
    
    for (int i = 1; i <= N; i++) {
        int K;
        cin >> K;
        
        int total_pay = 0;
        for (int j = 0; j < K; j++) {
            int receiver, amount;
            cin >> receiver >> amount;
            
            money[receiver] += amount;
            count[receiver]++;
            total_pay += amount;
        }
        
        money[i] -= total_pay;
    }
    
    vector<Person> people;
    for (int i = 1; i <= N; i++) {
        people.push_back({i, money[i], count[i]});
    }
    
    sort(people.begin(), people.end(), compare);
    
    for (Person p : people) {
        double yuan = p.money / 100.0;
        cout << p.id << " " << fixed << setprecision(2) << yuan << endl;
    }
    
    return 0;
}