#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)) return 0;
    vector<vector<pair<int,int>>> ch(n);
    for(int i=1;i<n;i++){
        int j,s;
        cin>>j>>s;
        ch[j].push_back({i,s});
    }
    // Find leaves
    vector<int> leaves;
    for(int i=0;i<n;i++) if(ch[i].empty()) leaves.push_back(i);
    // If n==1, leaves includes 0 but not considered? But n>1.
    // Compute bottleneck for each leaf via DFS
    const int INF = 101;
    int best = -1;
    vector<int> bottleneck(n, -1);
    // BFS/DFS stack: node, curMin
    struct Item{int u; int curMin;};
    vector<Item> stack;
    stack.reserve(n);
    stack.push_back({0, INF});
    vector<int> minTo(n, INF);
    minTo[0]=INF;
    // iterative DFS
    vector<int> order;
    order.push_back(0);
    size_t idx=0;
    // Use stack for traversal
    vector<int> st; st.push_back(0);
    while(!st.empty()){
        int u=st.back(); st.pop_back();
        for(auto [v,w]: ch[u]){
            int cur = min(minTo[u], w);
            minTo[v]=cur;
            st.push_back(v);
        }
    }
    for(int leaf: leaves){
        if(leaf==0) continue; // entrance not treasure
        int b = minTo[leaf];
        best = max(best, b);
    }
    if(best==-1) best=0;
    cout<<best<<"\n";
    vector<int> cand;
    for(int leaf: leaves){
        if(leaf==0) continue;
        if(minTo[leaf]==best) cand.push_back(leaf);
    }
    sort(cand.begin(), cand.end()); // ascending to match sample
    for(int i=0;i<(int)cand.size();i++){
        if(i) cout<<' ';
        cout<<cand[i];
    }
    if(!cand.empty()) cout<<"\n";
    return 0;
}
