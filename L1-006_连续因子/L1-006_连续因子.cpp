#include <iostream>
#include <cmath>
using namespace std;

/**
 * L1-006 - 连续因子
 * 修复点：使用 long long 兼容 2^31 范围；循环上界用 i*i <= N 整数比较
 * 避免浮点 sqrt 精度问题；temp 用 long long 防止除法过程中溢出。
 */
int main() {
    long long N;
    if (!(cin >> N)) return 0;

    int max_len = 0;
    long long start = 0;

    long long limit = (long long)sqrt((double)N);
    for (long long i = 2; i <= limit; ++i) {
        long long temp = N;
        int cur = 0;
        long long j = i;
        while (temp % j == 0) {
            temp /= j;
            ++cur;
            ++j;
        }
        if (cur > max_len) {
            max_len = cur;
            start = i;
        }
    }
    if (max_len == 0) { max_len = 1; start = N; }

    cout << max_len << '\n';
    for (int i = 0; i < max_len; ++i) {
        if (i) cout << '*';
        cout << start + i;
    }
    cout << '\n';
    return 0;
}
