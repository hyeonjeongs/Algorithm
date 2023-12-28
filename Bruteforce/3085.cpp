#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int maxCount = 0;
void rowCandyCount(char candy[51][51], int n) {

    for(int i=0; i<n; i++) {
        int count = 1;
        for(int j=0; j<n; j++){
            if(candy[i][j] == candy[i][j+1]){
                count++;
            }
            else {
                if(count > maxCount){
                    maxCount = count;
                }
                count = 1;
            }
        }
    }
}
void colCandyCount(char candy[51][51], int n) {
    for(int i=0; i<n; i++) {
        int count = 1;
        for(int j=0; j<n; j++){
            if(candy[j][i] == candy[j+1][i]){
                count++;
            }
            else {
                if(count > maxCount){
                    maxCount = count;
                }
                count = 1;
            }
        }
    }
}

int main() {
    int n;
    char candy[51][51];
    cin>>n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>candy[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n-1; j++) {
            swap(candy[i][j], candy[i][j+1]);
            rowCandyCount(candy, n);
            colCandyCount(candy, n);

            swap(candy[i][j+1], candy[i][j]);

            swap(candy[j][i],candy[j+1][i]);
            rowCandyCount(candy, n);
            colCandyCount(candy, n);

            swap(candy[j+1][i], candy[j][i]);
        }
    }

    cout<<maxCount<<'\n';
    return 0;
}