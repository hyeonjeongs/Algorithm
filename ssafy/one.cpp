#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int min_num;

void dfs(string input, int count) {
    bool status = true;

    if(input.empty()) {
        return;
    }

    for(int i=1; i<input.size(); i++) {
        if(input[i]=='a') {
            if(input[i-1]=='b') {
                status = false;
                break;
            }
        }
        if(input[i] =='b') {
            if(input[i-1]=='a') {
                status = false;
                break;
            }
        }
    }
    if(status) {
        min_num = min(min_num, count);
    }


    for(int i=0; i<input.size(); i++) {
        string str = input;
        dfs(str.erase(i,1), count+1);
        str = input;
    }

}

int main(int argc, char** argv)
{
    int test_case;
    int T;

    std::ios::sync_with_stdio(false);


    cin >> T;
    for (test_case = 1; test_case <= T; test_case++)
    {

        int n;
        string input;
        cin>>n;
        cin>>input;
        set<char> s;

        min_num = 0;

        for(int i=0;i <n; i++) {
            s.insert(input[i]);
        }

        string str ="";
        for(char a : s) {
            str.push_back(a);
        }

        int result = n - s.size();


        for(int i=1; i<str.size(); i++) {
            if(str[i]=='a') {
                if(str[i-1]=='b') {
                    result++;
                    continue;
                }
            }
            if(str[i] =='b') {
                if(str[i-1]=='a') {
                    result++;
                    continue;
                }
            }
        }

        cout << "#" << test_case << " "<< result <<endl;
    }

    return 0;
}
