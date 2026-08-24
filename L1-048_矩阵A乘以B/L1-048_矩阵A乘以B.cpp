#include <iostream>
using namespace std;

/**
 * L1-048 - 矩阵A乘以B
 * 
 * 实现原理：
 * 矩阵乘法规则：
 * 如果A是R_a行C_a列，B是R_b行C_b列，则：
 * - 只有C_a == R_b时才能相乘
 * - 结果矩阵是R_a行C_b列
 * - 结果矩阵的元素C[i][j] = sum(A[i][k] * B[k][j])，其中k从0到C_a-1
 * 
 * 解题思路：
 * 1. 读取矩阵A的行数R_a和列数C_a
 * 2. 读取矩阵A的元素
 * 3. 读取矩阵B的行数R_b和列数C_b
 * 4. 读取矩阵B的元素
 * 5. 检查是否可以相乘（C_a == R_b）
 * 6. 如果可以，计算乘积矩阵并输出
 * 7. 如果不可以，输出错误信息
 */
int main() {
    int Ra, Ca;
    cin >> Ra >> Ca;
    
    // 读取矩阵A
    int A[100][100];
    for (int i = 0; i < Ra; i++) {
        for (int j = 0; j < Ca; j++) {
            cin >> A[i][j];
        }
    }
    
    int Rb, Cb;
    cin >> Rb >> Cb;
    
    // 读取矩阵B
    int B[100][100];
    for (int i = 0; i < Rb; i++) {
        for (int j = 0; j < Cb; j++) {
            cin >> B[i][j];
        }
    }
    
    // 检查是否可以相乘
    if (Ca != Rb) {
        cout << "Error: " << Ca << " != " << Rb << endl;
        return 0;
    }
    
    // 计算乘积矩阵
    int result[100][100] = {0};
    for (int i = 0; i < Ra; i++) {
        for (int j = 0; j < Cb; j++) {
            for (int k = 0; k < Ca; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    // 输出结果矩阵
    cout << Ra << " " << Cb << endl;
    for (int i = 0; i < Ra; i++) {
        for (int j = 0; j < Cb; j++) {
            if (j > 0) {
                cout << " ";
            }
            cout << result[i][j];
        }
        cout << endl;
    }
    
    return 0;
}