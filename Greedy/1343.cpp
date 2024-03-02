#include <iostream>
#include <vector>

using namespace std;
vector<char> foliomino;
bool fillFoliomino(int cnt){
    if(cnt%2!=0) {
        return false;
    }
    int fourCnt = cnt/4;
    int twoCnt = (cnt%4)/2;

    for(int i=0; i<fourCnt*4; i++) {
        foliomino.push_back('A');
    }
    for(int i=0; i<twoCnt*2; i++) {
        foliomino.push_back('B');
    }

    foliomino.push_back('.');
    return true;
}

int main() {

    int cnt=0;
    bool isPossible= true;
    while(1){
        char ch;
        cin.get(ch);
        if(!isPossible ||ch == '\n'){
            break;
        }

        if(ch =='.') {
            if(!fillFoliomino(cnt)) {
                isPossible = false;
                cout << -1;
                break;
            }else {
                cnt=0;
            }
        }
        if(ch =='X') {
            cnt++;
        }
    }

    if(!isPossible) {
        return 0;
    }
    if(fillFoliomino(cnt)) {
        for(int i=0; i<foliomino.size()-1; i++) {
            cout<< foliomino[i];
        }
    } else{
        cout <<-1;
    }

    return 0;
}