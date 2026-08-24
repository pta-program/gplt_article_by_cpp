#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if(!(cin >> N)) return 0;
    string line;
    getline(cin, line);
    vector<string> banned(N);
    for (int i=0;i<N;++i) getline(cin, banned[i]);
    int k;
    if(!(cin >> k)) return 0;
    getline(cin, line);
    string text;
    getline(cin, text);
    // sequential processing
    string cur = text;
    long long cnt = 0;
    for (auto &w : banned) {
        string nxt;
        nxt.reserve(cur.size()*2);
        for (size_t i=0; i<cur.size(); ) {
            if (i + w.size() <= cur.size() && cur.compare(i, w.size(), w)==0) {
                cnt++;
                nxt += "<censored>";
                i += w.size();
            } else {
                nxt.push_back(cur[i]);
                ++i;
            }
        }
        cur.swap(nxt);
    }
    if (cnt >= k) {
        cout << cnt << "\nHe Xie Ni Quan Jia!\n";
    } else {
        cout << cur << "\n";
    }
    return 0;
}
