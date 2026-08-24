#include <iostream>
#include <string>
using namespace std;

/**
 * L1-018 - 大笨钟
 * 修复点：原代码对 12:00 误判为敲钟时段。
 * 根据题意 00:00~12:00（含端点）不敲钟，12:00 应输出 Only ...。
 * 敲钟时段为 12:01~23:59，正点敲 hh%12，过了整点敲 (hh+1)%12。
 */
int main() {
    string t;
    if (!(cin >> t)) return 0;
    int hh = stoi(t.substr(0, 2));
    int mm = stoi(t.substr(3, 2));

    // 00:00 ~ 12:00（含12:00）不敲
    if (hh < 12 || (hh == 12 && mm == 0)) {
        cout << "Only " << t << ".  Too early to Dang." << endl;
    } else {
        // 有效整点：过了整点算下一小时
        int eff = hh + (mm > 0 ? 1 : 0);
        int dang = eff - 12;               // 12:01->1, ..., 23:00->11, 23:01->12
        if (dang <= 0) dang += 12;         // 兜底（理论上不会出现）
        // 兼容 24 的表示：若 eff==24，dang=12 正确
        for (int i = 0; i < dang; ++i) cout << "Dang";
        cout << endl;
    }
    return 0;
}
