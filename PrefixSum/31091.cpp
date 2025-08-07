#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> ll(n+1, 0); // 이하
    vector<int> lm(n+1, 0); // 이상

    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        if(input<=0) {
            ll[-input]++;
        }else {
            lm[input]++;
        }
    }

    vector<int> lls(n+1, 0);
    vector<int> lms(n+1, 0);
    lls[0] = ll[0];
    lms[0] = lm[0];
    for(int i=1; i<=n; i++) {
        lls[i] = lls[i-1] + ll[i];
        lms[i] = lms[i-1] + lm[i];
    }

    vector<int> answer;
    if((lms[n]-lms[0]) == 0) {
        answer.push_back(0);
    }
    for(int i=1; i<=n; i++) {
        int result = lls[i-1] + (lms[n]-lms[i]);
        if(result == i) {
            answer.push_back(i);
        }
    }

    cout << answer.size()<< '\n';
    for(int i=0; i<answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << '\n';

    return 0;
}