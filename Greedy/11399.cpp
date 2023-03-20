#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minTime(int n, vector<int> p){
    int result =0;
    vector<int> sum(n,0);
    sum[0] = p[0];
    result += sum[0];

    for(int i=1; i<n; i++) {
        sum[i] = sum[i-1] + p[i];
        result += sum[i];
    }
    return result;
}

int main(){
    int n;

    cin>> n;
    vector<int> p(n,0);

    for(int i=0; i<n; i++){
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    cout<<minTime(n, p);

    return 0;
}

/*
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int minAtm(int n, vector<int> atm) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            sum += atm[j];
        }
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> atm(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> atm[i];
    }

    sort(atm.begin(), atm.end());
    cout << minAtm(n, atm);

    return 0;
}*/
