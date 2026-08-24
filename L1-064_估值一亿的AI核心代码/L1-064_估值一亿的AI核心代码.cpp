#include <bits/stdc++.h>
using namespace std;

bool isIndependent(const string &s, size_t pos, size_t len) {
    bool leftOK = (pos == 0) || !isalnum((unsigned char)s[pos - 1]);
    bool rightOK = (pos + len >= s.size()) || !isalnum((unsigned char)s[pos + len]);
    return leftOK && rightOK;
}

void replaceIndependent(string &s, const string &oldStr, const string &newStr) {
    size_t pos = 0;
    while (true) {
        pos = s.find(oldStr, pos);
        if (pos == string::npos) break;
        if (isIndependent(s, pos, oldStr.size())) {
            s.replace(pos, oldStr.size(), newStr);
            pos += newStr.size();
        } else {
            pos += oldStr.size();
            if (pos == 0) break; // avoid overflow
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if (!(cin >> N)) return 0;
    string line;
    getline(cin, line);
    for (int i = 0; i < N; ++i) {
        getline(cin, line);
        cout << line << "\n";
        string t = line;
        // ? -> !
        for (char &c : t) if (c == '?') c = '!';
        // upper -> lower except 'I'
        for (char &c : t) {
            if (c != 'I' && isupper((unsigned char)c)) c = tolower((unsigned char)c);
        }
        // eliminate extra spaces
        string r;
        r.reserve(t.size());
        bool prevSpace = true; // to trim leading
        for (char c : t) {
            if (isspace((unsigned char)c)) {
                prevSpace = true;
            } else {
                if (prevSpace && !r.empty()) {
                    if (ispunct((unsigned char)c)) {
                        // no space before punctuation
                    } else {
                        r.push_back(' ');
                    }
                }
                r.push_back(c);
                prevSpace = false;
            }
        }
        // replace independent I and me BEFORE can/could to preserve I in phrase
        replaceIndependent(r, "I", "you");
        replaceIndependent(r, "me", "you");
        // replace independent phrases
        replaceIndependent(r, "can you", "I can");
        replaceIndependent(r, "could you", "I could");

        cout << "AI: " << r << "\n";
    }
    return 0;
}
