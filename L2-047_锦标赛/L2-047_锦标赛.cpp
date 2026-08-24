#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;
    int n = 1 << k;

    vector<vector<int>> l(k);
    for (int i = 0; i < k; i++) {
        int cnt = 1 << (k - i - 1);
        l[i].resize(cnt);
        for (int j = 0; j < cnt; j++) {
            cin >> l[i][j];
        }
    }

    int w;
    cin >> w;

    vector<vector<set<int>>> S(k);
    for (int i = 0; i < k; i++) {
        S[i].resize(1 << (k - i - 1));
    }

    for (int j = 0; j < (1 << (k - 1)); j++) {
        set<int> V;
        V.insert(w);
        for (int i = 1; i < k; i++) {
            int j_idx = j / (1 << i);
            if (j_idx < (int)l[i].size()) {
                V.insert(l[i][j_idx]);
            }
        }
        for (int v : V) {
            if (v >= l[0][j]) {
                S[0][j].insert(v);
            }
        }
    }

    for (int i = 1; i < k; i++) {
        for (int j = 0; j < (1 << (k - i - 1)); j++) {
            int left = 2 * j;
            int right = 2 * j + 1;

            bool left_can_lose = S[i-1][left].count(l[i][j]) > 0;
            bool right_can_lose = S[i-1][right].count(l[i][j]) > 0;

            if (left_can_lose) {
                for (int v : S[i-1][right]) {
                    if (v >= l[i][j]) {
                        S[i][j].insert(v);
                    }
                }
            }
            if (right_can_lose) {
                for (int v : S[i-1][left]) {
                    if (v >= l[i][j]) {
                        S[i][j].insert(v);
                    }
                }
            }
        }
    }

    if (S[k-1][0].count(w) == 0) {
        cout << "No Solution" << endl;
        return 0;
    }

    vector<int> result(n, -1);

    function<void(int, int, int)> assign = [&](int i, int j, int target_value) {
        if (i == 0) {
            result[2*j] = target_value;
            result[2*j+1] = l[0][j];
        } else {
            int left = 2 * j;
            int right = 2 * j + 1;

            bool left_lose = false, right_lose = false;

            if (S[i-1][left].count(l[i][j]) && S[i-1][right].count(target_value) && target_value >= l[i][j]) {
                left_lose = true;
            }
            if (S[i-1][right].count(l[i][j]) && S[i-1][left].count(target_value) && target_value >= l[i][j]) {
                right_lose = true;
            }

            if (!left_lose && !right_lose) {
                cout << "No Solution" << endl;
                exit(0);
            }

            if (left_lose) {
                assign(i-1, left, l[i][j]);
                assign(i-1, right, target_value);
            } else {
                assign(i-1, right, l[i][j]);
                assign(i-1, left, target_value);
            }
        }
    };

    assign(k-1, 0, w);

    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << endl;

    return 0;
}
