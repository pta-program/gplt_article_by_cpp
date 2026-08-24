#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-016 二叉搜索树的结构
 *
 * 题目描述：
 *   给定一个整数序列，按顺序插入到二叉搜索树中（小值插入右子树，大值插入左子树）。
 *   然后回答 M 个关于树结构的问题，判断断言是否成立。
 *   断言类型包括：某节点是根节点、两个节点是兄弟、两个节点在同一层、
 *   某节点是另一节点的父亲、某节点是另一节点的左孩子、某节点是另一节点的右孩子。
 *   输入格式：第一行给出整数 N。第二行给出 N 个整数表示插入序列。
 *   第三行给出整数 M。接下来 M 行，每行给出一个断言语句。
 *   输出格式：对于每个断言，输出 "Yes" 或 "No"。
 *
 * 实现原理：
 *   构建二叉搜索树并记录每个节点的父亲和层数信息。
 *   1. 按顺序插入节点，记录每个节点的 left、right、parent、level。
 *   2. 使用 find() 函数根据关键字查找节点索引。
 *   3. 根据断言类型进行判断：
 *      a. root：检查节点索引是否等于根节点索引。
 *      b. siblings：检查两个节点的父亲是否相同。
 *      c. same level：检查两个节点的层数是否相同。
 *      d. parent of：检查父节点关系。
 *      e. left/right child：检查子节点关系。
 *
 * 时间复杂度：O(N^2 + M)，建树为 O(N^2)，查询为 O(M)
 */
typedef struct {int key,left,right,parent,level;} Node;
static int find(Node a[],int n,int x){int i;for(i=0;i<n;++i)if(a[i].key==x)return i;return -1;}
int main(void){Node a[100];int n,m,i,root=0;char s[100];scanf("%d",&n);for(i=0;i<n;++i){int x,cur;scanf("%d",&x);a[i]=(Node){x,-1,-1,-1,0};if(!i)continue;cur=root;while(1){int *next=x<a[cur].key?&a[cur].left:&a[cur].right;if(*next<0){*next=i;a[i].parent=cur;a[i].level=a[cur].level+1;break;}cur=*next;}}
scanf("%d",&m);getchar();while(m--){int x,y=-1,ix,iy,ok=0;fgets(s,sizeof(s),stdin);sscanf(s,"%d",&x);if(strstr(s," and "))sscanf(s,"%d and %d",&x,&y);else if(strstr(s,"parent of"))sscanf(s,"%d is the parent of %d",&x,&y);else if(strstr(s,"left child"))sscanf(s,"%d is the left child of %d",&x,&y);else if(strstr(s,"right child"))sscanf(s,"%d is the right child of %d",&x,&y);ix=find(a,n,x);iy=find(a,n,y);if(strstr(s,"root"))ok=ix==root;else if(ix>=0&&iy>=0&&strstr(s,"siblings"))ok=a[ix].parent>=0&&a[ix].parent==a[iy].parent;else if(ix>=0&&iy>=0&&strstr(s,"same level"))ok=a[ix].level==a[iy].level;else if(ix>=0&&iy>=0&&strstr(s,"parent of"))ok=a[iy].parent==ix;else if(ix>=0&&iy>=0&&strstr(s,"left child"))ok=a[iy].left==ix;else if(ix>=0&&iy>=0&&strstr(s,"right child"))ok=a[iy].right==ix;puts(ok?"Yes":"No");}return 0;}
