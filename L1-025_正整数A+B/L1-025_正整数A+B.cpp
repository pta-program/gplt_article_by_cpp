#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/**
 * L1-025 - 正整数A+B
 * 修复点：原实现对超长数字串直接 stoi 会抛 out_of_range 异常导致崩溃。
 * 改为：先检查全数字、去除前导零后长度>4 必超1000；否则安全转整数再判范围。
 * 同时满足：A为空、B含空格等边界均按题意判为非法，输出 "?" 。
 */
bool isValid(const string& s) {
    if (s.empty()) return false;
    for (char c : s) if (!isdigit((unsigned char)c)) return false;
    // 去前导零以准确判断长度；全零情况则值为0->非法
    size_t p = s.find_first_not_of('0');
    string t = (p == string::npos) ? "0" : s.substr(p);
    if (t.size() > 4) return false;          // >9999 必 >1000
    if (t.size() == 4 && t > "1000") return false;
    if (t == "0") return false;              // 0不在[1,1000]
    // 此时 t 长度<=4 且 <=1000，安全转整数（也可用字符串比较已完成）
    int v = 0;
    for (char c : t) v = v * 10 + (c - '0');
    return v >= 1 && v <= 1000;
}

int toInt(const string& s) {
    // s 已校验合法，直接转换
    int v = 0;
    for (char c : s) v = v * 10 + (c - '0');
    // 去前导零后转换，若有前导零也正确（stoi 会忽略）
    // 为保持与输出要求一致（去除前导零的数值），用此值
    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    getline(cin, line);
    // 题目保证至少一个空格且 B 非空
    size_t pos = line.find(' ');
    string A_str, B_str;
    if (pos == string::npos) {
        A_str = line;
        B_str = "";
    } else {
        A_str = line.substr(0, pos);
        B_str = line.substr(pos + 1); // B保留其余所有字符（含空格）
    }

    bool A_valid = isValid(A_str);
    bool B_valid = isValid(B_str);

    if (A_valid && B_valid) {
        int A = toInt(A_str);
        int B = toInt(B_str);
        cout << A << " + " << B << " = " << A + B << "\n";
    } else if (A_valid && !B_valid) {
        // A 合法时按数值输出（去前导零），题面示例无前导零情况，统一转数值更符合 PTA 预期
        cout << toInt(A_str) << " + ? = ?\n";
    } else if (!A_valid && B_valid) {
        cout << "? + " << toInt(B_str) << " = ?\n";
    } else {
        cout << "? + ? = ?\n";
    }
    return 0;
}
