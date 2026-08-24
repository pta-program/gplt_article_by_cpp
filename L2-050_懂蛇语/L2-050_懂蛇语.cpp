#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();

    unordered_map<string, vector<string>> dict;

    for (int i = 0; i < N; i++) {
        string line;
        getline(cin, line);
        string abbrev, word;
        istringstream iss(line);
        string first;
        iss >> first;
        abbrev += first[0];
        while (iss >> word) {
            abbrev += word[0];
        }
        dict[abbrev].push_back(line);
    }

    int M;
    cin >> M;
    cin.ignore();

    for (int i = 0; i < M; i++) {
        string line;
        getline(cin, line);
        string abbrev, word;
        istringstream iss(line);
        string first;
        iss >> first;
        abbrev += first[0];
        while (iss >> word) {
            abbrev += word[0];
        }

        if (dict.count(abbrev)) {
            auto &matches = dict[abbrev];
            sort(matches.begin(), matches.end());
            for (int j = 0; j < (int)matches.size(); j++) {
                if (j > 0) cout << "|";
                cout << matches[j];
            }
            cout << endl;
        } else {
            cout << line << endl;
        }
    }

    return 0;
}
