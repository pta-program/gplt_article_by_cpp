#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> item_owners(m + 1);

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int item;
            cin >> item;
            item_owners[item].push_back(i);
        }
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int a, b;
        cin >> a >> b;
        const auto &va_raw = item_owners[a];
        const auto &vb_raw = item_owners[b];
        const vector<int> *pa = &va_raw, *pb = &vb_raw;
        if (pa->size() > pb->size()) swap(pa, pb);
        vector<char> in_b(n + 1, 0);
        for (int x : *pb) in_b[x] = 1;
        int cnt = 0;
        for (int x : *pa) if (in_b[x]) cnt++;
        cout << cnt << "\n";
    }

    return 0;
}
