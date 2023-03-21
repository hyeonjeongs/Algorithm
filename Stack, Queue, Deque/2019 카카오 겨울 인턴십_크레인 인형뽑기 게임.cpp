/*
 * break문 안써서 시간 많이 씀
 */

#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
void check(stack<int> &st, int &answer) {
    while(st.size() >=2){
        int one = st.top();
        st.pop();
        int two = st.top();

        if(one == two){
            answer+=2;
            st.pop();
        }else{
            st.push(one);
            return;
        }
    }
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int cols = board[0].size();

    stack<int> st;

    for(int i=0; i<moves.size(); i++){
        int num = moves[i]-1;
        for(int j=0; j<cols; j++){
            if(board[j][num]!=0){
                if(!st.empty() && st.top() == board[j][num]){

                    st.pop();
                    answer+=2;
                    check(st, answer);

                }else{
                    st.push(board[j][num]);

                }

                board[j][num] =0;
                break;
            }
        }
    }

    return answer;
}