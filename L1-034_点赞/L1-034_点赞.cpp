#include <iostream>
using namespace std;

/**
 * L1-034 - 点赞
 * 
 * 实现原理：
 * 使用数组统计每个特性标签的出现次数。
 * 找到出现次数最多的标签，如果有并列则选择编号最大的。
 * 
 * 解题思路：
 * 1. 创建数组count[1001]，索引为标签编号，值为出现次数
 * 2. 读取N篇博文的特性描述
 * 3. 统计每个标签的出现次数
 * 4. 找到出现次数最多且编号最大的标签
 * 5. 输出结果
 */
int main() {
    int N;
    cin >> N;
    
    int count[1001] = {0};  // 标签编号从1到1000
    
    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;
        
        for (int j = 0; j < K; j++) {
            int tag;
            cin >> tag;
            count[tag]++;
        }
    }
    
    // 找到出现次数最多且编号最大的标签
    int max_count = 0;
    int max_tag = 0;
    
    for (int i = 1; i <= 1000; i++) {
        if (count[i] > max_count || (count[i] == max_count && i > max_tag)) {
            max_count = count[i];
            max_tag = i;
        }
    }
    
    cout << max_tag << " " << max_count << endl;
    
    return 0;
}