/*
 * 틀린 이유 : visited에 저장된 오리가 다 0값이어야 완전한 string 값인건데 이거를 안해서 틀림
 */

#include <iostream>
#include <vector>

using namespace std;

bool checkDuck(vector<int> &visited, int index) {
    bool current = false;

    for (int i = 0; i < visited.size(); i++) {
        if (visited[i] == index-1) {
            visited[i]=index;
            current = true;
            if(visited[i]== 5) {
                visited[i] = 0;
            }
            break;
        }
    }
    if(!current && index == 1) {
        visited.push_back(index);
    }
    if(!current && index != 1) {
        return false;
    }

    return true;
}

void duckNumber(string input) {
    vector<int> visited;
    bool is_possible = true;

    for (int i = 0; i < input.size(); i++) {

        if (input[i] == 'q') {
            if(!checkDuck(visited, 1)){
                is_possible = false;
                break;
            }
        }
        if (input[i] == 'u') {
            if(!checkDuck(visited, 2)){
                is_possible = false;
                break;
            }
        }
        if (input[i] == 'a') {
            if(!checkDuck(visited, 3)){
                is_possible = false;
                break;
            }
        }
        if (input[i] == 'c') {
            if(!checkDuck(visited, 4)){
                is_possible = false;
                break;
            }
        }
        if (input[i] == 'k') {
            if(!checkDuck(visited, 5)){
                is_possible = false;
                break;
            }
        }
    }

    for(int i=0; i<visited.size(); i++) {
        if(visited[i] != 0){
            is_possible = false;
            break;
        }

    }

    if(visited.size() == 0 || !is_possible) {
        cout<< -1;
        return;
    }
    cout<< visited.size();
}

int main() {
    string input;
    cin >> input;

    duckNumber(input);

    return 0;
}