#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pi;

int printerQueue(int m, vector<int> num, queue<pi> printer){
    int i=0, cnt =0;
    while(!printer.empty()){
        if(printer.front().second<num[i]){
            int one = printer.front().first;
            int two = printer.front().second;
            printer.pop();
            printer.push({one,two});
        } else if(printer.front().second >= num[i++]){
            cnt++;
            if(m == printer.front().first){
                return cnt;
            }
            printer.pop();
        }
    }

    return cnt;
}

int main(){
    int t;
    int n, m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<int> num;
        queue<pi> printer;

        for(int i=0; i<n; i++){
            int input;
            cin>>input;
            num.push_back(input);
            printer.push({i, input});
        }
        sort(num.begin(), num.end(), greater<>());
        cout<<printerQueue(m, num, printer)<<'\n';
    }
    return 0;
}