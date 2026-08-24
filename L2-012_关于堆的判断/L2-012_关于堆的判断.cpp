#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    if (!(cin >> N >> M)) return 0;
    vector<int> heap(N + 1);
    unordered_map<int,int> pos;
    int sz = 0;
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        ++sz;
        heap[sz] = x;
        pos[x] = sz;
        int j = sz;
        while (j > 1 && heap[j] < heap[j/2]) {
            swap(heap[j], heap[j/2]);
            pos[heap[j]] = j;
            pos[heap[j/2]] = j/2;
            j /= 2;
        }
    }
    string dummy;
    getline(cin, dummy); // consume endline
    for (int i = 0; i < M; ++i) {
        string line;
        getline(cin, line);
        while(line.size()==0 && !cin.eof()) getline(cin, line); // skip empty
        // tokenise by spaces
        vector<string> tok;
        {
            stringstream ss(line);
            string t;
            while (ss >> t) tok.push_back(t);
        }
        // tok[0] is x
        // determine type
        bool ans = false;
        if (find(tok.begin(), tok.end(), string("root")) != tok.end()) {
            int x = stoi(tok[0]);
            ans = (pos[x] == 1);
        } else if (find(tok.begin(), tok.end(), string("siblings")) != tok.end()) {
            int x = stoi(tok[0]);
            int y = stoi(tok[2]);
            ans = (pos[x]/2 == pos[y]/2 && pos[x]!=pos[y]);
        } else if (find(tok.begin(), tok.end(), string("parent")) != tok.end()) {
            int x = stoi(tok[0]);
            // format: x is the parent of y  -> y is tok[5]
            int y = stoi(tok[5]);
            ans = (pos[y]/2 == pos[x]);
        } else if (find(tok.begin(), tok.end(), string("child")) != tok.end()) {
            int x = stoi(tok[0]);
            int y = stoi(tok[5]);
            ans = (pos[x]/2 == pos[y]);
        }
        cout << (ans ? "T" : "F") << "\n";
    }
    return 0;
}
