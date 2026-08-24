#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if (!(cin >> N)) return 0;
    vector<int> teams(N);
    for (int i = 0; i < N; ++i) cin >> teams[i];
    vector<int> total(N);
    int max_st = 0;
    for (int i = 0; i < N; ++i) {
        total[i] = teams[i] * 10;
        max_st = max(max_st, total[i]);
    }
    vector<vector<int>> seats(N, vector<int>(max_st, 0));
    int seat_num = 1;
    int round = 0;
    while (true) {
        int left = 0;
        for (int i = 0; i < N; ++i) if (round < total[i]) ++left;
        if (left == 0) break;
        if (left == 1) {
            // leave one empty seat before isolated assignment
            seat_num++; // skip one seat
            for (int i = 0; i < N; ++i) {
                while (round < total[i]) {
                    seats[i][round] = seat_num;
                    seat_num += 2;
                    ++round;
                }
            }
            break;
        }
        for (int i = 0; i < N; ++i) {
            if (round < total[i]) {
                seats[i][round] = seat_num++;
            }
        }
        ++round;
    }
    for (int i = 0; i < N; ++i) {
        cout << "#" << i + 1 << "\n";
        for (int j = 0; j < teams[i]; ++j) {
            for (int k = 0; k < 10; ++k) {
                if (k) cout << ' ';
                cout << seats[i][j * 10 + k];
            }
            cout << "\n";
        }
    }
    return 0;
}
