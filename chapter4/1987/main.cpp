#include <iostream>
#include <vector>
#include <bits/atomic_base.h>

using namespace std;

int r,c;
vector<vector<char>> grid;
vector<vector<int>> visited;
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};
int res = 0;
bool check_range(int y, int x) {
    return y>-1 && y<r && x>-1 && x<c;
}
void dfs(int y, int x, int cnt) {
    res = max(res,cnt);
    for (int i = 0;i<4;i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (!check_range(ny,nx)) continue;
        if (visited[ny][nx]) continue;
        if (grid[y][x] == grid[ny][nx]) continue;
        visited[ny][nx] = 1;
        dfs(ny,nx,cnt+1);
        visited[ny][nx] = 0;
    }
}
int main() {
    cin >> r >> c;
    grid = vector(r,vector<char>(c));
    visited = vector(r,vector<int>(c));
    for (int i = 0;i<r;i++) {
        for (int j = 0;j<c;j++) {
            cin >> grid[i][j];
        }
    }
    visited[0][0] = 1;
    dfs(0,0,1);
    cout << res;
}