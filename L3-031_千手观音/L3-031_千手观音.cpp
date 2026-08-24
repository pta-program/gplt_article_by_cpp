#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-031 千手观音
 *
 * 题目描述：
 *   给定 N 个数字字符串（由点号分隔的三位数字组成），要求推断数字字符串之间的排序规则。
 *   如果相邻两个字符串在某一位数字不同，则该位数字较小的字符串排在前面。
 *   要求输出所有不同数字的字典序最小拓扑排序。
 *   输入格式：第一行给出整数 N。接下来 N 行，每行给出一个数字字符串。
 *   输出格式：输出所有不同数字的排序结果，用点号分隔。
 *
 * 实现原理：
 *   使用拓扑排序推断数字之间的大小关系。
 *   1. 对于相邻的两个字符串，逐位比较，找到第一个不同的数字位。
 *   2. 添加一条有向边：较小的数字 -> 较大的数字。
 *   3. 使用字典序最小的拓扑排序算法：
 *      a. 每次选择入度为 0 且字典序最小的节点。
 *      b. 将该节点加入结果，并减少其邻接节点的入度。
 *   4. 使用位掩码优化边的存储和查询。
 *
 * 时间复杂度：O(N * L + K^2)，其中 L 是字符串长度，K 是不同数字的数量
 */
static char word[10005][4];static int cnt,edge[10005][10005/8+1],ind[10005],used[10005];
static int id(char*s){int i;for(i=0;i<cnt;++i)if(!strcmp(word[i],s))return i;strcpy(word[cnt],s);return cnt++;}
static int has(int a,int b){return edge[a][b>>3]&(1<<(b&7));}static void add(int a,int b){if(!has(a,b))edge[a][b>>3]|=1<<(b&7),ind[b]++;}
int main(void){int n,i;char prev[50]="",cur[50];scanf("%d",&n);while(n--){char *p,*q;scanf("%s",cur);if(prev[0]){p=prev;q=cur;while(*p&&*q){char a[4]={0},b[4]={0};sscanf(p,"%3[^.]",a);sscanf(q,"%3[^.]",b);if(strcmp(a,b)){add(id(a),id(b));break;}p=strchr(p,'.');q=strchr(q,'.');if(!p||!q)break;++p;++q;}}for(p=cur;*p;){char a[4]={0};sscanf(p,"%3[^.]",a);id(a);p=strchr(p,'.');if(!p)break;++p;}strcpy(prev,cur);}for(i=0;i<cnt;++i){int j,best=-1;for(j=0;j<cnt;++j)if(!used[j]&&!ind[j]&&(best<0||strcmp(word[j],word[best])<0))best=j;used[best]=1;printf("%s%s",i?".":"",word[best]);for(j=0;j<cnt;++j)if(has(best,j))--ind[j];}putchar('\n');return 0;}
