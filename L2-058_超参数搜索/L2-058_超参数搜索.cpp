#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)) return 0;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    int mx = *max_element(a.begin()+1, a.end());
    vector<int> best;
    for(int i=1;i<=n;i++) if(a[i]==mx) best.push_back(i);
    for(int i=0;i<(int)best.size();i++){
        if(i) cout<<' ';
        cout<<best[i];
    }
    cout<<"\n";
    // map score -> minimal index
    unordered_map<int,int> minIdx;
    minIdx.reserve(n*2);
    for(int i=1;i<=n;i++){
        auto it=minIdx.find(a[i]);
        if(it==minIdx.end() || i < it->second) minIdx[a[i]] = i;
    }
    vector<int> uniq;
    uniq.reserve(minIdx.size());
    for(auto &p: minIdx) uniq.push_back(p.first);
    sort(uniq.begin(), uniq.end());
    int m;cin>>m;
    for(int i=0;i<m;i++){
        int x;cin>>x;
        auto it = upper_bound(uniq.begin(), uniq.end(), x);
        if(it==uniq.end()) cout<<0<<"\n";
        else cout<< minIdx[*it] << "\n";
    }
    return 0;
}
