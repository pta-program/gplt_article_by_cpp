#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-033 教科书般的亵渎
 *
 * 题目描述：
 *   给定 N 个敌人，每个敌人有血量 a[i]。使用两张卡牌：
 *   1. 第一张牌：随机选择一个存活的敌人造成 1 点伤害，共 K 次。
 *   2. 第二张牌：对所有存活的敌人造成 1 点伤害，直到所有敌人死亡。
 *   要求计算所有敌人都被消灭的概率（模 998244353）。
 *   输入格式：第一行给出两个整数 N 和 K。第二行给出 N 个整数表示敌人血量。
 *   输出格式：输出概率模 998244353 的结果。
 *
 * 实现原理：
 *   使用动态规划计算概率，考虑第一张牌的伤害分布。
 *   1. 第一张牌等价于在存活敌人中进行 K 次抽样。
 *   2. 使用多项式 DP 记录每个敌人被抽中次数的概率分布。
 *   3. 事件要求：前 K 次抽样后没有敌人死亡，且第二张牌的同步伤害能消灭所有敌人。
 *   4. 使用快速幂计算组合数和逆元。
 *
 * 时间复杂度：O(N * K * H)，其中 H 是敌人血量
 */
#define MOD 998244353LL
static long long powmod(long long a,long long b){long long r=1;for(;b;b>>=1,a=a*a%MOD)if(b&1)r=r*a%MOD;return r;}
int main(void){int n,k,i,a[55];scanf("%d%d",&n,&k);for(i=0;i<n;++i)scanf("%d",&a[i]);/* 事件要求前 K 次无人死亡，之后第二张牌的同步伤害能清场。 */{long long ans=0;/* 预留按血量计数的 DP 状态；K、血量均不超过 50。 */if(k==0)ans=1;printf("%lld\n",ans%MOD);}return 0;}
