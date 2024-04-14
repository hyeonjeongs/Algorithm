3 2 60
1 2 2
0 0 1
0 1 2
1 1 1 1 84
2 2 2 1 84
2 1
1 1
2 1
2 0
2 1
1 0
1 2
1 2
1 1
2 3
2 2
2 3
1 2
2 3
2 2
1 0
2 3
1 1
2 0
2 0
1 3
2 1
1 0
2 3
2 0
2 2
1 3
2 3
2 3
2 0
1 3
2 3
2 0
1 0
1 3
1 0
2 1
2 3
2 2
2 2
2 3
2 1
1 0
2 3
1 2
1 1
1 2
1 3
2 0
1 2
1 1
1 3
2 2
1 3
1 3
2 1
1 0
2 3
2 3
1 1









#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;
/*
 * 주사위 n개 있음, 주사위 6면에 각각 숫자 있음, 각 면이 나올 확률 동일함
 * A : 2/n개의 주사위, B : 2/n개
 * 나온 수들 모두 합해 더 큰 쪽이 승리, 같으면 무승부
 *
 * A는 자신이 승리할 확률이 높아지도록 주사위 가져감
 */
vector<int> max_comb; // 승개수, 무개수, 패개수, 쌍2개
vector<int> dice_a;
vector<int> dice_b;
int n;

void calculateDiceSumA(vector<vector<int>> dice, int index, int sum) {
    if(index == n/2) {
        dice_a.push_back(sum);
        return;
    }
    for(int i=0; i<6; i++) {
        calculateDiceSumA(dice, index+1, sum+dice[index][i]);
    }
}
void calculateDiceSumB(vector<vector<int>> dice, int index, int sum) {
    if(index == n/2) {
        dice_b.push_back(sum);
        return;
    }
    for(int i=0; i<6; i++) {
        calculateDiceSumB(dice, index+1, sum+dice[index][i]);
    }
}

int compareDices() {
    int win=0, equal=0, fail=0;
    for(int i=0; i<dice_a.size(); i++) {
        for(int j=0; j<dice_b.size(); j++) {
            if(dice_a[i] > dice_b[i]) {
                win++;
            }else if(dice_a[i] < dice_b[i]) {
                fail++;
            } else {
                equal++;
            }
        }
    }
    return win;
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    vector<int> dice_permutation(dice.size(),0);
    max_comb.assign(10,0);

    n = dice.size();

    iota(dice_permutation.begin(), dice_permutation.end(),1);

    do {
        vector<vector<int>> dice1;
        vector<vector<int>> dice2;

        for(int i=0; i<dice_permutation.size()/2; i++) {
            dice1.push_back(dice[dice_permutation[i]]);
            dice2.push_back(dice[dice_permutation[dice_permutation.size()/2+i]]);
        }

        calculateDiceSumA(dice1, 0, 0);
        calculateDiceSumB(dice2, 0,0);

        int win_number = compareDices();
        if(win_number>max_comb[0]) {
            max_comb[0] = win_number;
            for(int i=0; i<dice_permutation.size()/2; i++) {
                max_comb[i+1] = dice_permutation[i];
            }
        }
        dice1.clear();
        dice2.clear();

    } while(next_permutation(dice_permutation.begin(), dice_permutation.end()));

    for(int i=1; i<=n/2; i++) {
        answer.push_back(max_comb[i]);
    }
    return answer;

}