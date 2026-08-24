#include <iostream>
#include <string>
using namespace std;

/**
 * L1-091 - 程序员买包子
 * 
 * 实现原理：
 * 根据买包子的数量判断是否看到卖X的。
 * 如果 K=N：没看到
 * 如果 K=M：看到了
 * 否则：忘了找
 * 
 * 解题思路：
 * 1. 读取N、X、M、K
 * 2. 根据条件判断并输出结果
 */
int main() {
    int N, M, K;
    string X;
    cin >> N >> X >> M >> K;
    
    if (K == N) {
        cout << "mei you mai " << X << " de" << endl;
    } else if (K == M) {
        cout << "kan dao le mai " << X << " de" << endl;
    } else {
        cout << "wang le zhao mai " << X << " de" << endl;
    }
    
    return 0;
}