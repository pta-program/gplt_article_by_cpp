#include <iostream>
#include <iomanip>
using namespace std;

/**
 * L1-061 - 新胖子公式
 * 
 * 实现原理：
 * 根据BMI公式计算肥胖指数：BMI = 体重(kg) / 身高(m)^2
 * 如果BMI > 25，则是胖子。
 * 
 * 解题思路：
 * 1. 读取体重和身高
 * 2. 计算BMI
 * 3. 输出BMI值，保留1位小数
 * 4. 根据BMI值判断是否是胖子
 */
int main() {
    double weight, height;
    cin >> weight >> height;
    
    // 计算BMI
    double bmi = weight / (height * height);
    
    // 输出BMI值，保留1位小数
    cout << fixed << setprecision(1) << bmi << endl;
    
    // 判断是否是胖子
    if (bmi > 25) {
        cout << "PANG" << endl;
    } else {
        cout << "Hai Xing" << endl;
    }
    
    return 0;
}