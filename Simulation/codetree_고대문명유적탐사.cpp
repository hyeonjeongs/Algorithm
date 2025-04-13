#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pi;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
vector<int> numbers;
int idx = 0;
int coumts = 0;
vector<vector<int>> block;
struct DATA {
    int x;
    int y;
    int spin;
    int cnt;
    vector<pi> nodes;
    vector<vector<int>> block;

    bool operator<(const DATA& data) const {
        if(cnt != data.cnt) {
            return cnt > data.cnt;
        }
        if(spin != data.spin) {
            return spin < data.spin;
        }
        if(x != data.x) {
            return x < data.x;
        }
        return y < data.y;
    }
};

bool cmp(pi a, pi b) {
    if(a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

bool outOfRange(int x, int y){
    return x<0 || x>=5 || y<0 || y>=5;
}

vector<vector<int>> spinRight(int x, int y, vector<vector<int>> spins) {
    vector<vector<int>> news = spins;

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            news[i + y][j + x] = spins[3-1-j + y][i + x];
        }
    }

    return news;
}

vector<pi> bfs(vector<vector<int>> arr) {

    vector<pi> total_nodes;
    vector<vector<bool>> visited(5, vector<bool>(5, false));


    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++) {
            if(visited[i][j]) {
                continue;
            }
            int current = arr[i][j];
            queue<pi> que;
            vector<pi> change_nodes;

            que.push({j, i});
            change_nodes.push_back({j, i}); // x, y
            visited[i][j] = true;

            while(!que.empty()) {
                int cx = que.front().first;
                int cy = que.front().second;
                que.pop();

                for(int k=0; k<4; k++) {
                    int nx = cx + dx[k];
                    int ny = cy + dy[k];

                    if(outOfRange(nx, ny) || visited[ny][nx]) {
                        continue;
                    }
                    if(current == arr[ny][nx]) {

                        change_nodes.push_back({nx, ny});
                        visited[ny][nx] = true;
                        que.push({nx, ny});
                    }
                }
            }
            if(change_nodes.size()>=3) {
                total_nodes.insert(total_nodes.end(), change_nodes.begin(), change_nodes.end());
            }
        }
    }

    return total_nodes;
}

vector<DATA> findMaxNum() {
    vector<DATA> results;
    vector<vector<int>> copy = block;
    for(int i=0; i<=2; i++) {
        for(int j=0; j<=2; j++) {
            vector<vector<int>> spin_block = copy; // 돌아간거 다시원래대로 (가장 큰거 찾기)
            for(int k=0; k<=2; k++) { // 회전 각도 (0,1,2)
                spin_block = spinRight(j, i, spin_block);
                vector<pi> node_data = bfs(spin_block); // 유적개수 카운트
                int sizes = node_data.size();
                if(node_data.size()>=3) {
                    results.push_back({j+1, i+1, k, sizes, node_data, spin_block});
                }
            }
        }
    }
    sort(results.begin(), results.end());
    return results;
}

void getNewNode(DATA data) {
    vector<pi> assigns = data.nodes;
    vector<vector<int>> blocks = data.block;
    sort(assigns.begin(), assigns.end(), cmp);
    int current_idx= idx;
    for(int i=0; i<assigns.size(); i++) {
        blocks[assigns[i].second][assigns[i].first] = numbers[current_idx++];
    }
    idx = current_idx;
    block = blocks;
}

int main() {
    int k, m;
    cin >> k >> m;
    vector<int> answers;


    block.assign(5, vector<int>(5,0));
    numbers.assign(m, 0);
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            cin >> block[i][j];
        }
    }
    for(int i=0; i<m; i++) {
        cin >> numbers[i];
    }
    vector<DATA> copy;

    while(k--) {
        int answer= 0;

        vector<DATA> results = findMaxNum();

        if(results.size()==0) {
            break;
        }
        
        answer+= results[0].cnt; // 유적개수

        getNewNode(results[0]);

        while(true) {
            vector<pi> nodes = bfs(block);
            if(nodes.size()<3){
                break;
            }
            answer += nodes.size(); // 찾아진거있으면
            results[0].nodes = nodes;
            results[0].block = block;
            getNewNode(results[0]);
        }
        answers.push_back(answer);
    }
    for(int i=0; i<answers.size(); i++) {
        cout << answers[i] << " ";
    }
    return 0;
}