#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if(!(cin>>N)) return 0;
    string S;
    cin>>S;
    string T=S;
    for(int i=0;i<N;++i){
        int op; cin>>op;
        if(op==1){
            string s1; cin>>s1;
            vector<int> pos;
            // allow overlapping, find first 3
            for(size_t p=0; p + s1.size() <= T.size(); ++p){
                if(T.compare(p, s1.size(), s1)==0){
                    pos.push_back((int)p);
                    if((int)pos.size()==3) break;
                }
            }
            if(pos.empty()){
                cout<<-1<<"\n";
            }else{
                for(size_t j=0;j<pos.size();++j){
                    if(j) cout<<' ';
                    cout<<pos[j];
                }
                cout<<"\n";
            }
        }else if(op==2){
            int p; string s2; cin>>p>>s2;
            char ch = s2.empty()? '?' : s2[0];
            if(p<0) p=0;
            if(p>(int)T.size()) p=T.size();
            T.insert(T.begin()+p, ch);
            cout<<T<<"\n";
        }else if(op==3){
            int l,r; cin>>l>>r;
            if(l<0) l=0;
            if(r>=(int)T.size()) r=(int)T.size()-1;
            if(l<=r) reverse(T.begin()+l, T.begin()+r+1);
            cout<<T<<"\n";
        }
    }
    return 0;
}
