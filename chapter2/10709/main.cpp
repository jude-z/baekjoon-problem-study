#include <iostream>
#include <queue>
using namespace std;
int n,m;
vector<vector<char>> grid;
vector<vector<int>> visited;
int main() {
    cin >> n >> m;
    grid = vector<vector<char>>(n,vector<char>(m));
    visited = vector<vector<int>>(n,vector<int>(m,-1));
    queue<pair<int,int>> q;
    for (int i = 0; i<n;i++) {
        for (int j = 0; j<m;j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'c') {
                q.push({i,j});
                visited[i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        pair<int,int> pos = q.front();
        q.pop();
        int py = pos.first;
        int px = pos.second;
        int ny = py;
        int nx = px + 1;
        if (!check_range(ny,nx)) continue;
        if (grid[ny][nx] == 'c') continue;
        if (visited[ny][nx] > 0) continue;
        visited[ny][nx] = visited[py][px] + 1;
        q.push({ny,nx});
    }
    for (int i = 0; i<n;i++) {
        for (int j = 0; j<m;j++) {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }

}