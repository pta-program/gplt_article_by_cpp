#include <iostream>
#include <cmath>
using namespace std;

/**
 * L1-028 - 判断素数
 * 修复点：原循环条件 i <= sqrt(n) 用浮点 sqrt，有精度误差且每次重复计算；
 * 改为 i*i <= n 整数运算，步进仅奇数，避免浮点误差并提升稳定性。
 */
bool isPrime(long long n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if (!(cin >> N)) return 0;
    for (int i = 0; i < N; ++i) {
        long long num; cin >> num;
        cout << (isPrime(num) ? "Yes" : "No") << '\n';
    }
    return 0;
}
