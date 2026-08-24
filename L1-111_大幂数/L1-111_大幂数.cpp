#include <bits/stdc++.h>
using namespace std;
long long ipow(long long base, int exp){
    long long res=1;
    while(exp){
        if(exp&1) {
            if(res > (long long)4e18 / base) return (long long)4e18;
            res*=base;
        }
        exp>>=1;
        if(exp){
            if(base > (long long)4e18 / base) base = (long long)4e18;
            else base*=base;
        }
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    if(!(cin>>n)) return 0;
    // k max about 31, try descending to find maximal k
    for(int k=31;k>=1;--k){
        long long sum=0;
        int m=0;
        // estimate m upper bound: for this k, sum_{i=1}^m i^k <= n
        // m won't be large, for k=1 m~46340, for k=2 m~1290, for larger k smaller
        for(int cur=1;;++cur){
            long long pw = ipow(cur, k);
            if(pw > n) break; // sum will exceed anyway but need sum check
            if(sum > n - pw) break; // overflow/exceed
            sum += pw;
            if(sum==n){
                m=cur;
                break;
            }
            if(sum>n) break;
        }
        if(m>0){
            // found
            for(int i=1;i<=m;++i){
                if(i>1) cout<<'+';
                cout<<i<<'^'<<k;
            }
            cout<<"\n";
            return 0;
        }
        // If not found via incremental break due to pw > n, need to try larger m where pw may exceed? Actually sum already exceeds.
        // No need.
    }
    cout<<"Impossible for "<<n<<".\n";
    return 0;
}
