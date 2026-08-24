#include <iostream>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    if(!(cin >> s)) return 0;
    long long cnt[26]={0};
    for(char c: s) if(c>='a' && c<='z') cnt[c-'a']++;
    for(int i=0;i<26;++i){
        if(i) cout << ' ';
        cout << cnt[i];
    }
    cout << "\n";
    long long beauty=0;
    for(int i=0;i<26;++i){
        long long score;
        cin >> score;
        beauty += cnt[i]*score;
    }
    cout << beauty << "\n";
    return 0;
}
