#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> num;
vector<int> result;

void backTracking(int start, int index){

    if(index ==m){
        for(int i=0; i<m; i++){
            cout<< result[i] << " ";
        }
        cout<< '\n';
        return;
        
    }

    for(int i = start; i<num.size(); i++){
        result[index] = num[i];
        backTracking(i, index+1);
    }


}

int main(){

    cin>> n>>m;

    num.assign(n,0);
    result.assign(m,0);

    for(int i=0; i<n; i++){
        cin>> num[i];
    }

    sort(num.begin(), num.end()); // 오름차순

    backTracking(0,0);

    return 0;
}