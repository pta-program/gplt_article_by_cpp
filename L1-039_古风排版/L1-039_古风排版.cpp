#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * L1-039 - 古风排版
 * 修复点：原代码使用 VLA char grid[N][cols] 非标准 C++，改为 vector 实现，
 * 保证 -std=c++17 下标准兼容；逻辑保持古风排版（右→左、上→下）。
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string s;
    if (!(cin >> N)) return 0;
    cin.ignore();                 // 去掉行末换行
    getline(cin, s);

    int len = (int)s.length();
    int cols = (len + N - 1) / N; // 向上取整
    vector<vector<char>> grid(N, vector<char>(cols, ' '));

    int idx = 0;
    for (int j = cols - 1; j >= 0; --j) {
        for (int i = 0; i < N; ++i) {
            if (idx < len) grid[i][j] = s[idx++];
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < cols; ++j) cout << grid[i][j];
        cout << '\n';
    }
    return 0;
}
