#include <iostream>
#include <map>
using namespace std;
int main() {
    int N, K, S;
    if (!(cin >> N >> K >> S)) return 0;
    map<int, pair<int,int>> mp; // score -> (normal, pat)
    for (int i = 0; i < N; ++i) {
        int score, pat;
        cin >> score >> pat;
        if (score < 175) continue;
        if (pat >= S) mp[score].second++;
        else mp[score].first++;
    }
    long long total = 0;
    for (auto &p : mp) {
        int normal = p.second.first;
        int pat = p.second.second;
        total += min(normal, K);
        total += pat; // all PAT-qualified can be recommended
    }
    cout << total << "\n";
    return 0;
}
