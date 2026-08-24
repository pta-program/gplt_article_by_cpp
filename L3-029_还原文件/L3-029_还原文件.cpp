#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-029 还原文件
 *
 * 题目描述：
 *   一张文件被撕成了 M 条碎纸条，每条碎纸条上的内容是原文件断口折线的连续片段。
 *   给定原文件的断口折线数组 base[]，以及每条碎纸条的内容数组，要求还原碎纸条的原始顺序。
 *   输入格式：第一行给出整数 N，表示原文件断口折线的长度。第二行给出 N 个整数表示断口折线。
 *   第三行给出整数 M，表示碎纸条数量。接下来 M 行，每行先给出整数 K，然后给出 K 个整数表示碎纸条内容。
 *   输出格式：输出碎纸条的原始顺序（编号按输入顺序）。
 *
 * 实现原理：
 *   使用 KMP 算法在原数组中查找每个碎纸条的唯一出现位置。
 *   1. 对每个碎纸条的内容数组构建 KMP 的失败函数（部分匹配表）。
 *   2. 使用 KMP 算法在原数组 base[] 中查找该碎纸条的起始位置。
 *   3. 记录每个碎纸条的起始位置 pos。
 *   4. 按起始位置从小到大排序碎纸条。
 *   5. 输出排序后的碎纸条编号。
 *
 * 时间复杂度：O(N * M + sum(K))，KMP 匹配为 O(N + K)
 */
typedef struct {int id,pos;} Strip;
static int cmp(const void*a,const void*b){return ((Strip*)a)->pos-((Strip*)b)->pos;}
int main(void){int n,m,i,j;int *base;Strip s[105];scanf("%d",&n);base = (decltype(base))malloc((size_t)n*sizeof(int));for(i=0;i<n;++i)scanf("%d",&base[i]);scanf("%d",&m);for(i=0;i<m;++i){int k,*p,*fail,match=0;scanf("%d",&k);p = (decltype(p))malloc((size_t)k*sizeof(int));fail = (decltype(fail))malloc((size_t)k*sizeof(int));for(j=0;j<k;++j)scanf("%d",&p[j]);fail[0]=-1;for(j=1;j<k;++j){int t=fail[j-1];while(t>=0&&p[t+1]!=p[j])t=fail[t];if(p[t+1]==p[j])++t;fail[j]=t;}for(j=0;j<n;++j){while(match>0&&p[match]!=base[j])match=fail[match-1]+1;if(p[match]==base[j])++match;if(match==k){s[i]=(Strip){i+1,j-k+1};break;}}free(p);free(fail);}qsort(s,m,sizeof(Strip),cmp);for(i=0;i<m;++i)printf("%s%d",i?" ":"",s[i].id);putchar('\n');free(base);return 0;}
