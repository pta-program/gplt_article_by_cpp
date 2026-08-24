#include <iostream>
#include <cstdlib>
using namespace std;

/**
 * L1-009 - N个数求和
 * 修复点：gcd 处理负数时返回负值导致约分异常；改为对绝对值求 gcd。
 * 同时 abs 对 long long 使用 llabs，避免重载歧义；分母保持正数。
 */
long long llgcd(long long a, long long b) {
    a = llabs(a); b = llabs(b);
    while (b != 0) {
        long long t = a % b;
        a = b; b = t;
    }
    return a;
}
long long lllcm(long long a, long long b) {
    return a / llgcd(a, b) * b; // 先除后乘防溢出
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    long long total_num = 0, total_den = 1;

    for (int i = 0; i < N; ++i) {
        long long num, den; char slash;
        cin >> num >> slash >> den;
        long long common_den = lllcm(total_den, den);
        total_num = total_num * (common_den / total_den) + num * (common_den / den);
        total_den = common_den;
        long long g = llgcd(total_num, total_den);
        if (g != 0) { total_num /= g; total_den /= g; }
        if (total_den < 0) { total_num = -total_num; total_den = -total_den; }
    }

    long long integer_part = total_num / total_den;
    long long fraction_num = total_num % total_den;

    if (integer_part != 0 && fraction_num != 0) {
        cout << integer_part << ' ' << llabs(fraction_num) << '/' << total_den << '\n';
    } else if (integer_part != 0) {
        cout << integer_part << '\n';
    } else {
        // 结果为 0 时按题意输出 0/1？但保证分子分母已约分，fraction_num==0 且 integer==0 对应 0
        // 此时 fraction_num==0, total_den已约分；输出 0/1 更符合最简形式，但题面保证至少有一个分数，
        // 若和为0会走此分支输出 0/1；若和为纯分数直接输出分数
        if (fraction_num == 0) cout << integer_part << '\n'; // 0
        else cout << fraction_num << '/' << total_den << '\n';
        // 上面已覆盖 integer==0 且 fraction!=0 的情况，下行保留原逻辑兼容
        // 实际上当 integer==0 时 fraction_num 就是分子（绝对值<分母）
        // 为确保输出如 7/24 而非 0，需单独处理
        // 重算：若 integer==0 且 fraction!=0，直接输出分数
        // （上一步已在 else 分支，先修正）
    }
    return 0;
}
