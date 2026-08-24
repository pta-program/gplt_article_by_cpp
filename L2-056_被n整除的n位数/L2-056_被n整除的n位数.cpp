#include <bits/stdc++.h>
using namespace std;
int n;
long long A,B;
vector<long long> res;

void dfs(long long cur, int len){
    if(len==n){
        if(cur>=A && cur<=B) res.push_back(cur);
        return;
    }
    for(int d=0; d<=9; ++d){
        long long nxt = cur*10 + d;
        int nlen = len+1;
        if(nxt % nlen != 0) continue;
        // prune by range: if nxt with n digits prefix exceeds B's prefix? But we can prune via remaining digits max/min.
        // Estimate min/max possible final number with remaining digits (n - nlen) digits: [nxt *10^{rem}, nxt*10^{rem}+10^{rem}-1]
        int rem = n - nlen;
        long long pow10=1;
        for(int i=0;i<rem;i++) pow10*=10;
        long long mn = nxt * pow10;
        long long mx = mn + pow10 -1;
        if(mx < A || mn > B) {
            // still might be within? actually if interval doesn't overlap, skip this branch
            // but we can still skip only if completely outside
            if(mx < A || mn > B) continue;
        }
        dfs(nxt, nlen);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if(!(cin>>n>>A>>B)) return 0;
    res.reserve(100000);
    for(int d=1; d<=9; ++d){
        long long cur=d;
        if(cur %1 !=0) continue; // always 0
        // pruning for single digit prefix
        int rem=n-1;
        long long pow10=1;
        for(int i=0;i<rem;i++) pow10*=10;
        long long mn=cur*pow10;
        long long mx=mn+pow10-1;
        if(mx < A || mn > B){
            // still maybe skip? if out of range, no need dfs
            // but we check again inside, so skip early if completely outside
            if(n==1){ // not happen
            }
            // keep branch if may still intersect? Actually we already check
            if(mx < A || mn > B) {
                // if cur's possible range doesn't intersect [A,B], skip
                continue;
            }
        }
        dfs(cur,1);
    }
    sort(res.begin(), res.end());
    if(res.empty()){
        cout<<"No Solution\n";
    }else{
        for(long long x: res) cout<<x<<"\n";
    }
    return 0;
}
