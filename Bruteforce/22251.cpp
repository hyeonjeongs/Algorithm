#include <iostream>
#include <vector>
#include <string>
using namespace std;
int arr[10][10] = {0};
string str;
int n, k, p, x;

int dfs(int dep, int cnt) {
    if(dep >= str.length()) {
        if(stoi(str) == x) return 0;
        if(stoi(str)<=n && stoi(str)>=1) return 1;

        return 0;
    }

    int sum = 0;
    int cur = str[dep] - '0'; // 현재 숫자
    for(int i=0; i<10; i++) {

        if(cur != i && arr[cur][i]<=cnt) {
            str[dep] = i + '0'; // i로 바꾸기
            sum += dfs(dep+1, cnt - arr[cur][i]);
            str[dep] = cur + '0'; // 다시 돌려주기
        }
        if(cur == i) {
            sum += dfs(dep+1, cnt);
        }
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int num[] = { 0b1111110, 0b0110000, 0b1101101, 0b1111001, 0b0110011, 0b1011011, 0b1011111, 0b1110000, 0b1111111, 0b1111011 };

    cin>>n>>k>>p>>x; // 총 n층, k자리수, 반전횟수, 현재 층 수
    str = to_string(x);

    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            int k = num[i] ^ num[j];
            while(k!=0) {
                if(k & 1) {
                    arr[i][j]++;
                }
                k>>=1;
            }
        }
    }
    while(str.length() < k) {
        str.insert(str.begin(), '0');
    }
    cout << dfs(0, p)<<'\n';

    return 0;
}