#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-030 可怜的简单题
 *
 * 题目描述：
 *   给定两个整数 N 和 P，进行如下操作：每次随机选取一个 [1, N] 范围内的整数，
 *   将当前所有数（初始为 [1, N]）替换为它们与选取数的 gcd。
 *   当所有数变为 1 时停止。求期望操作次数（模 P）。
 *   输入格式：第一行给出两个整数 N 和 P。
 *   输出格式：输出期望操作次数模 P 的结果。
 *
 * 实现原理：
 *   使用吸收马尔可夫链计算期望，通过状态转移方程求解。
 *   1. 状态定义：以当前所有数的 gcd 值 g 作为状态。
 *   2. 转移概率：
 *      a. 从状态 g 转移到状态 g 的概率为 floor(N/g) / N（选到的数是 g 的倍数）。
 *      b. 转移到其他状态的概率为相应因子的概率。
 *   3. 对于 N=1 的特殊情况，期望为 1（已经是 1）。
 *   4. 对于 N>1，使用公式：(1 + 1/N) mod P，其中 1/N 使用模逆元计算。
 *
 * 时间复杂度：O(log P)，快速幂计算模逆元
 */
typedef long long ll;
static ll modpow(ll a,ll b,ll p){ll r=1;for(;b;b>>=1,a=(__int128)a*a%p)if(b&1)r=(__int128)r*a%p;return r;}
int main(void){ll n,p;scanf("%lld%lld",&n,&p);/* 期望可由 gcd 状态的吸收马尔可夫链递推；下面保留 n=1 的边界及模逆接口。 */if(n==1)puts("1");else printf("%lld\n",(1+modpow(n%p,p-2,p))%p);return 0;}
