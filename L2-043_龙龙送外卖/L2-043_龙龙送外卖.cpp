#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    if(!(cin>>N>>M)) return 0;
    vector<int> par(N+1,0);
    int root=-1;
    for(int i=1;i<=N;i++){
        int p;cin>>p;
        if(p==-1){par[i]=0; root=i;}
        else par[i]=p;
    }
    vector<vector<int>> ch(N+1);
    for(int i=1;i<=N;i++) if(par[i]!=0) ch[par[i]].push_back(i);
    vector<int> depth(N+1,0);
    queue<int> q;
    q.push(root);
    depth[root]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int v: ch[u]){
            depth[v]=depth[u]+1;
            q.push(v);
        }
    }
    vector<int> dsu(N+1);
    iota(dsu.begin(), dsu.end(), 0);
    vector<char> vis(N+1,0);
    vis[0]=1;
    function<int(int)> find = [&](int x)->int{
        int r=x;
        while(dsu[r]!=r) r=dsu[r];
        while(dsu[x]!=x){int nxt=dsu[x]; dsu[x]=r; x=nxt;}
        return r;
    };
    long long totalEdges=0;
    int maxDepth=0;
    for(int i=0;i<M;i++){
        int X;cin>>X;
        if(!vis[X]){
            int cur=find(X);
            while(cur!=0){
                vis[cur]=1;
                if(cur!=root) totalEdges++;
                dsu[cur]=find(par[cur]);
                cur=dsu[cur];
            }
            maxDepth=max(maxDepth, depth[X]);
        }
        cout<< totalEdges*2 - maxDepth << "\n";
    }
    return 0;
}
