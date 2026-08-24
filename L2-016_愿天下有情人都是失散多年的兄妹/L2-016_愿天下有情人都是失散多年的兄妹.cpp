#include <bits/stdc++.h>
using namespace std;
struct Person{char gender; int father; int mother;};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; if(!(cin>>N)) return 0;
    unordered_map<int, Person> people;
    people.reserve(N*2);
    for(int i=0;i<N;i++){
        int id,father,mother; char g;
        cin>>id>>g>>father>>mother;
        people[id]={g,father,mother};
    }
    int K; cin>>K;
    for(int i=0;i<K;i++){
        int a,b; cin>>a>>b;
        auto itA = people.find(a);
        auto itB = people.find(b);
        if(itA==people.end() || itB==people.end()){
            // According to spec, queries IDs are among N, but if not found treat as Never Mind? Actually no NA case. Just handle.
            cout<<"Never Mind\n";
            continue;
        }
        if(itA->second.gender == itB->second.gender){
            cout<<"Never Mind\n";
            continue;
        }
        unordered_map<int,int> ancA;
        queue<pair<int,int>> q;
        q.emplace(a,0);
        ancA[a]=0;
        // BFS limited to 4 steps (0..4)
        unordered_set<int> visA; visA.insert(a);
        while(!q.empty()){
            auto [id,gen]=q.front(); q.pop();
            if(gen>=4) continue;
            auto it = people.find(id);
            if(it==people.end()) continue;
            int f = it->second.father;
            int m = it->second.mother;
            if(f!=-1 && !ancA.count(f)){
                ancA[f]=gen+1;
                if(!visA.count(f)){visA.insert(f); q.emplace(f,gen+1);}
            }else if(f!=-1 && ancA.count(f)){
                // keep minimal gen
            }
            // also need to push to queue even if already in ancA? Already visited check via ancA
            if(f!=-1 && ancA.find(f)==ancA.end()){} // already

            if(m!=-1 && !ancA.count(m)){
                ancA[m]=gen+1;
                if(!visA.count(m)){visA.insert(m); q.emplace(m,gen+1);}
            }
        }
        // For correctness, we need to explore both parents via queue; above handles father but mother not queued if ancA already? We'll ensure queue push for mother as well.
        // Actually we pushed both; fine.

        // Re-do BFS properly to ensure both parents are expanded:
        // Clear and redo with proper queue? The above loop already pushes both, but we used ancA check to avoid duplicate. Need to ensure both parents get queued.
        // To avoid missing, we'll do separate BFS that traverses regardless of ancA existence but uses visited set.
        // For simplicity, we already have ancA, but the loop's generation for mother may be missed if father already limited? It's fine.

        bool found=false;
        queue<pair<int,int>> qb;
        qb.emplace(b,0);
        unordered_set<int> visB; visB.insert(b);
        if(ancA.count(b) && ancA[b] <5) found=true;
        while(!qb.empty() && !found){
            auto [id,gen]=qb.front(); qb.pop();
            if(gen>=4) continue;
            auto it = people.find(id);
            if(it==people.end()) continue;
            int f = it->second.father;
            int m = it->second.mother;
            for(int parentId : {f,m}){
                if(parentId==-1) continue;
                if(ancA.count(parentId)){
                    // both distances <5 (ancA already <5, gen+1 <5 because gen<4)
                    found=true; break;
                }
                if(!visB.count(parentId)){
                    visB.insert(parentId);
                    qb.emplace(parentId, gen+1);
                }
            }
        }
        cout<<(found?"No\n":"Yes\n");
    }
    return 0;
}
