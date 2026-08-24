#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-019 代码排版
 *
 * 题目描述：
 *   给定一行C语言代码，要求按照C语言的语法规则进行格式化排版。
 *   具体要求：
 *   1. 大括号单独占一行，并根据嵌套层次缩进。
 *   2. 每条语句（以分号结尾）单独占一行。
 *   3. 字符串中的字符保持原样，不参与语法分析。
 *   输入格式：输入一行C语言代码。
 *   输出格式：输出格式化后的代码，每个缩进级别为两个空格。
 *
 * 实现原理：
 *   使用词法扫描器逐字符解析代码，处理字符串、大括号和分号。
 *   1. 使用 instr 标志跟踪是否在字符串内部。
 *   2. 遇到双引号且前一个字符不是反斜杠时，切换 instr 状态。
 *   3. 在非字符串状态下：
 *      a. 遇到 '{'：输出当前累积的语句（如果有），输出 '{'，缩进深度 +1。
 *      b. 遇到 '}'：输出当前累积的语句（如果有），缩进深度 -1，输出 '}'。
 *      c. 遇到 ';'：将分号加入当前语句，输出并清空缓冲区。
 *   4. 使用 trim() 函数去除语句两端的空白字符。
 *
 * 时间复杂度：O(N)，其中 N 是代码长度
 */
static void trim(char *s){int l=0,r=strlen(s);while(isspace((unsigned char)s[l]))++l;while(r>l&&isspace((unsigned char)s[r-1]))--r;memmove(s,s+l,r-l);s[r-l]=0;}
static void output(int dep,const char*s){int i;for(i=0;i<dep*2;++i)putchar(' ');puts(s);}
int main(void){char s[400],buf[400];int i,dep=0,b=0,instr=0;fgets(s,sizeof(s),stdin);for(i=0;s[i];++i){char c=s[i];if(c=='"'&&(i==0||s[i-1]!='\\'))instr=!instr;if(!instr&&c=='{'){buf[b]=0;trim(buf);if(b)output(dep,buf);output(dep,"{");++dep;b=0;}else if(!instr&&c=='}'){buf[b]=0;trim(buf);if(b)output(dep,buf);--dep;output(dep,"}");b=0;}else if(!instr&&c==';'){buf[b++]=c;buf[b]=0;trim(buf);if(b)output(dep,buf);b=0;}else buf[b++]=c;}buf[b]=0;trim(buf);if(b)output(dep,buf);return 0;}
