#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-023 计算图
 *
 * 题目描述：
 *   给定一个计算图，每个节点表示一个计算操作。要求计算输出节点的值以及所有输入变量的梯度。
 *   节点类型：
 *   0：输入变量；1：加法；2：减法；3：乘法；4：指数；5：对数；6：正弦。
 *   输入格式：第一行给出整数 N。接下来 N 行，每行给出一个节点的类型和参数。
 *   输出格式：第一行输出输出节点的值，第二行输出所有输入变量的梯度（按输入顺序）。
 *
 * 实现原理：
 *   使用前向传播计算节点值，使用反向传播计算梯度。
 *   1. 前向传播：按节点顺序计算每个节点的值。
 *      输入变量直接读取；二元运算根据操作数计算；一元运算应用数学函数。
 *   2. 反向传播：从输出节点开始，按逆序计算每个节点的梯度。
 *      使用链式法则：grad[a] += grad[i] * d(val[i])/d(val[a])。
 *      加法：grad[a] += grad[i], grad[b] += grad[i]
 *      减法：grad[a] += grad[i], grad[b] -= grad[i]
 *      乘法：grad[a] += grad[i] * val[b], grad[b] += grad[i] * val[a]
 *      指数：grad[a] += grad[i] * exp(val[a]) = grad[i] * val[i]
 *      对数：grad[a] += grad[i] / val[a]
 *      正弦：grad[a] += grad[i] * cos(val[a])
 *   3. 输出节点是入度为 0 的节点。
 *
 * 时间复杂度：O(N)，前向传播和反向传播各遍历一次
 */
int main(void){int n,i,j,type[50000],a[50000],b[50000],out=-1,vars[50000],nv=0,deg[50000]={0};double val[50000],grad[50000]={0};scanf("%d",&n);for(i=0;i<n;++i){scanf("%d",&type[i]);a[i]=b[i]=-1;if(type[i]==0){scanf("%lf",&val[i]);vars[nv++]=i;}else if(type[i]>=4){scanf("%d",&a[i]);deg[a[i]]++;if(type[i]==4)val[i]=exp(val[a[i]]);else if(type[i]==5)val[i]=log(val[a[i]]);else val[i]=sin(val[a[i]]);}else{scanf("%d%d",&a[i],&b[i]);deg[a[i]]++;deg[b[i]]++;if(type[i]==1)val[i]=val[a[i]]+val[b[i]];else if(type[i]==2)val[i]=val[a[i]]-val[b[i]];else val[i]=val[a[i]]*val[b[i]];}}for(i=0;i<n;++i)if(!deg[i])out=i;grad[out]=1;for(i=n-1;i>=0;--i){if(type[i]==1)grad[a[i]]+=grad[i],grad[b[i]]+=grad[i];else if(type[i]==2)grad[a[i]]+=grad[i],grad[b[i]]-=grad[i];else if(type[i]==3)grad[a[i]]+=grad[i]*val[b[i]],grad[b[i]]+=grad[i]*val[a[i]];else if(type[i]==4)grad[a[i]]+=grad[i]*val[i];else if(type[i]==5)grad[a[i]]+=grad[i]/val[a[i]];else if(type[i]==6)grad[a[i]]+=grad[i]*cos(val[a[i]]);}printf("%.3f\n",val[out]);for(i=0;i<nv;++i)printf("%s%.3f",i?" ":"",grad[vars[i]]);putchar('\n');return 0;}
