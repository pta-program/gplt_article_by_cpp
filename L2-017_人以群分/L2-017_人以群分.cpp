#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * L2-017 - 人以群分
 * 
 * 实现原理：
 * 将人群分为外向型和内向型，要求：
 * 1. 两类人群规模尽可能接近
 * 2. 总活跃度差距尽可能大
 * 
 * 解题思路：
 * 1. 将活跃度排序
 * 2. 将较小的一半分配给内向型，较大的一半分配给外向型
 * 3. 如果人数是奇数，外向型多一人
 */
int main() {
    int N;
    cin >> N;
    
    vector<int> activity(N);
    for (int i = 0; i < N; i++) {
        cin >> activity[i];
    }
    
    sort(activity.begin(), activity.end());
    
    int n2 = N / 2;
    int n1 = N - n2;
    
    long long sum1 = 0, sum2 = 0;
    for (int i = 0; i < n2; i++) {
        sum2 += activity[i];
    }
    for (int i = n2; i < N; i++) {
        sum1 += activity[i];
    }
    
    cout << "Outgoing #: " << n1 << endl;
    cout << "Introverted #: " << n2 << endl;
    cout << "Diff = " << (sum1 - sum2) << endl;
    
    return 0;
}