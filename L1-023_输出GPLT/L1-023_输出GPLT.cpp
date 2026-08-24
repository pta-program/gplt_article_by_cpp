#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/**
 * L1-023 - 输出GPLT
 * 修复点：补充 <cctype> 以保证 toupper 可移植；其余逻辑不变。
 */
int main() {
    string s;
    getline(cin, s);
    int cnt[4] = {0}; // G P L T
    for (char c : s) {
        switch (toupper((unsigned char)c)) {
            case 'G': cnt[0]++; break;
            case 'P': cnt[1]++; break;
            case 'L': cnt[2]++; break;
            case 'T': cnt[3]++; break;
            default: break;
        }
    }
    while (cnt[0] > 0 || cnt[1] > 0 || cnt[2] > 0 || cnt[3] > 0) {
        if (cnt[0] > 0) { cout << 'G'; cnt[0]--; }
        if (cnt[1] > 0) { cout << 'P'; cnt[1]--; }
        if (cnt[2] > 0) { cout << 'L'; cnt[2]--; }
        if (cnt[3] > 0) { cout << 'T'; cnt[3]--; }
    }
    cout << '\n';
    return 0;
}
