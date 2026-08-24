#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)) return 0;
    unordered_map<int, vector<int>> mp;
    // also track all ids
    unordered_map<int,int> has0, has1;
    for(int i=0;i<n;++i){
        int id, rec; cin>>id>>rec;
        if(rec==0) has0[id]=1;
        else has1[id]=1;
    }
    vector<int> ans;
    for(auto &p: has0){
        int id=p.first;
        if(has1.find(id)==has1.end()){
            ans.push_back(id);
        }
    }
    if(ans.empty()){
        cout<<"NONE\n";
    }else{
        sort(ans.begin(), ans.end());
        for(size_t i=0;i<ans.size();++i){
            if(i) cout<<' ';
            cout<<ans[i];
        }
        cout<<"\n";
    }
    return 0;
}
