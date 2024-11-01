#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> makeGame(string str) {
    vector<vector<char>> game(3, vector<char>(3,' '));
    int index= 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++) {
            game[i][j] = str[index++];
        }
    }
    return game;
}
bool isEndGame(vector<vector<char>> game) {
    bool is_end = false;
    bool is_full = true;
    bool is_possible = false;

    int one = 0, two = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++) {
            if(game[i][j] == '.') {
                is_full = false;
            }
            else if(game[i][j] == 'X'){
                one++;
            } else {
                two++;
            }
        }
    }
    if(one== two || (one-two)==1) {
        is_possible = true;
    }


    int o_num = 0;
    int x_num = 0;
    for(int i=0; i<3; i++) {
        if(game[i][0] == game[i][1] && game[i][0] == game[i][2]) {
            if(game[i][0] == '.') {
                continue;
            }
            if(game[i][0] == 'O' && one-two==1) {
                is_possible = false;
            }
            if(is_end && o_num>0) {
                is_possible = false;
            }
            if(is_end && x_num>1) {
                is_possible = false;
            }
            if(game[i][0] == 'X') {
                x_num++;
            }
            if(game[i][0] == 'O'){
                o_num++;
            }
            is_end = true;

        }
        if(game[0][i] == game[1][i] && game[0][i] == game[2][i]) {
            if(game[0][i] == '.') {
                continue;
            }
            if(game[0][i] == 'O' && one-two==1) {
                is_possible = false;
            }

            if(is_end && o_num>0) {
                is_possible = false;
            }
            if(is_end && x_num>1) {
                is_possible = false;
            }
            if(game[0][i] == 'X') {
                x_num++;
            }
            if(game[0][i] == 'O'){
                o_num++;
            }

            is_end = true;

        }
    }
    if(game[0][0] == game[1][1] && game[0][0] == game[2][2] ){
        if(game[0][0] != '.') {
            is_end = true;
        }
        if(game[0][0] == 'O' && one-two==1) {
            is_possible = false;
        }
        if(game[0][0] == 'O' && o_num>0) {
            is_possible = false;
        }

    }
    if(game[0][2] == game[1][1] && game[0][2] == game[2][0] ){
        if(game[0][2] != '.') {
            is_end = true;
        }
        if(game[0][2] == 'O' && one-two==1) {
            is_possible = false;
        }
        if(game[0][2] == 'O' && o_num>0) {
            is_possible = false;
        }
    }

    if(is_possible && (is_end || is_full)) {
        return true;
    }
    return false;
}

int main() {

    vector<vector<char>> game(3, vector<char>(3,' '));
    while(1){

        string str;
        cin >> str;
        if(str == "end") {
            break;
        }

        game = makeGame(str);
        if(isEndGame(game)) {
            cout << "valid" <<'\n';
        }else {
            cout << "invalid" << '\n';
        }
    }

    return 0;
}