#include <iostream>
#include <vector>
using namespace std;

int r,c;
vector<vector<char>> grid;
vector<vector<int>> visited;
int res;
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};
bool check_range(int y, int x) {
    return y > -1 && y < r && x > -1 && x < c;
}
void dfs(int y, int x,int cnt) {
    res = cnt;
    for (int i = 0; i < 4;i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (!check_range(ny,nx)) continue;
        if (grid[ny][nx] == grid[y][x]) continue;
        if (visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        dfs(ny,nx,cnt+1);
    }
}
int main() {
    grid = vector(r,vector<char>(c));
    visited = vector(r,vector<int>(c));
    for (int i = 0; i<r;i++) {
        for (int j = 0; j< c;j++) {
            cin >> grid[i][j];
        }
    }
    visited[0][0] = 1;
    dfs(0,0,1);
    cout << res;
}