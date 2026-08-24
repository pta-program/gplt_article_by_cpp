#include <bits/stdc++.h>
using namespace std;

int toSec(const string& t){
    int hh,mm,ss;
    sscanf(t.c_str(),"%d:%d:%d",&hh,&mm,&ss);
    return hh*3600+mm*60+ss;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)) return 0;
    vector<pair<int,int>> segs;
    segs.reserve(n);
    for(int i=0;i<n;i++){
        string a,b;
        cin>>a>>b;
        int s=toSec(a);
        int e=toSec(b);
        segs.emplace_back(s,e);
    }
    // Convert to half-open [s, e+1)
    vector<pair<int,int>> events; // time, delta
    events.reserve(2*n);
    for(auto &p: segs){
        events.emplace_back(p.first, 1);
        events.emplace_back(p.second+1, -1);
    }
    sort(events.begin(), events.end(), [](auto &A, auto &B){
        if(A.first!=B.first) return A.first < B.first;
        return A.second < B.second;
    });
    int cur=0, mx=0;
    size_t i=0;
    while(i<events.size()){
        int t=events[i].first;
        int sum=0;
        while(i<events.size() && events[i].first==t){
            sum+=events[i].second;
            i++;
        }
        cur+=sum;
        mx=max(mx, cur);
    }
    cout<<mx<<"\n";
    return 0;
}
