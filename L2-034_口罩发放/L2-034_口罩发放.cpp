#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

/**
 * L2-034 - 口罩发放
 * 
 * 实现原理：
 * 根据规则筛选口罩发放名单。
 * 规则：
 * 1. 身份证号必须是18位数字
 * 2. 同一个身份证号两次获得口罩需间隔至少P天
 * 3. 按提交时间顺序发放
 * 
 * 解题思路：
 * 1. 读取每天的申请记录
 * 2. 验证身份证号
 * 3. 检查间隔时间
 * 4. 按时间排序发放
 * 5. 记录身体状况为1的申请人
 */
struct Application {
    string name;
    string id;
    int condition;
    string time;
    int index;
};

bool isValidID(const string& id) {
    if (id.size() != 18) return false;
    for (char c : id) {
        if (!isdigit(c)) return false;
    }
    return true;
}

bool compareTime(const Application& a, const Application& b) {
    if (a.time != b.time) {
        return a.time < b.time;
    }
    return a.index < b.index;
}

int main() {
    int D, P;
    cin >> D >> P;
    
    unordered_map<string, int> last_grant;
    unordered_map<string, bool> sick_recorded;
    vector<pair<string, string>> sick_people;
    
    for (int day = 1; day <= D; day++) {
        int T, S;
        cin >> T >> S;
        
        vector<Application> apps;
        
        for (int i = 0; i < T; i++) {
            string name, id, time;
            int condition;
            cin >> name >> id >> condition >> time;
            
            if (!isValidID(id)) continue;
            
            if (condition == 1 && !sick_recorded[id]) {
                sick_recorded[id] = true;
                sick_people.push_back({name, id});
            }
            
            apps.push_back({name, id, condition, time, i});
        }
        
        sort(apps.begin(), apps.end(), compareTime);
        
        int granted = 0;
        for (const Application& app : apps) {
            if (granted >= S) break;
            
            if (last_grant.find(app.id) != last_grant.end()) {
                int last_day = last_grant[app.id];
                if (day - last_day <= P) continue;
            }
            
            cout << app.name << " " << app.id << endl;
            last_grant[app.id] = day;
            granted++;
        }
    }
    
    for (const auto& p : sick_people) {
        cout << p.first << " " << p.second << endl;
    }
    
    return 0;
}