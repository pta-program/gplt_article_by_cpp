#include <iostream>
using namespace std;

/**
 * L1-055 - 谁是赢家
 * 
 * 实现原理：
 * 根据规则判断赢家：
 * 1. 如果一位艺人的观众票数高，且得到至少1名评委的认可，该艺人胜出
 * 2. 如果艺人的观众票数低，但得到全部评委的认可，也可以胜出
 * 
 * 解题思路：
 * 1. 读取艺人a和艺人b的观众票数
 * 2. 读取3名评委的投票结果
 * 3. 统计每位艺人得到的评委票数
 * 4. 根据规则判断赢家
 * 5. 输出结果
 */
int main() {
    int Pa, Pb;
    cin >> Pa >> Pb;
    
    int judge_a = 0;  // 艺人a得到的评委票数
    int judge_b = 0;  // 艺人b得到的评委票数
    
    for (int i = 0; i < 3; i++) {
        int vote;
        cin >> vote;
        if (vote == 0) {
            judge_a++;
        } else {
            judge_b++;
        }
    }
    
    char winner;
    int winner_pa, winner_pb;
    
    if (Pa > Pb) {
        // 艺人a观众票数高
        if (judge_a >= 1) {
            winner = 'a';
            winner_pa = Pa;
            winner_pb = judge_a;
        } else {
            winner = 'b';
            winner_pa = Pb;
            winner_pb = judge_b;
        }
    } else {
        // 艺人b观众票数高
        if (judge_b >= 1) {
            winner = 'b';
            winner_pa = Pb;
            winner_pb = judge_b;
        } else {
            winner = 'a';
            winner_pa = Pa;
            winner_pb = judge_a;
        }
    }
    
    cout << "The winner is " << winner << ": " << winner_pa << " + " << winner_pb << endl;
    
    return 0;
}