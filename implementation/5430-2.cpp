#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    int t;

    cin >> t;

    for(int i=0; i<t; i++) {
        string input, str;
        int n;

        cin >> input;
        cin >> n;
        cin >> str;
        str = str.substr(1, str.length()-2);
        istringstream ss(str);
        string buffer;
        vector<int> arr;
        while(getline(ss, buffer, ',')) {
            arr.push_back(stoi(buffer));
        }
        bool is_forward = true;
        bool is_error = false;

        for(char ch: input) {
            if(ch == 'D') {
                if(arr.size() <=0) {
                    is_error = true;
                    cout << "error"<< '\n';
                    break;
                }
                if(is_forward) {
                    arr.erase(arr.begin());
                } else {
                    arr.pop_back();
                }
            } else {
                is_forward = !is_forward;
            }
        }

        if(!is_error) {
            cout << "[";

            if(is_forward) {
                for(int j=0; j<arr.size(); j++) {
                    if(arr.size()-1 == j) {
                        cout << arr[j];
                    } else {
                        cout << arr[j] << ",";
                    }
                }
            } else {
                for(int j=arr.size()-1; j>=0; j--) {
                    if(j==0) {
                        cout << arr[j];
                    } else {
                        cout << arr[j] << ",";
                    }
                }
            }
            cout << "]" << '\n';

        }


    }
    return 0;
}