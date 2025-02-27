#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
vector<int> result;

bool isPrime(int number) {
    if(number<2) {
        return false;
    }
    for(int i=2; i<=sqrt(number); i++) {
        if(number%i==0) {
            return false;
        }
    }
    return true;
}

void backtracking(string number, int cnt) {
    if(!isPrime(stoi(number))) {
        return;
    }
    if(cnt>=n) {
        result.push_back(stoi(number));
        return;
    }
    for(int i=0; i<=9; i++) {
        string news = number + to_string(i)[0];
        backtracking(news, cnt+1);
    }

}
int main() {

    cin >> n;
    for(int i=1; i<=9; i++) {
        backtracking(to_string(i), 1);
    }
    sort(result.begin(), result.end());

    for(int i=0; i<result.size(); i++) {
        cout << result[i]<< '\n';
    }
    return 0;
}