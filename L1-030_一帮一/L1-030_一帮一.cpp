#include <iostream>
#include <string>
using namespace std;

/**
 * L1-030 - 一帮一
 * 
 * 实现原理：
 * 使用双指针法进行分组：
 * 1. 左指针从数组开头开始（名次最高）
 * 2. 右指针从数组末尾开始（名次最低）
 * 3. 找到与左指针指向学生性别不同的右指针位置
 * 4. 配对这两个学生，然后移动指针继续寻找下一对
 * 
 * 解题思路：
 * 1. 读取学生人数N和N个学生信息（性别+姓名）
 * 2. 使用双指针法从两端向中间配对：
 *    - 左指针i从0开始
 *    - 右指针j从N-1开始
 *    - 找到与students[i]性别不同的students[j]
 *    - 输出配对结果
 *    - 移动指针继续配对
 */
int main() {
    int N;
    cin >> N;
    
    // 存储学生信息：性别和姓名
    int gender[50];
    string name[50];
    
    for (int i = 0; i < N; i++) {
        cin >> gender[i] >> name[i];
    }
    
    // 双指针法配对
    int i = 0;      // 左指针，从名次最高开始
    int j = N - 1;  // 右指针，从名次最低开始
    
    while (i < j) {
        // 找到与当前左指针学生性别不同的右指针学生
        while (i < j && gender[j] == gender[i]) {
            j--;
        }
        
        // 输出配对结果
        cout << name[i] << " " << name[j] << endl;
        
        // 移动指针
        i++;
        j--;
    }
    
    return 0;
}