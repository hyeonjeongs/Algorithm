#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int main() {
    string input;
    string str;
    string str1;
    vector<vector<string>> arr(100001);
    map<string, string> domain;
    map<string, string> dns;
    cin >> input;

    istringstream ss(input);

    int i = 0;
    while (getline(ss, str1, ' ')) {
        arr[i].push_back(str1);
    }


    for (int j = 0; j < arr.size(); j++) {
        if (arr[j][0] == "R") {
            domain[arr[j][1]] = arr[j][2];
            dns[arr[j][2]] = arr[j][1];
        }
        if (arr[j][0] == "S") {
            if (domain.find(arr[j][1]) != domain.end()) {
                cout << domain[arr[j][1]] << '\n';
            } else if (dns.find(arr[j][1]) != dns.end()) {
                cout << dns[arr[j][1]] << '\n';
            } else {
                cout << "not found" << '\n';
            }
        }
        if (arr[j][0] == "A") {
            if (domain.find(arr[j][1]) != domain.end()) {
                cout << domain[arr[j][1]] << '\n';
            }
            if (dns.find(arr[j][1]) != dns.end()) {
                cout << dns[arr[j][1]] << '\n';
            }
        }
    }

}