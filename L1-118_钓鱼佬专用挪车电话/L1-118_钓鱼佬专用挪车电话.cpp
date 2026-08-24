#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> lines;
    string s;
    while((int)lines.size()<11 && std::getline(cin, s)){
        // keep the line as is (including empty)
        // if EOF and line is empty due to trailing newline, still count
        lines.push_back(s);
    }
    // If input contains fewer than 11 lines because of missing final newline, handle
    // Some judges provide 11 lines exactly, so lines.size() should be 11
    // If lines still less than 11, try to read remaining with cin.eof?
    for(size_t i=0;i<lines.size();++i){
        int cnt=0;
        for(char c: lines[i]) if(c=='m') cnt++;
        // also if line empty cnt=0, length may be 0 -> 0
        // fallback: if no 'm' but line not empty length equals cnt
        if(cnt==0 && !lines[i].empty()){
            // count anyway by length if contains other chars? but spec only m
            cnt = (int)lines[i].size();
            if(cnt>9) cnt=9;
        }
        if(cnt>9) cnt=9;
        cout<<cnt;
    }
    // If we read less than 11 but still expect 11, we already output what we have
    // If we read 10 due to bug, but spec says 11, just output newline
    cout<<"\n";
    return 0;
}
