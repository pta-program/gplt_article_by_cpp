#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

/**
 * L2-042 - 老板的作息表
 * 
 * 实现原理：
 * 找出作息表中未列出的时间段。
 * 规则：
 * 1. 输入时间段按时间顺序排列
 * 2. 找出未覆盖的区间
 * 
 * 解题思路：
 * 1. 将时间转换为秒数便于比较
 * 2. 排序时间段
 * 3. 找出相邻时间段之间的空隙
 * 4. 处理首尾边界
 */
struct TimeInterval {
    int start;
    int end;
};

int time_to_seconds(const string& time) {
    int hh, mm, ss;
    sscanf(time.c_str(), "%d:%d:%d", &hh, &mm, &ss);
    return hh * 3600 + mm * 60 + ss;
}

void seconds_to_time(int sec, string& time) {
    char buf[10];
    sprintf(buf, "%02d:%02d:%02d", sec / 3600, (sec % 3600) / 60, sec % 60);
    time = buf;
}

bool compare(const TimeInterval& a, const TimeInterval& b) {
    return a.start < b.start;
}

int main() {
    int N;
    cin >> N;
    
    vector<TimeInterval> intervals(N);
    
    for (int i = 0; i < N; i++) {
        string start_str, end_str, dash;
        cin >> start_str >> dash >> end_str;
        
        intervals[i].start = time_to_seconds(start_str);
        intervals[i].end = time_to_seconds(end_str);
    }
    
    sort(intervals.begin(), intervals.end(), compare);
    
    int prev_end = 0;
    
    for (const TimeInterval& interval : intervals) {
        if (interval.start > prev_end) {
            string start_time, end_time;
            seconds_to_time(prev_end, start_time);
            seconds_to_time(interval.start, end_time);
            cout << start_time << " - " << end_time << endl;
        }
        prev_end = max(prev_end, interval.end);
    }
    
    if (prev_end < 23 * 3600 + 59 * 60 + 59) {
        string start_time, end_time;
        seconds_to_time(prev_end, start_time);
        end_time = "23:59:59";
        cout << start_time << " - " << end_time << endl;
    }
    
    return 0;
}