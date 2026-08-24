#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)) return 0;
    long long cnt=0;
    for(int i=0;i<n;++i){
        int x; cin>>x;
        if(x < 1700) cnt++; // visible text "低于1700" (hidden '不' ignored)
    }
    cout<<cnt<<"\n";
    return 0;
}
