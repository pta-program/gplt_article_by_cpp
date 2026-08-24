#include <bits/stdc++.h>
using namespace std;

struct PersonInfo{
    char gender='?';
    string father="";
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if(!(cin>>N)) return 0;
    unordered_map<string, PersonInfo> mp;
    mp.reserve(N*2);
    for(int i=0;i<N;i++){
        string first,last;
        cin>>first>>last;
        PersonInfo pi;
        pi.father = "";
        if(last.size()>=4 && last.substr(last.size()-4)=="sson"){
            pi.gender='m';
            pi.father = last.substr(0, last.size()-4);
        }else if(last.size()>=7 && last.substr(last.size()-7)=="sdottir"){
            pi.gender='f';
            pi.father = last.substr(0, last.size()-7);
        }else{
            pi.gender = last.back(); // 'm' or 'f'
            pi.father = "";
        }
        mp[first]=pi;
    }
    int M; cin>>M;
    for(int i=0;i<M;i++){
        string n1,s1,n2,s2;
        cin>>n1>>s1>>n2>>s2;
        // check existence by first name (as stored). Full name check? Use first name.
        auto it1 = mp.find(n1);
        auto it2 = mp.find(n2);
        if(it1==mp.end() || it2==mp.end()){
            cout<<"NA\n";
            continue;
        }
        char g1 = it1->second.gender;
        char g2 = it2->second.gender;
        if(g1==g2){
            cout<<"Whatever\n";
            continue;
        }
        // BFS for n1 ancestors up to 4 generations (0..3) : forbids if common ancestor within 4 steps (<4)
        unordered_map<string,int> anc1;
        queue<pair<string,int>> q;
        q.emplace(n1,0);
        anc1[n1]=0;
        while(!q.empty()){
            auto [name, d]=q.front(); q.pop();
            if(d>=3) continue; // keep distances 0..3, next would be 4 (outside forbidden)
            auto it = mp.find(name);
            if(it==mp.end()) continue;
            string f = it->second.father;
            if(f.empty()) continue;
            // record father even if not in mp (could be common ancestor)
            if(anc1.find(f)==anc1.end()){
                anc1[f]=d+1;
                if(mp.find(f)!=mp.end()) q.emplace(f,d+1);
                else {
                    // father not in map, no further expansion but keep as ancestor
                }
            }
        }
        bool found=false;
        // check n2 itself
        if(anc1.count(n2)) found=true;
        queue<pair<string,int>> q2;
        q2.emplace(n2,0);
        unordered_set<string> visited2;
        visited2.insert(n2);
        while(!q2.empty() && !found){
            auto [name,d]=q2.front(); q2.pop();
            if(d>=3) continue;
            auto it = mp.find(name);
            if(it==mp.end()) continue;
            string f = it->second.father;
            if(f.empty()) continue;
            if(anc1.count(f)){
                found=true; break;
            }
            if(visited2.count(f)) continue;
            visited2.insert(f);
            if(mp.find(f)!=mp.end()){
                q2.emplace(f,d+1);
            }
        }
        if(found) cout<<"No\n";
        else cout<<"Yes\n";
    }
    return 0;
}
