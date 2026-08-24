#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

/**
 * L2-018 - 多项式A除以B
 * 
 * 实现原理：
 * 多项式除法。
 * 使用数组表示多项式，下标表示指数，值表示系数。
 * 
 * 解题思路：
 * 1. 将多项式转换为数组形式
 * 2. 执行多项式除法
 * 3. 输出商和余数
 */
int main() {
    int n;
    
    cin >> n;
    vector<double> A(10010, 0);
    int max_exp_a = 0;
    for (int i = 0; i < n; i++) {
        int e;
        double c;
        cin >> e >> c;
        A[e] = c;
        if (e > max_exp_a) {
            max_exp_a = e;
        }
    }
    
    cin >> n;
    vector<double> B(10010, 0);
    int max_exp_b = 0;
    for (int i = 0; i < n; i++) {
        int e;
        double c;
        cin >> e >> c;
        B[e] = c;
        if (e > max_exp_b) {
            max_exp_b = e;
        }
    }
    
    vector<double> Q(10010, 0);
    vector<double> R = A;
    
    int exp_q = max_exp_a - max_exp_b;
    while (exp_q >= 0) {
        double coeff = R[max_exp_a] / B[max_exp_b];
        
        if (abs(coeff) < 0.05) {
            break;
        }
        
        Q[exp_q] = coeff;
        
        for (int i = 0; i <= max_exp_b; i++) {
            R[exp_q + i] -= coeff * B[i];
        }
        
        // 更新max_exp_a
        while (max_exp_a >= 0 && abs(R[max_exp_a]) < 0.05) {
            R[max_exp_a] = 0;
            max_exp_a--;
        }
        
        exp_q = max_exp_a - max_exp_b;
    }
    
    // 输出商
    vector<pair<int, double>> q_result;
    for (int i = 10009; i >= 0; i--) {
        if (abs(Q[i]) >= 0.05) {
            q_result.push_back({i, Q[i]});
        }
    }
    
    if (q_result.empty()) {
        cout << "0 0 0.0" << endl;
    } else {
        cout << q_result.size();
        for (auto& p : q_result) {
            cout << " " << p.first << " " << fixed << setprecision(1) << p.second;
        }
        cout << endl;
    }
    
    // 输出余数
    vector<pair<int, double>> r_result;
    for (int i = 10009; i >= 0; i--) {
        if (abs(R[i]) >= 0.05) {
            r_result.push_back({i, R[i]});
        }
    }
    
    if (r_result.empty()) {
        cout << "0 0 0.0" << endl;
    } else {
        cout << r_result.size();
        for (auto& p : r_result) {
            cout << " " << p.first << " " << fixed << setprecision(1) << p.second;
        }
        cout << endl;
    }
    
    return 0;
}