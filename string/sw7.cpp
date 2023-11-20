#include <iostream>
#include <vector>

using namespace std;

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

int ddr[] = {1,0,-1,0};
int ddc[] = {0,1,0,-1};

void turnArray(vector <vector<string>> &arr, int n, int w, int depth) {

    for (int i = 0; i < abs(w); i++) {
        bool dir;
        if(w>0) {
            dir = true;
        }else {
            dir = false;
        }
        for (int j = 0; j < depth; j++) {
            string start = arr[j][j];
            int r = j, c = j;
            int way = 0;

            while (way < 4) {
                int new_r, new_c;
                if(dir) {
                    new_r = r + ddr[way];
                    new_c = c + ddc[way];
                }else {
                    new_r = r + dr[way];
                    new_c = c + dc[way];
                }

                if(new_r ==j && new_c == j) {
                    break;
                }
                if (new_r >= j && new_r < n - j && new_c >= j && new_c < n - j) {
                    arr[r][c] = arr[new_r][new_c];
                    r = new_r;
                    c = new_c;
                } else {
                    way++;
                }
            }
            if(dir){
                arr[j][j+1] = start;
            }else {
                arr[j + 1][j] = start;
            }

            dir = !dir;
        }
    }

}

int main() {
    int n, w;
    cin >> n >> w;
    vector <vector<string>> input(n+1, vector<string>(n+1, ""));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> input[i][j];
        }
    }

    turnArray(input, n, w, n/2);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<input[i][j]<<' ';
        }
        cout<<'\n';
    }


    return 0;
}