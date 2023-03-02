#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;
vector<bool> check;
void backTracking(int index){

    if(index == m){
        for(auto i: arr){
            cout<< i<<' ';
        }
        cout<<'\n';
        return;
    }

    for(int i=1; i<=n; i++){
        if(!check[i]){
            arr[index] = i;
            check[i]= true;
            backTracking(index+1);
            check[i] = false;
        }

    }
}

int main(){

    cin>>n>>m;
    arr.assign(m,0);
    check.assign(n+1,false);

    backTracking(0);

    return 0;
}


/*
#include <iostream>
#include <vector>

using namespace std;

int n, m;
bool check[9] ={false,};
vector<int> arr;

void backTracking(int index) {
    if(index == m){
        for(int i=0; i<m; i++){
            cout<<arr[i]<<' ';
        }
        cout << '\n';
        return;
    }

    for(int i=1; i<=n; i++){
        if(!check[i]){
            arr[index] = i;
            check[i] = true;
            backTracking(index+1);
            check[i] = false;
        }
    }

}

int main() {

    cin>> n>> m;

    arr.assign(m+1,0);
    backTracking(0);

    return 0;
}

*/
/*
#include<iostream>
#include<vector>

using namespace std;
const int SIZE = 8;

int n, m;
vector<int> num(SIZE);
vector<bool> check(SIZE, false);

void backTracking(int index) {
    if (index == m) {
        for (int i = 0; i < m; i++)
            cout << num[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!check[i]) {
            num[index] = i;
            check[i] = true;
            backTracking(index + 1); //다음 인덱스 호출
            check[i] = false; //원래 상태로 돌려둠
        }
    }
}

int main() {
    cin >> n >> m;
    backTracking(0);

    return 0;
}*/

