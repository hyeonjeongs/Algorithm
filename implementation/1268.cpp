#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> students(n, vector<int>(6,0));
    vector<set<int>> same_class(n, set<int>());

    for(int i=0; i<n; i++) { // 학생
        for(int j=1; j<=5; j++) { // 학년
            int num;
            cin >> num; // 반
            students[i][j] = num;
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=1; j<6; j++) {
            int current_class = students[i][j]; // i 번 학생, 현재 학년에서의 반

            for(int k=0; k<n; k++) {
                if(current_class == students[k][j]) {
                    same_class[i].insert(k+1);
                }
            }
        }
    }

    vector<int> cnt(n,0);
    int max_cnt = 0;
    int index=0;
    for(int i=0; i<n; i++) {
        int count = same_class[i].size();
        if(max_cnt < count) {
            index = i;
            max_cnt = count;
        }
    }


    cout << index+1 << '\n';

    return 0;
}