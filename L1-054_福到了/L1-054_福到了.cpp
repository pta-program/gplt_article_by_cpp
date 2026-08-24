#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    char replace_char;
    int N;
    if (!(cin >> replace_char >> N)) return 0;
    string dummy;
    getline(cin, dummy); // consume endline
    vector<string> grid(N);
    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);
        // If line shorter than N, pad with spaces (trailing spaces may be trimmed)
        if ((int)line.size() < N) line += string(N - line.size(), ' ');
        else if ((int)line.size() > N) line = line.substr(0, N);
        grid[i] = line;
    }
    bool symmetric = true;
    for (int i = 0; i < N && symmetric; ++i) {
        for (int j = 0; j < N; ++j) {
            if (grid[i][j] != grid[N - 1 - i][N - 1 - j]) {
                symmetric = false;
                break;
            }
        }
    }
    if (symmetric) {
        cout << "bu yong dao le\n";
    }
    for (int i = N - 1; i >= 0; --i) {
        for (int j = N - 1; j >= 0; --j) {
            char c = grid[i][j];
            if (c == '@') cout << replace_char;
            else cout << c;
        }
        cout << "\n";
    }
    return 0;
}
