#include<iostream>
#include<string>
using namespace std;

int calculateCharge(int h, int m, int time) {
    int ans = 0; //요금

    while (time--) {
        if (h >= 7 && h < 19) { //시간이 7~19까지 일경우
            ans += 10; // 1분에 10원
        }
        else {
            ans += 5; // 1분에 5원
        }
        
        h += (++m / 60) % 24; // 1분 더했을때 시간으로 넘어가는지
        m %= 60; //시간으로 넘어간경우 분 변경
    }
    return ans; // 값 반환
}

int main() {
    int n, m, time;
    int charge = 0; //요금
    string h; // 전화 건 시간

    cin >> n; // 전화건 횟수

    while(n--){
        getline(cin, h, ':'); //구분자 : 까지 시간 저장
        cin >> m >> time; //분과 통화 시간 저장
        charge += calculateCharge(stoi(h),m,time); // 요금 계산하기
    }

    cout << charge; //요금 출력
}