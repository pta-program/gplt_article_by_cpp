#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if(!(cin>>N)) return 0;
    vector<char> gender(N+1);
    vector<vector<pair<int,int>>> g(N+1);
    for(int i=1;i<=N;i++){
        char gg; int K;
        cin>>gg>>K;
        gender[i]=gg;
        for(int j=0;j<K;j++){
            int fid, d; char colon;
            cin>>fid>>colon>>d;
            g[i].push_back({fid,d});
        }
    }
    const long long INF = 4e12;
    vector<vector<long long>> allDist(N+1, vector<long long>(N+1, INF));
    for(int s=1;s<=N;s++){
        vector<long long> &dist = allDist[s];
        dist[s]=0;
        using P=pair<long long,int>;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0,s});
        while(!pq.empty()){
            auto [d,u]=pq.top(); pq.pop();
            if(d!=dist[u]) continue;
            for(auto [v,w]: g[u]){
                if(dist[v] > d + w){
                    dist[v]=d+w;
                    pq.push({dist[v], v});
                }
            }
        }
    }
    vector<long long> maxDist(N+1, INF);
    for(int i=1;i<=N;i++){
        long long mx=0;
        bool hasOpposite=false;
        bool unreachable=false;
        for(int j=1;j<=N;j++){
            if(gender[j]==gender[i]) continue;
            hasOpposite=true;
            if(allDist[j][i]==INF){unreachable=true; break;}
            mx=max(mx, allDist[j][i]);
        }
        if(!hasOpposite) mx=INF;
        else if(unreachable) mx=INF;
        maxDist[i]=mx;
    }
    long long bestF = INF, bestM = INF;
    for(int i=1;i<=N;i++){
        if(gender[i]=='F') bestF=min(bestF, maxDist[i]);
        else bestM=min(bestM, maxDist[i]);
    }
    vector<int> candF, candM;
    for(int i=1;i<=N;i++){
        if(gender[i]=='F' && maxDist[i]==bestF) candF.push_back(i);
        if(gender[i]=='M' && maxDist[i]==bestM) candM.push_back(i);
    }
    sort(candF.begin(), candF.end());
    sort(candM.begin(), candM.end());
    for(int i=0;i<(int)candF.size();i++){
        if(i) cout<<' ';
        cout<<candF[i];
    }
    cout<<"\n";
    for(int i=0;i<(int)candM.size();i++){
        if(i) cout<<' ';
        cout<<candM[i];
    }
    cout<<"\n";
    return 0;
}
