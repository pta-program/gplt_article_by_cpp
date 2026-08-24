#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-001 凑零钱
 *
 * 题目描述：
 *   给定 N 枚硬币，面值各不相同。要求从中选出一些硬币，使它们的面值之和恰好等于给定的金额。
 *   如果有多种方案，输出字典序最小的方案（即选择的硬币面值从小到大排列后字典序最小）。
 *   输入格式：第一行给出两个整数 N 和 target，分别表示硬币数量和目标金额。
 *   第二行给出 N 个整数，表示每种硬币的面值。
 *   输出格式：如果能凑出目标金额，按从小到大的顺序输出所选硬币的面值；否则输出 "No Solution"。
 *
 * 实现原理：
 *   使用动态规划（0/1背包问题）求解，同时保证字典序最小。
 *   1. 将硬币按面值从小到大排序。
 *   2. 使用二维数组 possible[i][sum] 表示前 i 枚硬币能否凑出金额 sum。
 *      采用后缀遍历（从后往前），避免重复计算。
 *   3. DP 转移：possible[i][sum] = possible[i+1][sum] || possible[i+1][sum-coin[i]]
 *      即第 i 枚硬币可选或不选。
 *   4. 路径重建：从第一枚硬币开始，优先选择小面额硬币（因为已排序），
 *      如果 possible[i+1][sum-coin[i]] 为真，则选择该硬币。
 *
 * 时间复杂度：O(N * target)
 */
static int cmp(const void *a, const void *b) { return *(const int *)a - *(const int *)b; }
int main(void) {
    int n, target, coin[10001], i, sum, first = 1; unsigned char *possible;
    if (scanf("%d%d", &n, &target) != 2) return 0;
    // 读取 N 枚硬币面值并升序排序：面值从小到大便于后续构造字典序最小的方案
    for (i = 1; i <= n; ++i) scanf("%d", &coin[i]); qsort(coin + 1, n, sizeof(int), cmp);
    // possible[i][sum]=1 表示用第 i~n 枚硬币恰好能凑出金额 sum；边界置 possible[n+1][0]=1（不用任何硬币凑出 0）
    possible = (decltype(possible))calloc((size_t)(n + 2) * (target + 1), 1); possible[(n + 1) * (target + 1)] = 1;
    // 0/1 背包递推（自后向前）：不选第 i 枚硬币，或者（sum>=coin[i] 时）选第 i 枚硬币
    for (i = n; i >= 1; --i) for (sum = 0; sum <= target; ++sum) possible[i * (target + 1) + sum] = possible[(i + 1) * (target + 1) + sum] || (sum >= coin[i] && possible[(i + 1) * (target + 1) + sum - coin[i]]);
    // 第 1 枚硬币起凑不出 target，说明无任何方案可行
    if (!possible[1 * (target + 1) + target]) { puts("No Solution"); free(possible); return 0; }
    // 贪心重建路径：按升序从前往后扫描，能选当前硬币（选后剩余金额仍可解）就选，从而保证字典序最小
    for (i = 1, sum = target; i <= n && sum; ++i) if (sum >= coin[i] && possible[(i + 1) * (target + 1) + sum - coin[i]]) { printf("%s%d", first ? "" : " ", coin[i]); first = 0; sum -= coin[i]; }
    putchar('\n'); free(possible); return 0;
}
