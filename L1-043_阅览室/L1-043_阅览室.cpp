#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if (!(cin >> N)) return 0;
    for (int day = 0; day < N; ++day) {
        vector<int> borrow_time(1001, -1);
        int total_time = 0;
        int count = 0;
        while (true) {
            int book_id;
            char op;
            string time_str;
            cin >> book_id >> op >> time_str;
            if (book_id == 0) break;
            size_t p = time_str.find(':');
            int hh = stoi(time_str.substr(0, p));
            int mm = stoi(time_str.substr(p + 1));
            int total_minutes = hh * 60 + mm;
            if (op == 'S') {
                borrow_time[book_id] = total_minutes;
            } else if (op == 'E') {
                if (borrow_time[book_id] != -1) {
                    int duration = total_minutes - borrow_time[book_id];
                    total_time += duration;
                    ++count;
                    borrow_time[book_id] = -1;
                }
            }
        }
        if (count == 0) {
            cout << "0 0\n";
        } else {
            int avg = (total_time + count / 2) / count;
            cout << count << ' ' << avg << "\n";
        }
    }
    return 0;
}
