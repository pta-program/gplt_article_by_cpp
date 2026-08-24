#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-020 至多删三个字符
 *
 * 题目描述：
 *   给定一个字符串，要求计算通过删除至多三个字符后可以得到的不同字符串的数量。
 *   输入格式：输入一行字符串。
 *   输出格式：输出不同字符串的数量。
 *
 * 实现原理：
 *   使用动态规划计算删除 k 个字符后的不同字符串数量，同时处理重复计数。
 *   1. 定义 f[k]：表示前 i 个字符中删除 k 个字符得到的不同字符串数量。
 *   2. 递推关系：f[k] = f[k]（不删当前字符）+ f[k-1]（删除当前字符）。
 *   3. 去重处理：当遇到相同字符时，需要减去重复计算的部分。
 *      记录每个字符最后一次出现的位置 last[c]。
 *      如果上次出现位置 r 距离当前位置 <= k，则需要减去 hist[r-1][k-(i-r)]。
 *   4. 使用滚动数组优化空间，hist[i%5][] 存储历史状态。
 *
 * 时间复杂度：O(N)，其中 N 是字符串长度
 */
int main(void){static char s[1000005];unsigned long long hist[5][4]={{1,0,0,0}},f[4]={1,0,0,0},nf[4];int last[26],i,k,n;memset(last,-1,sizeof(last));scanf("%s",s);n=strlen(s);for(i=1;i<=n;++i){int r=last[s[i-1]-'a'];for(k=0;k<4;++k){unsigned long long dup=0;nf[k]=f[k]+(k?f[k-1]:0);if(r>=0&&i-r<=k){int q=r-i+k;dup=hist[(r-1)%5][q];}nf[k]-=dup;}memcpy(f,nf,sizeof(f));memcpy(hist[i%5],f,sizeof(f));last[s[i-1]-'a']=i;}printf("%llu\n",f[0]+f[1]+f[2]+f[3]);return 0;}
