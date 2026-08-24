#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M;
    if(!(cin>>N>>M)) return 0;
    vector<int> a(N);
    for(int i=0;i<N;++i) cin>>a[i];
    for(int opIdx=0; opIdx<M; ++opIdx){
        int type; cin>>type;
        if(type==1){
            int L1; cin>>L1;
            vector<int> pat1(L1);
            for(int i=0;i<L1;++i) cin>>pat1[i];
            int L2; cin>>L2;
            vector<int> pat2(L2);
            for(int i=0;i<L2;++i) cin>>pat2[i];
            // find first occurrence of pat1 in a
            int pos=-1;
            if((int)a.size() >= L1){
                for(size_t i=0;i+L1<=a.size();++i){
                    bool ok=true;
                    for(int j=0;j<L1;++j) if(a[i+j]!=pat1[j]){ok=false;break;}
                    if(ok){pos=(int)i;break;}
                }
            }
            if(pos!=-1){
                vector<int> b;
                b.reserve(a.size()-L1+L2);
                b.insert(b.end(), a.begin(), a.begin()+pos);
                b.insert(b.end(), pat2.begin(), pat2.end());
                b.insert(b.end(), a.begin()+pos+L1, a.end());
                a.swap(b);
            }
        }else if(type==2){
            // insert average between adjacent if sum even
            if(a.size()>=2){
                vector<int> b;
                b.reserve(a.size()*2);
                for(size_t i=0;i<a.size();++i){
                    b.push_back(a[i]);
                    if(i+1<a.size() && ((a[i]+a[i+1])%2==0)){
                        b.push_back((a[i]+a[i+1])/2);
                    }
                }
                a.swap(b);
            }
        }else if(type==3){
            int l,r; cin>>l>>r;
            // 1-indexed
            if(l>=1 && r<= (int)a.size() && l<=r){
                reverse(a.begin()+l-1, a.begin()+r);
            }
        }
    }
    for(size_t i=0;i<a.size();++i){
        if(i) cout<<' ';
        cout<<a[i];
    }
    if(!a.empty()) cout<<"\n";
    return 0;
}
