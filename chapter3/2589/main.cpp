#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<char>> grid;
vector<vector<int>> visited;
vector<pair<int,int>> points;
int n,m;
int res = -1;
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};
bool check_range(int y, int x) {
    return y > -1 && y < n && x > -1 && x < m;
}
void dfs(int cnt);
void calculate();
int main() {
    cin >> n >> m;
    grid = vector(n,vector<char>(m));
    for (int i = 0; i<n;i++) {
        string str;
        cin >> str;
        for (int j = 0; i<m;j++) {
            grid[i][j] = str[j];
        }
    }
    dfs(0);
    cout << res;
}
void dfs(int cnt) {
    if (cnt == 2) {
        calculate();
        return;
    }
    for (int i = 0; i<n;i++) {
        for (int j= 0;j<m;j++) {
            if (grid[i][j] == 'W') continue;
            if (!points.empty()) {
                if (points[0].first == i && points[0].second == j) continue;
            }
            points.push_back({i,j});
            dfs(cnt + 1);
            points.erase(points.begin() + cnt);
        }
    }

}

void calculate() {
    visited = vector(n,vector<int>(m));
    queue<pair<int,int>> q;
    q.push(points[0]);
    visited[points[0].first][points[0].second] = 1;
    while (!q.empty()) {
        pair<int,int> point = q.front();
        q.pop();
        int y = point.first;
        int x = point.second;
        for (int i = 0; i<4;i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!check_range(ny,nx)) continue;
            if (visited[ny][nx]) continue;
            if (grid[ny][nx] == 'W') continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny,nx});
        }
    }
    res = max(res, visited[points[1].first][points[1].second] -1);
}
