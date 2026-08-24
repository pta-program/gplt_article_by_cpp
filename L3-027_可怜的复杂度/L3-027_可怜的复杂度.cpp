#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-027 可怜的复杂度
 *
 * 题目描述：
 *   给定一个长度为 N 的数组，每个元素取值范围为 [1, m]。
 *   对数组进行随机变换，变换规则是：对于每个元素 x，如果变换后的值与其他元素相同，
 *   则概率为 1/m；否则保持不同。要求计算变换后所有区间的哈希值不相等的概率。
 *   输入格式：第一行给出测试用例数 T。对于每个测试用例，
 *   第一行给出 N 和 m，第二行给出 N 个整数表示数组元素。
 *   输出格式：对于每个测试用例，输出概率乘以 m^N 后的结果（模 998244353）。
 *
 * 实现原理：
 *   使用概率累加计算所有区间的去重概率。
 *   1. 对于每个区间 [l, r]，计算该区间内所有元素变换后互不相同的概率。
 *   2. 概率计算：对于区间内每个元素对 (a, b)，如果原数组中 x[a] == x[b]，
 *      则变换后相等的概率为 1/m，不相等的概率为 (m-1)/m。
 *   3. 将所有区间的概率累加，再乘以 m^N（将概率转换为整数形式）。
 *   4. 使用快速幂计算 m^N 和 1/m 的模逆元。
 *
 * 时间复杂度：O(T * N^3)，枚举所有区间和元素对
 */
#define MOD 998244353LL
static long long pw(long long a,long long b){long long r=1;while(b){if(b&1)r=r*a%MOD;a=a*a%MOD;b>>=1;}return r;}
int main(void){int T;scanf("%d",&T);while(T--){int n,i,l,r;long long m,ans=0,x[105],inv;scanf("%d%lld",&n,&m);for(i=0;i<n;++i)scanf("%lld",&x[i]);inv=pw(m,MOD-2);for(l=0;l<n;++l)for(r=l;r<n;++r){long long ways=1;int a,b;/* 用区间哈希的出现概率近似表示其贡献，逐一处理相等块。 */for(a=l;a<=r;++a)for(b=l;b<a;++b)if(x[a]==x[b])ways=ways*inv%MOD;ans=(ans+ways*pw(m,n))%MOD;}printf("%lld\n",ans);}return 0;}
