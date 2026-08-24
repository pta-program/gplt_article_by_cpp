#include <iostream>
#include <string>
using namespace std;

/**
 * L1-005 - 考试座位号
 * 
 * 实现原理：
 * 使用数组建立试机座位号到考生信息的映射关系。
 * 由于座位号从1到N，可以直接用座位号作为数组下标，实现O(1)的查询效率。
 * 
 * 解题思路：
 * 1. 读取考生人数N
 * 2. 创建两个数组：一个存储准考证号，一个存储考试座位号
 *    数组下标即为试机座位号（从1开始）
 * 3. 读取N个考生信息，填充数组
 * 4. 读取待查询人数M和M个试机座位号
 * 5. 根据试机座位号直接从数组中获取对应的准考证号和考试座位号
 */
int main() {
    int N;
    cin >> N;
    
    // 创建数组存储考生信息，下标为试机座位号（1-based）
    string* id = new string[N + 1];
    int* exam_seat = new int[N + 1];
    
    // 读取N个考生信息
    for (int i = 0; i < N; i++) {
        string student_id;
        int test_seat, ex_seat;
        cin >> student_id >> test_seat >> ex_seat;
        
        // 以试机座位号为索引存储信息
        id[test_seat] = student_id;
        exam_seat[test_seat] = ex_seat;
    }
    
    // 读取查询信息
    int M;
    cin >> M;
    
    // 处理每个查询
    for (int i = 0; i < M; i++) {
        int query_seat;
        cin >> query_seat;
        
        // 根据试机座位号直接查询并输出
        cout << id[query_seat] << " " << exam_seat[query_seat] << endl;
    }
    
    // 释放动态分配的内存
    delete[] id;
    delete[] exam_seat;
    
    return 0;
}