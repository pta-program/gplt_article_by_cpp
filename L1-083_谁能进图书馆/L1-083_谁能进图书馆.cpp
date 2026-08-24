#include <iostream>
using namespace std;

/**
 * L1-083 - 谁能进图书馆
 * 
 * 实现原理：
 * 判断两位询问者能否进入图书馆。
 * 规则：年龄 < 禁入年龄线的儿童禁止入馆，除非有 >= 陪同年龄线的成人陪同。
 * 
 * 解题思路：
 * 1. 判断每个人能否单独进入
 * 2. 判断是否需要陪同
 * 3. 根据情况输出结果
 */
int main() {
    int ban_age, accompany_age, age1, age2;
    cin >> ban_age >> accompany_age >> age1 >> age2;
    
    bool can_enter1 = (age1 >= ban_age);
    bool can_enter2 = (age2 >= ban_age);
    
    bool has_accompany = (age1 >= accompany_age) || (age2 >= accompany_age);
    
    bool need_together = false;
    
    if (!can_enter1 && !can_enter2) {
        if (has_accompany) {
            // 两个都是小孩，但有陪同者
            can_enter1 = true;
            can_enter2 = true;
            need_together = true;
        }
    } else if (!can_enter1) {
        if (age2 >= accompany_age) {
            can_enter1 = true;
            need_together = true;
        }
    } else if (!can_enter2) {
        if (age1 >= accompany_age) {
            can_enter2 = true;
            need_together = true;
        }
    }
    
    // 第一行输出
    cout << age1 << "-" << (can_enter1 ? "Y" : "N") << " ";
    cout << age2 << "-" << (can_enter2 ? "Y" : "N") << endl;
    
    // 第二行输出
    if (need_together) {
        int accompany_person = (age1 >= accompany_age) ? 1 : 2;
        int child_person = (accompany_person == 1) ? 2 : 1;
        cout << "qing " << accompany_person << " zhao gu hao " << child_person << endl;
    } else if (can_enter1 && can_enter2) {
        cout << "huan ying ru guan" << endl;
    } else if (!can_enter1 && !can_enter2) {
        cout << "zhang da zai lai ba" << endl;
    } else {
        int can_person = can_enter1 ? 1 : 2;
        cout << can_person << ": huan ying ru guan" << endl;
    }
    
    return 0;
}