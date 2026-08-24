#include <iostream>
#include <string>
using namespace std;

/**
 * L1-026 - I Love GPLT
 * 修复点：补充 <string> 头文件以保证可移植；逻辑不变。
 */
int main() {
    string s = "I Love GPLT";
    for (char c : s) cout << c << '\n';
    return 0;
}
