#include <bits/stdc++.h>
using namespace std;
static inline string trim(const string &s) {
    size_t a = 0;
    while (a < s.size() && isspace((unsigned char)s[a])) ++a;
    size_t b = s.size();
    while (b > a && isspace((unsigned char)s[b-1])) --b;
    return s.substr(a, b - a);
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
        size_t comma_pos = line.find(',');
        size_t dot_pos = line.find('.');
        if (comma_pos == string::npos || dot_pos == string::npos) {
            cout << "Skipped\n";
            continue;
        }
        string first_part = line.substr(0, comma_pos);
        string second_raw = line.substr(comma_pos + 1, dot_pos - comma_pos - 1);
        // extract last word of first part
        string first_trim = trim(first_part);
        string last_word1;
        {
            size_t p = first_trim.rfind(' ');
            if (p == string::npos) last_word1 = first_trim;
            else last_word1 = first_trim.substr(p + 1);
        }
        // tokenise second part to words (single space separated, but be robust)
        vector<string> words;
        {
            string t = trim(second_raw);
            string cur;
            for (char c : t) {
                if (isspace((unsigned char)c)) {
                    if (!cur.empty()) { words.push_back(cur); cur.clear(); }
                } else cur.push_back(c);
            }
            if (!cur.empty()) words.push_back(cur);
        }
        string last_word2 = words.empty() ? "" : words.back();
        auto endsWithOng = [](const string &w)->bool{
            if (w.size() < 3) return false;
            return w.substr(w.size()-3) == "ong";
        };
        bool is_ong = endsWithOng(last_word1) && endsWithOng(last_word2);
        if (!is_ong) {
            cout << "Skipped\n";
        } else {
            // replace last three words with qiao ben zhong
            if (words.size() >= 3) {
                words.pop_back(); words.pop_back(); words.pop_back();
            } else {
                words.clear();
            }
            words.push_back("qiao");
            words.push_back("ben");
            words.push_back("zhong");
            // reconstruct second part
            string new_second;
            for (size_t k = 0; k < words.size(); ++k) {
                if (k) new_second.push_back(' ');
                new_second += words[k];
            }
            // first_part as original (trim right spaces?)
            string first_out = trim(first_part);
            cout << first_out << ", " << new_second << ".\n";
        }
    }
    return 0;
}
