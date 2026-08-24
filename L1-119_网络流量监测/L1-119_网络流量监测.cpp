#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)) return 0;
    vector<long long> a(n);
    long long sum=0;
    long long mx = LLONG_MIN, mn = LLONG_MAX;
    for(int i=0;i<n;++i){cin>>a[i]; sum+=a[i]; mx=max(mx,a[i]); mn=min(mn,a[i]);}
    long long avg = sum / n;
    cout<<mx<<" "<<mn<<" "<<avg<<"\n";
    vector<int> pos;
    double thr = avg * 2.0; // visible "2倍" (hidden .9 ignored)
    for(int i=0;i<n;++i){
        if((double)a[i] > thr) pos.push_back(i+1);
    }
    if(pos.empty()){
        cout<<"Normal\n";
    }else{
        for(size_t i=0;i<pos.size();++i){
            if(i) cout<<' ';
            cout<<pos[i];
        }
        cout<<"\n";
    }
    return 0;
}
