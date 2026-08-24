#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    if (!(cin >> N >> M)) return 0;
    for (int i = 0; i < M; ++i) {
        string s; cin >> s;
        long long ans = 0;
        for (char c : s) {
            ans = ans * 2 + (c == 'n' ? 1 : 0);
        }
        cout << ans + 1 << "\n";
    }
    return 0;
}
