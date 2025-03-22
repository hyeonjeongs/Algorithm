#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 조합 이용
int main(){
    int n, m;
    vector<bool> arr;

    cin >> n >> m;
    arr.assign(n+1,0);

    for(int i=1; i<=m; i++){
        arr[i] = true;
    }

    do{
        for(int i=1; i<=n; i++){
            if(arr[i]){
                cout<< i <<' ';
            }
        }
        cout<<'\n';

    }while(prev_permutation(arr.begin()+1, arr.end()));
    return 0;
}

/*

// 백트래킹 이용
#include<iostream>
#include<vector>

using namespace std;
const int SIZE = 8;

int n, m;
vector<int> num(SIZE);

void backTracking(int index, int start) {
    if (index == m) {
        for (int i = 0; i < m; i++)
            cout << num[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = start; i <= n; i++) {
        num[index] = i;
        backTracking(index + 1, i + 1); //다음 인덱스 호출
    }
}

int main() {
    cin >> n >> m;
    backTracking(0, 1);

    return 0;
}*/
