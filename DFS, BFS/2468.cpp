#include <iostream>
#include <vector>

using namespace std;
vector<vector<bool>> visit;
vector<vector<int>> rainH;
int n;
int dx[] ={0,0,-1,1};
int dy[] ={1,-1,0,0};

void reset() {
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            visit[i][j] = false;
        }
    }
}

void dfs(int height, int x, int y){
    visit[y][x] = true;

    for(int i=0; i<4; i++){
        int cur_x =  x+ dx[i];
        int cur_y = y + dy[i];

        if(cur_x>0 && cur_x<=n && cur_y>0 && cur_y<=n && !visit[cur_y][cur_x] && rainH[cur_y][cur_x] > height){
            dfs(height, cur_x, cur_y);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int max_cnt=0;
    int max_num=0;
    cin>>n;

    rainH.assign(n+1, vector<int>(n+1, 0));
    visit.assign(n+1, vector<bool>(n+1,false));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> rainH[i][j];
            max_num = max(max_num, rainH[i][j]);
        }
    }

    /*
     * 문제를 똑바로 읽기..!
     * 높이는 1이상이라해서 k=1부터 시작하는 것으로 했는데
     * 다시 읽어보니 입력받는 것의 높이였음..
     */
    for(int k=0; k<=max_num; k++){ // 높이는 k로 설정
        int num =0;
        reset();

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(!visit[i][j] && rainH[i][j]>k){
                    dfs(k, j, i);
                    num++;
                }
            }
        }
        if(max_cnt < num){
            max_cnt = num;
        }
    }
    cout<< max_cnt;

    return 0;
}