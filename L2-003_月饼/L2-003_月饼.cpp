#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

/**
 * L2-003 - 月饼
 * 
 * 实现原理：
 * 贪心算法，优先选择单价最高的月饼。
 * 
 * 解题思路：
 * 1. 计算每种月饼的单价
 * 2. 按单价从高到低排序
 * 3. 依次选择单价最高的月饼，直到满足需求量
 * 4. 计算总收益
 */
struct Mooncake {
    double stock;
    double price;
    double unit_price;
};

bool compare(Mooncake a, Mooncake b) {
    return a.unit_price > b.unit_price;
}

int main() {
    int N;
    double D;
    cin >> N >> D;
    
    vector<Mooncake> mooncakes(N);
    for (int i = 0; i < N; i++) {
        cin >> mooncakes[i].stock;
    }
    for (int i = 0; i < N; i++) {
        cin >> mooncakes[i].price;
        mooncakes[i].unit_price = mooncakes[i].price / mooncakes[i].stock;
    }
    
    sort(mooncakes.begin(), mooncakes.end(), compare);
    
    double total_profit = 0;
    double remaining = D;
    
    for (Mooncake m : mooncakes) {
        if (remaining <= 0) {
            break;
        }
        
        if (m.stock <= remaining) {
            total_profit += m.price;
            remaining -= m.stock;
        } else {
            total_profit += m.unit_price * remaining;
            remaining = 0;
        }
    }
    
    cout << fixed << setprecision(2) << total_profit << endl;
    
    return 0;
}