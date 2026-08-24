#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-015 球队"食物链"
 *
 * 题目描述：
 *   给定 N 支球队之间的胜负关系，要求找出一条"食物链"，即一个包含所有球队的序列，
 *   使得序列中每支球队都击败了下一支球队，最后一支球队击败了第一支球队（形成环）。
 *   输入格式：第一行给出整数 N。接下来 N 行，每行给出一个长度为 N 的字符串，
 *   第 i 行第 j 个字符为 'W' 表示球队 i 击败了球队 j，'L' 表示球队 i 输给了球队 j。
 *   输出格式：如果存在食物链，输出一个球队编号序列（以 1 开头）；否则输出 "No Solution"。
 *
 * 实现原理：
 *   使用记忆化搜索（动态规划）判断是否存在哈密顿回路，并构造路径。
 *   1. 使用 win[i] 存储球队 i 击败了哪些球队（位掩码）。
 *   2. 定义 memo[mask][last]：表示已选球队集合为 mask，当前最后一支球队为 last 时，
 *      是否能补全剩余球队并形成环。
 *   3. 递归终止条件：mask = (1<<n)-1（所有球队都已选择），且 last 击败了 0（第一支球队）。
 *   4. 状态转移：尝试选择下一支球队 v，如果 last 击败了 v，且 possible(mask|(1<<v), v) 为真。
 *   5. 路径构造：从球队 1 开始，贪心选择第一个可行的下一支球队。
 *
 * 时间复杂度：O(N^2 * 2^N)，记忆化搜索
 */
static int n, win[20]; static signed char *memo;
static int possible(int mask,int last){int idx=mask*n+last,v; signed char *m=&memo[idx];if(*m!=-1)return *m;if(mask==(1<<n)-1)return *m=((win[last]&1)!=0);for(v=1;v<n;++v)if(!(mask&(1<<v))&&(win[last]&(1<<v))&&possible(mask|(1<<v),v))return *m=1;return *m=0;}
int main(void){char s[25];int i,j,mask=1,last=0;scanf("%d",&n);for(i=0;i<n;++i){scanf("%s",s);for(j=0;j<n;++j)if(s[j]=='W')win[i]|=1<<j;}memo = (decltype(memo))malloc((size_t)(1<<n)*n);memset(memo,-1,(size_t)(1<<n)*n);if(!possible(1,0)){puts("No Solution");free(memo);return 0;}printf("1");while(mask!=(1<<n)-1){for(j=1;j<n;++j)if(!(mask&(1<<j))&&(win[last]&(1<<j))&&possible(mask|(1<<j),j)){printf(" %d",j+1);mask|=1<<j;last=j;break;}}putchar('\n');free(memo);return 0;}
