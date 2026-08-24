#include <iostream>
#include <stack>
using namespace std;

/**
 * L2-033 - 简单计算器
 * 
 * 实现原理：
 * 使用两个堆栈执行计算。
 * 规则：
 * 1. S1存放数字，S2存放运算符
 * 2. 每次从S1弹出n1和n2，从S2弹出运算符op
 * 3. 计算n2 op n1，结果压回S1
 * 4. 直到两个堆栈都为空
 * 
 * 解题思路：
 * 1. 将数字和运算符依次压入堆栈
 * 2. 按规则执行计算
 * 3. 处理除法分母为零的情况
 */
int main() {
    int N;
    cin >> N;
    
    stack<int> S1;
    stack<char> S2;
    
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        S1.push(num);
    }
    
    for (int i = 0; i < N - 1; i++) {
        char op;
        cin >> op;
        S2.push(op);
    }
    
    while (!S1.empty() && !S2.empty()) {
        int n1 = S1.top();
        S1.pop();
        
        int n2 = S1.top();
        S1.pop();
        
        char op = S2.top();
        S2.pop();
        
        int result;
        switch (op) {
            case '+':
                result = n2 + n1;
                break;
            case '-':
                result = n2 - n1;
                break;
            case '*':
                result = n2 * n1;
                break;
            case '/':
                if (n1 == 0) {
                    cout << "ERROR: " << n2 << "/0" << endl;
                    return 0;
                }
                result = n2 / n1;
                break;
        }
        
        S1.push(result);
    }
    
    cout << S1.top() << endl;
    
    return 0;
}