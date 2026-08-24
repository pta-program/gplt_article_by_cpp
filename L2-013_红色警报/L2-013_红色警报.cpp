#include <bits/stdc++.h>
using namespace std;

const int MAXN = 510;
int parent_[MAXN];

int findp(int x){
    if(parent_[x]!=x) parent_[x]=findp(parent_[x]);
    return parent_[x];
}
void unite(int a,int b){
    a=findp(a); b=findp(b);
    if(a!=b) parent_[b]=a;
}
int count_components(int N, const vector<pair<int,int>>& edges, const vector<bool>& destroyed){
    for(int i=0;i<N;i++) parent_[i]=i;
    for(auto &e: edges){
        int a=e.first, b=e.second;
        if(!destroyed[a] && !destroyed[b]){
            unite(a,b);
        }
    }
    unordered_set<int> roots;
    for(int i=0;i<N;i++){
        if(!destroyed[i]){
            roots.insert(findp(i));
        }
    }
    return (int)roots.size();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M;
    if(!(cin>>N>>M)) return 0;
    vector<pair<int,int>> edges;
    for(int i=0;i<M;i++){
        int a,b; cin>>a>>b;
        edges.emplace_back(a,b);
    }
    int K; cin>>K;
    vector<int> queries(K);
    for(int i=0;i<K;i++) cin>>queries[i];
    vector<bool> destroyed(N,false);
    int initial = count_components(N, edges, destroyed);
    int prev = initial;
    int remaining = N;
    for(int i=0;i<K;i++){
        int city = queries[i];
        destroyed[city]=true;
        remaining--;
        int cur = count_components(N, edges, destroyed);
        if(cur > prev){
            cout<<"Red Alert: City "<<city<<" is lost!"<<"\n";
        }else{
            cout<<"City "<<city<<" is lost."<<"\n";
        }
        prev = cur;
        if(remaining==0){
            cout<<"Game Over."<<"\n";
        }
    }
    return 0;
}
