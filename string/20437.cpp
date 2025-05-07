#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;


void stringGame(string w, int k) {

    int sizes = w.size();
    vector<bool> visited(sizes, false);

    int mins = sizes+1;
    int maxs = -1;

    for(int i=0; i<w.size(); i++) {
        if(visited[i]) {
            continue;
        }
        int left = i, right = i;
        visited[i] = true;
        int cnt = 0;
        while(right <sizes && left <= right) {
            if(w[left] == w[right]) {
                visited[right] = true;
                cnt++;
                if(cnt < k) { // 아직 같은 수 더 있어야함
                    right++;
                } else { // k 이므로 계산하기
                    if(cnt==k) {
                        mins = min(mins, right-left+1);
                        maxs = max(maxs, right-left+1);
                    }
                    for(int j=left+1; j<=right; j++) {
                        if(w[j] == w[right]) {
                            left = j;
                            break;
                        }
                    }
                    cnt--;
                    right++;
                }
            } else {
                right++;
            }
        }
    }
    if(mins == sizes+1 || maxs==-1){
        cout << -1 << '\n';
    } else {
        cout << mins << " " << maxs << '\n';
    }
}

int main() {

    int t;

    cin >> t;

    string w;
    int k;
    while(t--) {
        cin >> w;
        cin >> k;
        if(k==1) {
            cout << 1 << " " <<1 << '\n';
            continue;
        }
        stringGame(w, k);
    }

    return 0;
}