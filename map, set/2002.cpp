#include <iostream>
#include <map>
#include <vector>

using namespace std;

int outCar(int n, vector<int> &out_car) {

    int result = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(out_car[i] > out_car[j]) {
                result++;
                break;
            }
        }
    }
    return result;
}

int main() {

    int n, num=0;
    cin>> n;

    map<string, int> in_car;
    vector<int> out_car(n, 0);

    for(int i=1; i<=n; i++) {
        string input;
        cin>>input;
        in_car[input] = i;
    }

    for(int i=0; i<n; i++) {
        string input;
        cin>> input;
        out_car[i] = in_car[input];
    }

    cout<< outCar(n, out_car);

    return 0;
}


/*
// 추월한 차가 몇 개인지 구하는 함수
int outCar(int n, vector<string> &out_car, map<string, int> &cars){
    int ans = 0; //몇 개의 차가 추월했는지
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(cars[out_car[i]]>cars[out_car[j]]){
                ans++;
                break;
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<string> out_car(n, "");

    map<string, int> cars;
    string input;
    for (int i = 1; i <= n; i++) {
        cin >> input;
        cars[input] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> out_car[i];
    }
    cout<< outCar(n, out_car, cars);

    return 0;
}*/
