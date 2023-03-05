#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;
// 왼쪽-1, 오른쪽1, 양쪽0
vector<vector<int>> solution(string image) {
    vector<vector<int>> answer;
    stack<char> st;
    int index=0;
    int cnt = 0;

    for(int i=0; i<image.size(); i++){
        if(image[i]=='<'){
            if(!st.empty() && st.top()=='<'){
                answer.push_back({-1,cnt});

                cnt=0;
                st.pop();
            }
            st.push('<');

        }else if(image[i] =='>'){
            if(!st.empty() &&st.top()=='<'){
                answer.push_back({0,cnt});

                st.pop();
            }else{
                answer.push_back({1,cnt});

            }
            cnt=0;

        }else{
            cnt++;
        }
    }
    if(!st.empty()){
        answer.push_back({-1,cnt});
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<answer[i].size(); j++){
            cout<< answer[i][j]<< ' ';
        }
        cout<<endl;
    }

    return answer;
}