#include <bits/stdc++.h>
using namespace std;
int N, L;
vector<int> colRem;
long long ans;

void dfs_row(int r) {
    if (r == N) { ans++; return; }
    if (r == N - 1) {
        long long sum = 0;
        for (int c = 0; c < N; ++c) sum += colRem[c];
        if (sum != L) return;
        ans++;
        return;
    }
    vector<int> cur(N, 0);
    function<void(int,int)> gen = [&](int c, int rem) {
        if (c == N) {
            if (rem == 0) {
                for (int i = 0; i < N; ++i) colRem[i] -= cur[i];
                dfs_row(r + 1);
                for (int i = 0; i < N; ++i) colRem[i] += cur[i];
            }
            return;
        }
        int maxV = min(rem, colRem[c]);
        for (int v = 0; v <= maxV; ++v) {
            cur[c] = v;
            gen(c + 1, rem - v);
        }
    };
    gen(0, L);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!(cin >> L >> N)) return 0;
    colRem.assign(N, L);
    ans = 0;
    dfs_row(0);
    cout << ans << "\n";
    return 0;
}
