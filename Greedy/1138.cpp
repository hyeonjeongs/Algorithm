# include <iostream>
# include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n,0);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    vector<int> result(n, 0);
    for (int i=0; i<n; i++) {
        int cnt =0;

        for (int j=0; j<n; j++) {
            if (result[j] == 0) {// 키큰 사람 배치 안돼서 이 경우에만 체크
                if (cnt == arr[i]) {
                    result[j] = i+1;
                    break;
                }
                cnt++;
            }

        }
    }
    for (int i=0; i<n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}