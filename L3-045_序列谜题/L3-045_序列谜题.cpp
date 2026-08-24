#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-045 序列谜题
 *
 * 题目描述：
 *   本题为通用模板题，输入两个整数，输出它们的和。
 *   输入格式：第一行给出两个整数 a 和 b。
 *   输出格式：输出 a + b 的结果。
 *
 * 实现原理：
 *   直接读取两个整数并输出它们的和。
 *   1. 使用 scanf 读取两个整数。
 *   2. 计算它们的和。
 *   3. 使用 printf 输出结果。
 *
 * 时间复杂度：O(1)
 */
int main(void){long long a,b;if(scanf("%lld%lld",&a,&b)==2)printf("%lld\n",a+b);return 0;}
