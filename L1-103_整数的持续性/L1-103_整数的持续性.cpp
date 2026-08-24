#include <iostream>
#include <vector>
using namespace std;

/**
 * L1-103 - 整数的持续性
 * 
 * 实现原理：
 * 整数的持续性定义为：从整数n出发，将每一位数字相乘得到n1，再将n1的每一位相乘得到n2，
 * 直到得到个位数，所需的步数就是持续性。
 * 
 * 解题思路：
 * 1. 遍历区间[a, b]内的所有整数
 * 2. 对每个整数计算其持续性
 * 3. 记录最大持续性和对应的整数
 * 4. 输出结果
 */
int persistence(long long n) {
    if (n < 10) {
        return 0;
    }
    
    int steps = 0;
    while (n >= 10) {
        long long product = 1;
        while (n > 0) {
            product *= (n % 10);
            n /= 10;
        }
        n = product;
        steps++;
    }
    
    return steps;
}

int main() {
    long long a, b;
    cin >> a >> b;
    
    int max_persistence = 0;
    vector<long long> result;
    
    for (long long i = a; i <= b; i++) {
        int p = persistence(i);
        
        if (p > max_persistence) {
            max_persistence = p;
            result.clear();
            result.push_back(i);
        } else if (p == max_persistence) {
            result.push_back(i);
        }
    }
    
    cout << max_persistence << endl;
    
    for (size_t i = 0; i < result.size(); i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << result[i];
    }
    cout << endl;
    
    return 0;
}