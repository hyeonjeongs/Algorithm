/**
 * 그리디, deque 문제
 **/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    int n, m;
    cin >> n >>m;
    deque<int> deqs;
    int result = 0;

    for (int i=1; i<=n; i++) {
        deqs.push_back(i);
    }

    for (int i=0; i<m; i++) {
        int input;
        cin >> input;

        int index = 0;
        for (int j=0; j<deqs.size(); j++) {
            if (deqs[j] == input) {
                index = j;
                break;
            }
        }
        int backs = deqs.size() - index;

        if (index <=backs) {
            result+=index;
            while (index--) {
                deqs.push_back(deqs.front());
                deqs.pop_front();
            }

        } else {
            result+=backs;
            while (backs--) {
                deqs.push_front(deqs.back());
                deqs.pop_back();
            }

        }
        deqs.pop_front();

    }
    cout << result << '\n';

    return 0;
}