/**
 * 시간 : 120분
 * 어려운 부분 : 처음에 이모티콘 할인 비율 완전탐색으로 구현하는 법 -> (n과 m) 처럼 하는 부분 잊음
 * 완전탐색 좀 더 공부해야할듯
 *
 * 수열, 조합, 중복수열에 따라 visited 구분하는데 이부분 좀 더 공부
 */

#include <string>
#include <vector>

using namespace std;

int discount[4] = {40,30,20,10};
vector<vector<int>> global_users;
vector<int> global_emoticons;
int sizes;
vector<int> rates;
vector<int> answer;

void calcRate(int index) {
    if(index == sizes) {
        int max_price =0;
        int max_buy =0;

        for(int i=0; i<global_users.size(); i++) {
            int user_price = 0;

            for(int j=0; j<rates.size(); j++) {
                if(global_users[i][0]<=discount[rates[j]]) {
                    user_price += global_emoticons[j] * (100.0 - discount[rates[j]])/100;
                }
            }

            if(user_price>=global_users[i][1]) {
                max_buy++;
            } else {
                max_price += user_price;
            }
        }
        if(answer[0]<max_buy) {
            answer[0] = max_buy;
            answer[1] = max_price;
        } else if(answer[0] == max_buy && answer[1] < max_price) {
            answer[0] = max_buy;
            answer[1] = max_price;
        }

    } else {
        for(int i=0; i<4; i++) {
            rates[index] = i;
            calcRate(index+1);
        }
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {

    answer.assign(2,0);
    sizes = emoticons.size();
    rates.assign(sizes, -1);

    global_users= users;
    global_emoticons = emoticons;

    calcRate(0);

    return answer;
}