#include <iostream>
#include <cmath>
using namespace std;

/**
 * L1-031 - 到底是不是太胖了
 * 修复点：原代码 abs 用于 double 存在重载歧义，改为 fabs 明确浮点绝对值。
 */
int main() {
    int N;
    if (!(cin >> N)) return 0;
    for (int i = 0; i < N; ++i) {
        int H, W;
        cin >> H >> W;
        double standard = (H - 100) * 1.8;
        double diff = fabs(W - standard);
        if (diff < standard * 0.1) cout << "You are wan mei!\n";
        else if (W > standard) cout << "You are tai pang le!\n";
        else cout << "You are tai shou le!\n";
    }
    return 0;
}
