#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef pair<int,int> pi;
map<int,int> recommendNum;

int recommendPresident(int n, int input, vector<pi> &recommend, int num) {
    vector<int> order(2,0); // 오래된거
    int cnt=100000;

    if(recommend.size()<n) {
        recommend.push_back(pi(input, recommend.size()+1));
        recommendNum[input] = 1;
        num =1;
        return num;
    }

    // 추천수 가장 적은거 판단
    for(int i=0; i<n; i++) {
        if(recommend[i].second<cnt) {
            cnt = recommend[i].second;
        }
    }

    // 추천수 가장 적은것들중 가장 오래된것 판단
    for(int i=0; i<n; i++) {
        if(recommend[i].second == cnt && order[1] <recommendNum[recommend[i].first]) { // 추천수 같은경우 & 오래된경우
            order[0] = i;
            order[1] = recommendNum[recommend[i].first];
        }

    }

}

int main() {
    int n,m;

    cin>>n>>m;

    vector<pi> recommend(n);

    int num=0; //추천수

    for(int i=0; i<m; i++) {
        int input;
        cin>>input;
        num = recommendPresident(n,input, recommend, num);
    }

    for(int i=0; i<n; i++) {
        cout<<recommend[i].first<<' ';
    }

    return 0;
}