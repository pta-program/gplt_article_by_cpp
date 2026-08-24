#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    if(!(cin>>n>>m)) return 0;
    vector<vector<pair<int,int>>> g(n+1);
    for(int i=0;i<m;i++){
        int id1,id2,p;
        cin>>id1>>id2>>p;
        g[id1].push_back({id2,p});
    }
    int K;
    cin>>K;
    vector<int> queries(K);
    for(int i=0;i<K;i++) cin>>queries[i];
    for(int qi=0; qi<K; ++qi){
        int start=queries[qi];
        vector<int> path;
        vector<char> vis(n+1,0);
        path.push_back(start);
        vis[start]=1;
        int cur=start;
        while(true){
            int bestP=-1;
            int bestId=INT_MAX;
            for(auto [nxt,p]: g[cur]){
                if(vis[nxt]) continue;
                if(p > bestP || (p==bestP && nxt < bestId)){
                    bestP=p;
                    bestId=nxt;
                }
            }
            if(bestP==-1) break;
            path.push_back(bestId);
            vis[bestId]=1;
            cur=bestId;
        }
        for(int i=0;i<(int)path.size();i++){
            if(i) cout<<"->";
            cout<<path[i];
        }
        cout<<"\n";
    }
    return 0;
}
