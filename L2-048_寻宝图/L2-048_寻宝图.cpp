#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> grid(N);
    for (int i = 0; i < N; i++) cin >> grid[i];

    vector<vector<bool>> visited(N, vector<bool>(M, false));
    int total_islands = 0, treasure_islands = 0;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j] && grid[i][j] != '0') {
                total_islands++;
                bool has_treasure = false;
                queue<pair<int,int>> q;
                q.push({i, j});
                visited[i][j] = true;
                if (grid[i][j] >= '2' && grid[i][j] <= '9') has_treasure = true;

                while (!q.empty()) {
                    auto [x, y] = q.front(); q.pop();
                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d], ny = y + dy[d];
                        if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny] && grid[nx][ny] != '0') {
                            visited[nx][ny] = true;
                            if (grid[nx][ny] >= '2' && grid[nx][ny] <= '9') has_treasure = true;
                            q.push({nx, ny});
                        }
                    }
                }
                if (has_treasure) treasure_islands++;
            }
        }
    }

    cout << total_islands << " " << treasure_islands << endl;
    return 0;
}
