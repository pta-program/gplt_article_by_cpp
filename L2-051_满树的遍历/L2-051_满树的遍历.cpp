#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> children(n + 1);
    int root = 0;

    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        if (p == 0) root = i;
        else children[p].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        sort(children[i].begin(), children[i].end());
    }

    int max_degree = 0;
    for (int i = 1; i <= n; i++) {
        max_degree = max(max_degree, (int)children[i].size());
    }

    bool is_full_kary = true;
    for (int i = 1; i <= n; i++) {
        if (!children[i].empty() && (int)children[i].size() != max_degree) {
            is_full_kary = false;
            break;
        }
    }

    vector<int> preorder;
    stack<int> st;
    st.push(root);
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        preorder.push_back(u);
        for (int i = (int)children[u].size() - 1; i >= 0; i--) {
            st.push(children[u][i]);
        }
    }

    cout << max_degree;
    if (is_full_kary) cout << " yes";
    else cout << " no";
    cout << endl;

    for (int i = 0; i < (int)preorder.size(); i++) {
        if (i > 0) cout << " ";
        cout << preorder[i];
    }
    cout << endl;

    return 0;
}
