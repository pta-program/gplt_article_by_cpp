#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)) return 0;
    const int OFFSET = 1000000;
    const int SZ = 2000001;
    vector<char> has0(SZ,0), has1(SZ,0), has2(SZ,0);
    vector<int> v0, v1, v2;
    v0.reserve(n); v1.reserve(n); v2.reserve(n);
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        int idx=x+OFFSET;
        if(y==0){ if(!has0[idx]){has0[idx]=1; v0.push_back(x);} }
        else if(y==1){ if(!has1[idx]){has1[idx]=1; v1.push_back(x);} }
        else { if(!has2[idx]){has2[idx]=1; v2.push_back(x);} }
    }
    if(v0.empty() || v1.empty() || v2.empty()){
        cout<<-1<<"\n";
        return 0;
    }
    sort(v0.begin(), v0.end());
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    // Use presence array for v2 for O(1)
    vector<array<int,3>> ans;
    ans.reserve(100000);
    // iterate over middle
    for(int x1: v1){
        for(int x0: v0){
            long long x2 = 2LL*x1 - x0;
            if(x2 < -1000000 || x2 > 1000000) continue;
            if(has2[x2+OFFSET]){
                ans.push_back({x1,x0,(int)x2});
            }
        }
    }
    if(ans.empty()){
        cout<<-1<<"\n";
        return 0;
    }
    sort(ans.begin(), ans.end(), [](auto &a, auto &b){
        if(a[0]!=b[0]) return a[0] < b[0];
        return a[1] < b[1];
    });
    for(auto &t: ans){
        int x1=t[0], x0=t[1], x2=t[2];
        cout<<"["<<x0<<", 0] ["<<x1<<", 1] ["<<x2<<", 2]\n";
    }
    return 0;
}
