#include <iostream>
using namespace std;

/**
 * L1-063 - 吃鱼还是吃肉
 * 
 * 实现原理：
 * 根据宝宝的性别、身高、体重给出营养建议。
 * 标准数据：
 * - 男生：标准身高130厘米，标准体重27公斤
 * - 女生：标准身高129厘米，标准体重25公斤
 * 
 * 判断规则：
 * - 身高 < 标准身高：duo chi yu!（多吃鱼）
 * - 身高 == 标准身高：wan mei!（完美）
 * - 身高 > 标准身高：ni li hai!（你厉害）
 * - 体重 < 标准体重：duo chi rou!（多吃肉）
 * - 体重 == 标准体重：wan mei!（完美）
 * - 体重 > 标准体重：shao chi rou!（少吃肉）
 * 
 * 解题思路：
 * 1. 读取宝宝数量N
 * 2. 对每个宝宝：
 *    - 读取性别、身高、体重
 *    - 根据性别确定标准身高和体重
 *    - 评价身高和体重
 *    - 输出建议
 */
int main() {
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int gender, height, weight;
        cin >> gender >> height >> weight;
        
        int std_height, std_weight;
        
        if (gender == 1) {
            // 男生
            std_height = 130;
            std_weight = 27;
        } else {
            // 女生
            std_height = 129;
            std_weight = 25;
        }
        
        // 评价身高
        string height_comment;
        if (height < std_height) {
            height_comment = "duo chi yu!";
        } else if (height == std_height) {
            height_comment = "wan mei!";
        } else {
            height_comment = "ni li hai!";
        }
        
        // 评价体重
        string weight_comment;
        if (weight < std_weight) {
            weight_comment = "duo chi rou!";
        } else if (weight == std_weight) {
            weight_comment = "wan mei!";
        } else {
            weight_comment = "shao chi rou!";
        }
        
        cout << height_comment << " " << weight_comment << endl;
    }
    
    return 0;
}