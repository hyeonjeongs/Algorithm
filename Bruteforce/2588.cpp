#include <iostream>
#include <vector>

using namespace std;

int sizeFind(int r, int b, int sum) {
    for (int i = 3; i <= sum / 2; i++) { //길이 최소 3
        if ((sum / i) * i == sum) { //경우의 수 모두 해보기 - 나눠떨어지는 경우
            int j = sum / i;
            int num = i * 2 + j * 2 - 4;
            if (num == r)
                return max(i, j); //항상 L이 큰 수
        }
    }
    return 0;
}

int main() {
    int r, b;
    int length;
    cin >> r >> b;
    int sum = r + b;

    length = sizeFind(r, b, sum); //높이 너비 구하기
    cout<<length<<' '<<sum/length; // L, W 출력

    return 0;
}