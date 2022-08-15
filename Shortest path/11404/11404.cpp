#include<iostream>
#include<vector>

using namespace std;
const int INF = 1e7;

vector<vector<int>> city;
void floydWarshall(int n) {
	int dist;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist = city[i][k] + city[k][j]; // k를 거쳐서 감
				city[i][j] = min(dist, city[i][j]); //k 거쳐간것과 원래 값중에 더 최소값 저장
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n;
	cin >> m;

	city.assign(n+1, vector<int>(n + 1, INF));

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		city[a][b] = min(c, city[a][b]);
	}

	for (int i = 1; i <= n; i++) {
		city[i][i] = 0;
	}

	floydWarshall(n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (city[i][j] == INF) {
				cout << 0 << ' ';
			}
			else {
				cout << city[i][j] << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}