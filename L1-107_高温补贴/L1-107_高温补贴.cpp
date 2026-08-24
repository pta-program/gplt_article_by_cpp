#include <iostream>
using namespace std;
int main() {
    int T, S, t;
    if(!(cin >> T >> S >> t)) return 0;
    if (T >= 35 && t >= 33) {
        if (S == 1) {
            cout << "Bu Tie\n" << T << "\n";
        } else {
            cout << "Shi Nei\n" << T << "\n";
        }
    } else {
        if (S == 1) {
            cout << "Bu Re\n" << t << "\n";
        } else {
            cout << "Shu Shi\n" << t << "\n";
        }
    }
    return 0;
}
