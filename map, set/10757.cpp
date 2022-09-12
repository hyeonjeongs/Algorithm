#include <iostream>
#include <vector>

using namespace std;

vector<int> plusNum(string a, string b) {
    int a_size = a.size() - 1;
    int b_size = b.size() - 1;
    int carry = 0, num = 0;
    vector<int> sum;

    // 더 작은 자릿수만큼 진행
    while (a_size >= 0 && b_size >= 0) {
        num = (a[a_size--] - '0') + (b[b_size--] - '0') + carry;
        if (num >= 10) {
            num -= 10;
            carry = 1;
        } else
            carry = 0;

        sum.push_back(num);
    }

    //a 자릿수 남아 있는 동안

    while (a_size >= 0) {
        num = (a[a_size--] - '0') + carry;
        if (num >= 10) {
            num -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        sum.push_back(num);
    }


    // b 자릿수 남아 있는 동안

    while (b_size >= 0) {
        num = (b[b_size--] - '0') + carry;
        if (num >= 10) {
            num -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        sum.push_back(num);
    }
    if(carry ==1)
        sum.push_back(1);


    return sum;
}

int main() {
    string a, b;
    cin >> a >> b;

    vector<int> result = plusNum(a, b);

    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i];
    }

    return 0;
}