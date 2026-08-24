#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    if (!(cin >> N >> M)) return 0;
    string line;
    getline(cin, line);
    int cnt = 0;
    string ans;
    bool found = false;
    for (int i = 0; i < N; ++i) {
        getline(cin, line);
        bool isSignIn = false;
        if (line.find("qiandao") != string::npos) isSignIn = true;
        if (line.find("easy") != string::npos) isSignIn = true;
        if (!isSignIn) {
            ++cnt;
            if (cnt == M + 1) {
                ans = line;
                found = true;
                // need to consume remaining lines to keep input clean, but we can just output and skip
                // still need to read remaining lines if we continue? We can break after reading all? Simpler break and ignore rest.
                // To avoid needing to read rest, just remember answer and continue reading to consume, but not needed.
                // We'll continue reading remaining lines to exhaust input, but keep answer.
            }
        }
    }
    if (found) cout << ans << "\n";
    else cout << "Wo AK le\n";
    return 0;
}
