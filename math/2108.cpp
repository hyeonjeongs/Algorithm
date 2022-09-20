#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

const int SCOPE = 4000; //입력되는 정수의 최대 절댓값

int findMode(int max_cnt, vector<int>& frequency) {
    //정렬된 벡터에서 최빈값을 찾아 반환하는 함수
    //최빈값이 여러 개라면 두번째로 작은 값을 반환
    int cnt = 0; int mode; // 최빈값 개수 count, 최빈값
    for (int i = 0; i < 2 * SCOPE + 1; i++) { // 최빈값 찾아내기
        if (max_cnt == frequency[i]) { //최빈값 갱신
            mode = i; //최빈값인 인덱스 저장
            cnt++; // 최빈값 2개까지 카운트
            if (cnt == 2) { //세번째 최빈값부터는 mode 값을 갱신하지 않음
                break;
            }
        }
    }
    return mode - SCOPE; //인덱스는 입력된 숫자 + 4000 이므로 4000을 빼준 값을 반환
}

int main() {
    int n;
    double sum = 0.0; //입력된 숫자의 합
    int max_freq = 0; //최빈값의 빈도수

    cin >> n; // 입력
    vector<int> v(n); //입력된 숫자를 저장할 벡터
    vector<int> frequency(2 * SCOPE + 1, 0); //각 숫자들(-4000~4000)의 빈도를 저장할 벡터 - 최빈값 구하기 위해

    for (int i = 0; i < n; i++) { //수 입력
        cin >> v[i]; //입력한 수 저장
        sum += v[i]; //입력한 수들의 합 저장

        int cur_freq = ++frequency[v[i] + SCOPE]; //인덱스 값이 음수가 안되게 유의하며 빈도수 갱신, 해당 빈도수를 cur_freq에 저장(current frequency)
        max_freq = max(max_freq, cur_freq); //최대 빈도수 갱신
    }
    sort(v.begin(), v.end()); //오름차순 정렬

    //출력
    cout << (int)round(sum / n) << '\n'; //산술평균: -0 안나오게 유의
    cout << v[n / 2] << '\n'; //중앙값
    cout << findMode(max_freq, frequency) << '\n'; //최빈값
    cout << v[n - 1] - v[0] << '\n'; //범위

    return 0;
}