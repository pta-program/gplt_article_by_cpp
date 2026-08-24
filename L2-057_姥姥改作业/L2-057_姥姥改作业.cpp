#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long T;
    if(!(cin>>n>>T)) return 0;
    vector<long long> c(n+1);
    for(int i=1;i<=n;i++) cin>>c[i];
    // stack representation: vector<int> where back is top
    vector<int> cur;
    cur.reserve(n);
    for(int i=n;i>=1;--i) cur.push_back(i); // top =1
    vector<int> out;
    out.reserve(n);
    while(!cur.empty()){
        vector<int> left;
        left.reserve(cur.size());
        // process cur in pop order (top to bottom)
        // cur is stack, pop from back
        int sz = cur.size();
        for(int idx = sz-1; idx>=0; --idx){
            int id = cur[idx];
            if(c[id] > T) left.push_back(id);
            else out.push_back(id);
        }
        if(left.empty()) break;
        long long sum=0;
        for(int id: left) sum+=c[id];
        T = sum / (long long)left.size(); // floor
        cur.swap(left);
    }
    for(int i=0;i<(int)out.size();i++){
        if(i) cout<<' ';
        cout<<out[i];
    }
    cout<<"\n";
    return 0;
}
