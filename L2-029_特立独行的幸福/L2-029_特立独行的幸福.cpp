#include <bits/stdc++.h>
using namespace std;

int square_sum(int n){
    int sum=0;
    while(n>0){ int d=n%10; sum+=d*d; n/=10; }
    return sum;
}
bool is_prime(int n){
    if(n<2) return false;
    for(int i=2;i*i<=n;i++) if(n%i==0) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int A,B;
    if(!(cin>>A>>B)) return 0;
    const int MAXV = 10000;
    vector<int> happy(MAXV+1, -1); // -1 unknown, 0 unhappy, 1 happy
    vector<int> depCnt(MAXV+1, 0); // number of steps to 1 (excluding self) if happy else 0
    happy[1]=1; depCnt[1]=0;
    // precompute happiness via DFS + memo
    function<int(int)> solve = [&](int x)->int{
        if(happy[x]!=-1) return happy[x];
        unordered_set<int> visited;
        vector<int> chain;
        int cur=x;
        while(true){
            if(cur==1){
                // all chain are happy
                // compute depCnt for chain
                // depCnt for 1 is 0, for others is distance to 1
                // chain contains x ... last before 1
                for(int i=(int)chain.size()-1;i>=0;--i){
                    int node = chain[i];
                    int nxt = (i+1 < (int)chain.size()) ? chain[i+1] : 1;
                    // nxt is next in chain or 1
                    happy[node]=1;
                    depCnt[node]= depCnt[nxt]+1;
                }
                happy[1]=1;
                return 1;
            }
            if(happy[cur]!=-1){
                if(happy[cur]==1){
                    // chain all happy, propagate
                    for(int i=(int)chain.size()-1;i>=0;--i){
                        int node = chain[i];
                        int nxt = (i+1 < (int)chain.size()) ? chain[i+1] : cur;
                        happy[node]=1;
                        depCnt[node]= depCnt[nxt]+1;
                    }
                    return 1;
                }else{
                    // unhappy, all chain unhappy
                    for(int n: chain) happy[n]=0;
                    return 0;
                }
            }
            if(visited.count(cur)){
                // loop -> unhappy
                for(int n: chain) happy[n]=0;
                // also mark nodes in loop as unhappy (they are in chain)
                return 0;
            }
            visited.insert(cur);
            chain.push_back(cur);
            cur = square_sum(cur);
            // safety to avoid infinite: if chain too long, but will loop
            if(chain.size()>1000){ // fallback
                for(int n: chain) if(happy[n]==-1) happy[n]=0;
                return 0;
            }
        }
    };

    for(int i=1;i<=MAXV;i++) if(happy[i]==-1) solve(i);

    vector<char> isIndependent(B+1, 1);
    // isIndependent indexed by value, but A..B may be up to 10000, B may be < A? assume A<B
    for(int i=A;i<=B;i++){
        if(happy[i]==1){
            int cur = square_sum(i);
            while(cur!=1){
                if(cur>=A && cur<=B && cur!=i){
                    isIndependent[cur]=0;
                }
                // if cur is unhappy? Actually chain of happy numbers only goes through happy nodes, but we still walk. For happy i, all intermediate are happy.
                cur = square_sum(cur);
                if(cur==i) break; // avoid loop (should not for happy)
            }
        }
    }

    bool found=false;
    for(int i=A;i<=B;i++){
        if(happy[i]==1 && isIndependent[i]){
            int indep = depCnt[i]; // steps to 1
            if(is_prime(i)) indep*=2;
            cout<<i<<" "<<indep<<"\n";
            found=true;
        }
    }
    if(!found) cout<<"SAD\n";
    return 0;
}
