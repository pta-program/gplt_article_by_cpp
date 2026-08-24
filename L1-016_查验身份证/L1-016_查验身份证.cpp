#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/**
 * L1-016 - 查验身份证
 * 修复点：补充 <cctype> 头文件以确保 isdigit 可移植；其余逻辑保持不变。
 */
int main() {
    int weights[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    char check_codes[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

    int N;
    if (!(cin >> N)) return 0;
    bool all_passed = true;
    for (int i = 0; i < N; ++i) {
        string id; cin >> id;
        bool valid = true;
        int sum = 0;
        for (int j = 0; j < 17; ++j) {
            if (!isdigit((unsigned char)id[j])) { valid = false; break; }
            sum += (id[j] - '0') * weights[j];
        }
        if (valid) {
            int Z = sum % 11;
            char expected = check_codes[Z];
            char actual = id[17];
            if (actual == 'x') actual = 'X';
            if (expected != actual) valid = false;
        }
        if (!valid) { cout << id << '\n'; all_passed = false; }
    }
    if (all_passed) cout << "All passed\n";
    return 0;
}
