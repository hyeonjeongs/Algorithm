#include <iostream>
#include <vector>

using namespace std;

int main() {
    string str, contains;
    cin >> str;
    cin >> contains;
    int size = contains.size();
    string result = "";

    for (char ch: str) {
        result+=ch;
        if (result.size() >= size) {
            string current = result.substr(result.size()-size, size);
            if (current == contains) {
                result.erase(result.size()-size, size);
            }
        }
    }
    string answer = "FRULA";
    if (result!="") {
        answer = result;
    }
    cout << answer;
    return 0;
}