#include <iostream>
#include <vector>

using namespace std;

vector<int> changeSwitch(vector<int> switches, vector<pair<int, int>> students, int n, int m) {

    for (int i = 0; i < m; i++) {
        int num = students[i].second;
        if (students[i].first == 1) { // 남자인 경우 -> 본인 번호의 배수면 변경
            for (int j = num; j <= n; j += num) {
                switches[j] = !switches[j];
            }
        } else { // 여자인 경우 -> 좌우 대칭
            switches[num] = (switches[num] + 1) % 2;
            for (int j = 1; j <= n; j++) {
                if(num + j > n || num - j < 1 || switches[num + j] != switches[num - j]) //끝점 인경우 || 대칭 아닌 경우 break
                    break;
                if (switches[num + j] == switches[num - j]) { // 대칭인 경우
                    switches[num + j] = !switches[num +j];
                    switches[num - j] = !switches[num -j];
                }
            }
        }
    }
    return switches;
}

int main() {
    int n, m; //스위치 개수, 학생 수
    cin >> n;
    vector<int> switches(n + 1, 0);

    //스위치 상태 입력 받기
    for (int i = 1; i <= n; i++) {
        cin >> switches[i];
    }

    cin >> m;
    vector<pair<int, int>> students(m);
    for (int i = 0; i < m; i++) {
        cin >> students[i].first >> students[i].second;
    }

    switches = changeSwitch(switches, students, n, m);
    for (int i = 1; i <= n; i++) {
        cout << switches[i] << ' ';
        if(i%20==0)
            cout<<'\n';
    }

    return 0;
}