#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
/*
 * 1. 서로 선물 주고 받은 경우
 *  선물 더 많이 준애가 받기
 * 2. 서로 주고 받은 기록 없는 경우
 *  선물 지수 큰사람이 받기 (선물 지수 = 준 선물 - 받은 선물)
 * -> 선물 가장 많이 받은 친구가 받은 선물 수
 *
 * gift -> [선물 준 친구, 선물 받은 친구]
 */

int exchangeGift(vector<string> friends, map<string, int> friend_index, vector<vector<int>> exchange,vector<vector<int>> gift_number) {
    vector<int> result_gift(friends.size(), 0);

    int friend1_index, friend2_index;
    int friend1_give_number, friend2_give_number;

    for(int i=0; i<friends.size()-1; i++) {
        for(int j=i+1; j<friends.size(); j++) {
            friend1_index = friend_index[friends[i]];
            friend2_index = friend_index[friends[j]];

            friend1_give_number = exchange[friend1_index][friend2_index];
            friend2_give_number = exchange[friend2_index][friend1_index];

            if(friend1_give_number==0 && friend2_give_number==0 || friend1_give_number== friend2_give_number) {
                int friend1_number, friend2_number; // 지수
                friend1_number = gift_number[friend1_index][0] - gift_number[friend1_index][1];
                friend2_number = gift_number[friend2_index][0] - gift_number[friend2_index][1];
                if(friend1_number>friend2_number) {
                    result_gift[friend1_index]++;
                } else if (friend1_number<friend2_number){
                    result_gift[friend2_index]++;
                }
            }
            if(friend1_give_number> friend2_give_number) {
                result_gift[friend1_index]++;
            }
            if(friend1_give_number< friend2_give_number) {
                result_gift[friend2_index]++;
            }
        }
    }

    sort(result_gift.begin(), result_gift.end(), greater<>());
    return result_gift[0];
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    map<string, int> friend_index;
    vector<vector<int>> exchange(friends.size(), vector<int>(friends.size(),0));
    vector<vector<int>> gift_number(friends.size(), vector<int>(2,0));

    for(int i=0; i<friends.size(); i++) {
        friend_index[friends[i]] = i;
    }

    for(int i=0; i<gifts.size(); i++) {
        string sender, receiver;
        int row, col;
        istringstream ss(gifts[i]);
        ss.str();
        ss>>sender>>receiver;

        row = friend_index[sender];
        col = friend_index[receiver];

        exchange[row][col]++;
        gift_number[row][0]++;
        gift_number[col][1]++;
    }

    answer = exchangeGift(friends, friend_index, exchange, gift_number);

    return answer;
}