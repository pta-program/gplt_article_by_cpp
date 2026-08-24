#include <bits/stdc++.h>
// using namespace std; removed to avoid name conflict

/*
 * L3-002 特殊堆栈
 *
 * 题目描述：
 *   实现一个特殊的堆栈，支持以下三种操作：
 *   1. Push X：将整数 X 压入堆栈。
 *   2. Pop：弹出堆栈顶元素；如果堆栈为空，输出 "Invalid"。
 *   3. PeekMedian：查询堆栈中所有元素的中位数（即第 floor((n+1)/2) 小的元素）。
 *   输入格式：第一行给出操作次数 N。接下来 N 行，每行给出一个操作指令。
 *   输出格式：对于 Pop 操作，输出弹出的元素；对于 PeekMedian 操作，输出中位数。
 *
 * 实现原理：
 *   使用栈存储元素，同时使用 Fenwick 树（二叉索引树）维护元素频率，支持快速查询第 k 小元素。
 *   1. 栈 stack[]：按顺序保存所有元素，top 指针指向栈顶。
 *   2. Fenwick 树 bit[]：维护每个数值出现的次数，支持两个操作：
 *      a. add(x, delta)：将数值 x 的计数增加 delta（压栈时 delta=1，弹栈时 delta=-1）。
 *      b. kth(k)：查找第 k 小的数值（通过二进制拆分快速定位）。
 *   3. Push 操作：元素入栈，同时更新 Fenwick 树。
 *   4. Pop 操作：元素出栈，同时更新 Fenwick 树。
 *   5. PeekMedian 操作：查询第 (top+1)/2 小的元素。
 *
 * 时间复杂度：每个操作 O(log M)，其中 M 是数值范围（1~100000）
 */
int bit[100001], stack[100001], top;
static void add(int x, int delta) { for (; x <= 100000; x += x & -x) bit[x] += delta; }
static int kth(int k) { int x = 0, step; for (step = 1 << 16; step; step >>= 1) if (x + step <= 100000 && bit[x + step] < k) k -= bit[x += step]; return x + 1; }
int main(void) {
    int n; char op[20]; if (scanf("%d", &n) != 1) return 0;
    while (n--) { scanf("%s", op); if (!strcmp(op, "Push")) { int x; scanf("%d", &x); stack[top++] = x; add(x, 1); } else if (!top) puts("Invalid"); else if (!strcmp(op, "Pop")) { int x = stack[--top]; printf("%d\n", x); add(x, -1); } else printf("%d\n", kth((top + 1) / 2)); }
    return 0;
}
