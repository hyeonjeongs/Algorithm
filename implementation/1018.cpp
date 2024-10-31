#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int checkColor(int i, int j, vector<vector<int>> rectangle) {

    int result = 100;

    for(int n=0; n<2; n++) {
        int count = 0;
         // 0이 흰색, 1은 검정
        int rol = n;

        for(int m=i; m<i+8; m++) {
            rol = (rol+1)%2;
            int current = rol;
            for(int k=j; k<j+8; k++) {
                current = (current+1)%2;
                if(rectangle[m][k] != current) {
                    count++;
                }

            }
        }

        result = min(result, count);
    }

    return result;
}

int main() {
    int n, m;
    cin>> n >>m;
    vector<vector<int>> rectangle(n, vector<int>(m,0));

    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        for(int j=0; j<m; j++) {
            char ch = str[j];
            if(ch=='W') {
                rectangle[i][j] = 0;
            } else {
                rectangle[i][j] = 1;
            }
        }
    }

    int result = 100;
    for(int i=0; i<=n-8; i++) {
        for(int j=0; j<=m-8; j++) {
            result = min(result, checkColor(i, j, rectangle));
        }
    }
    cout << result <<'\n';

    return 0;
}