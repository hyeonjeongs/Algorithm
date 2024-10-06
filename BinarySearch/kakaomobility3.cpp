#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int solution(vector<int> &D, vector<string> &T) {
    vector<vector<int>> house(T.size(), vector<int>(3,0));
    vector<int> truck(3,0); // 0: 플라스틱, 1: 유리, 2: 금속
    int total = 0;

    for(int i=0; i< T.size(); i++) {
        string trash_str= T[i];
        for(int j=0; j<trash_str.length(); j++) {
            total++;
            if(trash_str[j]=='P') {
                house[i][0]++;
                truck[0]++;
            }else if(trash_str[j]=='G') {
                house[i][1]++;
                truck[1]++;
            }else if(trash_str[j]=='M') {
                house[i][2]++;
                truck[2]++;
            }
        }
    }

    int result= 0;

    if(total == 0){
        return 0;
    }

    for(int i=0; i<3; i++) { // 플라 - 유리 - 금속
        int dist = 0;
        int trash_cnt =0;
        for(int j=0; j<house.size(); j++) { // 집 방문
            dist += D[j];

            if(house[j][i]>0) {
                truck[i] -= house[j][i];
                trash_cnt += house[j][i];
            }

            if(truck[i] == 0) {
                dist = dist*2 + trash_cnt;
                break;
            }
        }
        result = max(result, dist);
    }
    return result;
}
