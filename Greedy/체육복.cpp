//Pogrammers
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> clothes (n+2, 1); // 맨앞, 맨뒤 공간 만들어놓기
    for(auto i:lost){
        clothes[i]--;
    }
    for(auto i:reserve){
        clothes[i]++;
    }

    for(int i=1; i<=n; i++){
        if(clothes[i]>=1)
            continue;
        if(clothes[i-1]==2){
            clothes[i]++;
            clothes[i-1]--;
        }
        else if(clothes[i+1] == 2){
            clothes[i]++;
            clothes[i+1]--;
        }
    }
    for(int i=1; i<=n; i++){
        if(clothes[i]>=1)
            answer++;
    }

    return answer;
}

int main() {
    vector<int> lost = {2, 4};
    vector<int> reserve = {1, 3, 5};
    int n = 5;

    cout << solution(n, lost, reserve);
    return 0;
}