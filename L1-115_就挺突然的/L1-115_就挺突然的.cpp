#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long A,B;
    if(!(cin>>A>>B)) return 0;
    long long diff = B - A;
    cout<<diff<<"\n";
    if(diff>250) cout<<"jiu ting tu ran de...\n";
    else if(diff<=0) cout<<"hai sheng ma?\n";
    else cout<<"nin tai cong ming le!\n";
    return 0;
}
