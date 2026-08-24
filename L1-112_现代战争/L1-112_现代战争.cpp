#include <bits/stdc++.h>
using namespace std;
struct Cell{int val; int r,c;};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;
    if(!(cin>>n>>m>>k)) return 0;
    vector<vector<int>> a(n, vector<int>(m));
    vector<Cell> cells;
    cells.reserve((size_t)n*m);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>a[i][j];
            cells.push_back({a[i][j], i, j});
        }
    }
    sort(cells.begin(), cells.end(), [](const Cell& x, const Cell& y){return x.val>y.val;});
    vector<char> delR(n,0), delC(m,0);
    int bomb=0;
    size_t idx=0;
    while(bomb<k && idx<cells.size()){
        int r=cells[idx].r, c=cells[idx].c;
        ++idx;
        if(delR[r] || delC[c]) continue;
        delR[r]=1;
        delC[c]=1;
        ++bomb;
    }
    vector<int> remR, remC;
    for(int i=0;i<n;++i) if(!delR[i]) remR.push_back(i);
    for(int j=0;j<m;++j) if(!delC[j]) remC.push_back(j);
    for(size_t i=0;i<remR.size();++i){
        for(size_t j=0;j<remC.size();++j){
            if(j) cout<<' ';
            cout<<a[remR[i]][remC[j]];
        }
        if(i+1<remR.size()) cout<<"\n";
    }
    if(!remR.empty()) cout<<"\n";
    return 0;
}
