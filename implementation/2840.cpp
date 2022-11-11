#include <iostream>
#include <vector>

using namespace std;

/*
  [실수했던 부분]
  isChecked 필요없다고 생각함
  이미 체크된것이 다른 바퀴에저장하려고 하면 저장 못하게 해야하므로 이미 사용했는지 체크하는 배열 필요함 !
 */

bool wheelSpin(char alpha, int current_position, vector<char> &wheel, vector<bool> &isChecked) {
    if(wheel[current_position] == alpha) // 이미 같은수 저장된 경우
        return true;

    if (wheel[current_position] != '?' || isChecked[alpha - 'A']){ // 글자 이미 저장되어 있거나, 다른 위치에 알파벳 쓰이고 있는 경우
        return false;
    }
    // 아직 글자 없고 알파벳 안쓰인 경우
    wheel[current_position] = alpha;
    isChecked[alpha- 'A'] = true;
    return true;
}

int main() {
    int n, k, num, current_position = 0; // 바퀴의 칸 수, 바퀴돌리는 횟수
    char alpha, result = '?';
    cin >> n >> k;
    vector<char> wheel(n, '?');
    vector<bool> isChecked(26, false);

    for (int i = 0; i < k; i++) {
        cin >> num >> alpha;
        current_position = (current_position + num) % n;

        // 행운의 숫자 아닌지 판단
        if (!wheelSpin(alpha, current_position, wheel, isChecked)) {
            result = '!';
            break;
        }
    }

    if (result == '!') {
        cout << "!" << '\n';
    } else {
        for (int i = n; i >0 ; i--)
            cout << wheel[(current_position + i) % n];
    }

    return 0;
}