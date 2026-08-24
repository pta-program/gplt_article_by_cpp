#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-018 森森美图
 *
 * 题目描述：
 *   给定一个 N×M 的像素网格，每个像素有一个亮度值。
 *   要求找到从起点 (sx, sy) 到终点 (tx, ty) 的路径，路径必须穿过连接起点和终点的直线两侧，
 *   并且路径的总亮度最小。八方向移动，对角移动的代价为 sqrt(2) 倍的平均亮度。
 *   输入格式：第一行给出整数 N 和 M。接下来 N 行，每行给出 M 个整数表示像素亮度。
 *   最后一行给出起点和终点坐标。
 *   输出格式：输出最小总亮度，保留两位小数。
 *
 * 实现原理：
 *   使用 Dijkstra 算法分别在直线两侧计算最短路，然后合并结果。
 *   1. 将网格像素按直线分为两侧。
 *   2. 使用 Dijkstra 算法计算从起点到终点的路径，限制路径只能经过直线某一侧的像素。
 *   3. 分别计算两侧的最短路径，注意起点和终点被重复计算，需要减去一次。
 *   4. 八方向移动：水平/垂直移动代价为目标像素亮度；对角移动代价为 (sqrt(2)-1) * (当前+目标)/2。
 *
 * 时间复杂度：O(N * M * log(N * M))，Dijkstra 算法
 */
#define INF 1e100
static int n,m,val[105][105],sx,sy,tx,ty;
static double solve(int side){double d[105][105];int used[105][105]={0},i,j,k,dx[8]={1,-1,0,0,1,1,-1,-1},dy[8]={0,0,1,-1,1,-1,1,-1};for(i=0;i<n;++i)for(j=0;j<m;++j)d[i][j]=INF;d[sy][sx]=val[sy][sx];for(k=0;k<n*m;++k){int x=-1,y=-1;for(i=0;i<n;++i)for(j=0;j<m;++j)if(!used[i][j]&&d[i][j]<INF&&((x<0)||d[i][j]<d[y][x]))x=j,y=i;if(x<0)break;used[y][x]=1;for(i=0;i<8;++i){int X=x+dx[i],Y=y+dy[i];long long c;if(X<0||X>=m||Y<0||Y>=n)continue;c=(long long)(tx-sx)*(Y-sy)-(long long)(ty-sy)*(X-sx);if((X!=tx||Y!=ty)&&(X!=sx||Y!=sy)&&(c==0||(side*c<0)))continue;{double w=val[Y][X];if(dx[i]&&dy[i])w+=(sqrt(2.0)-1)*(val[y][x]+val[Y][X]);if(d[y][x]+w<d[Y][X])d[Y][X]=d[y][x]+w;}}}return d[ty][tx];}
int main(void){int i,j;scanf("%d%d",&n,&m);for(i=0;i<n;++i)for(j=0;j<m;++j)scanf("%d",&val[i][j]);scanf("%d%d%d%d",&sx,&sy,&tx,&ty);printf("%.2f\n",solve(1)+solve(-1)-val[sy][sx]-val[ty][tx]);return 0;}
