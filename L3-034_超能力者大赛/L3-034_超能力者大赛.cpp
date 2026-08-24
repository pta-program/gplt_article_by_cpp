#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-034 超能力者大赛
 *
 * 题目描述：
 *   在一个城市网络中，有 N 个超能力者，每个超能力者在某个城市，有一定的能力值。
 *   你从第一个超能力者开始，能力值为该超能力者的能力值。
 *   每天你可以：
 *   1. 移动到相邻城市（花费时间等于道路长度）。
 *   2. 击败当前城市中能力值不超过你的超能力者（获得其能力值）。
 *   要求在 D 天内尽可能击败更多超能力者。
 *   输入格式：第一行给出四个整数 N、M、E、D，分别表示超能力者数、城市数、道路数、天数。
 *   接下来 N 行，每行给出城市编号和能力值。
 *   接下来 E 行，每行给出一条道路的信息。
 *   输出格式：输出每天的行动日志，以及最终结果。
 *
 * 实现原理：
 *   使用 Floyd-Warshall 计算最短路径，然后贪心选择对手。
 *   1. 使用 Floyd-Warshall 算法计算所有城市对之间的最短时间。
 *   2. 贪心策略：每次选择当前可击败的能力值最大的对手。
 *      a. 如果有多个能力值相同的对手，选择距离最近的。
 *   3. 输出移动和击败的行动日志。
 *   4. 如果在 D 天内击败所有对手，输出 WIN；否则输出最终状态。
 *
 * 时间复杂度：O(M^3 + N^2 * D)，Floyd-Warshall 为 O(M^3)
 */
#define INF 1000000000
int main(void){int N,M,E,D,i,j,k,city[100005],power[100005],dead[100005]={0},dis[205][205],pos,day=1,me;scanf("%d%d%d%d",&N,&M,&E,&D);for(i=0;i<N;++i)scanf("%d%d",&city[i],&power[i]);for(i=0;i<M;++i)for(j=0;j<M;++j)dis[i][j]=i==j?0:INF;while(E--){int a,b,w;scanf("%d%d%d",&a,&b,&w);if(w<dis[a][b])dis[a][b]=dis[b][a]=w;}for(k=0;k<M;++k)for(i=0;i<M;++i)for(j=0;j<M;++j)if(dis[i][k]+dis[k][j]<dis[i][j])dis[i][j]=dis[i][k]+dis[k][j];pos=city[0];me=power[0];dead[0]=1;while(day<=D){int t=-1;for(i=1;i<N;++i)if(!dead[i]&&power[i]<=me&&(t<0||power[i]>power[t]||(power[i]==power[t]&&dis[pos][city[i]]<dis[pos][city[t]])))t=i;if(t<0){printf("Lose on day %d with %d.\n",day,me);return 0;}if(pos!=city[t]){printf("Move from %d to %d.\n",pos,city[t]);day+=dis[pos][city[t]];pos=city[t];if(day>D)break;}printf("Get %d at %d on day %d.\n",power[t],pos,day);me+=power[t];dead[t]=1;if(++day>D)break;for(i=1,j=0;i<N;++i)j+=!dead[i];if(!j){printf("WIN on day %d with %d!\n",day-1,me);return 0;}}printf("Game over with %d.\n",me);return 0;}
