#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m;
int res = -1;
vector<vector<int>> grid;
vector<vector<int>> visited;
vector<pair<int,int>> start;
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};
bool check_range(int y, int x) {
    return y > -1 && y < n && x > -1 && x < m;
}
int calculate() {
    visited = vector<vector<int>>(n,vector<int>(m));
    queue<pair<int,int>> q;
    for (auto pos : start) {
        visited[pos.first][pos.second] = 1;
        q.push({pos.first,pos.second});
    }
    while (!q.empty()) {
        pair<int,int> pos = q.front();
        q.pop();
        int py = pos.first;
        int px = pos.second;
        for (int i = 0; i<4;i++) {
            int ny = py + dy[i];
            int nx = px + dx[i];
            if (!check_range(ny,nx)) continue;
            if (visited[ny][nx]) continue;
            if (grid[ny][nx] != 0) continue;
            visited[ny][nx] = 1;
            q.push({ny,nx});
        }
    }
    int cnt = 0;
    for (int i = 0; i<n;i++) {
        for (int j = 0; j<m;j++) {
            if (!visited[i][j] && grid[i][j]) cnt++;
        }
    }
    return cnt;
}
void wall(int cnt) {
    if (cnt == 3) {
        res = max(res,calculate());
        return;
    }
    for (int i = 0; i < n;i++) {
        for (int j = 0; j<m;j++) {
            if (!grid[i][j]) {
                grid[i][j] = 1;
                wall(cnt + 1);
                grid[i][j] = 0;
            }
        }
    }
}
int main() {
    cin >> n >> m;
    grid = vector<vector<int>>(n,vector<int>(m));
    for (int i = 0; i<n;i++) {
        for (int j= 0; j<m;j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) start.push_back({i,j});
        }
    }
    wall(0);


}