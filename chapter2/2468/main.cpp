#include <vector>
#include <iostream>

using namespace std;
int n;
vector<vector<int>> grid;
vector<vector<int>> visited;
int res = -1;
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};
bool check_range(int y, int x) {
    return y > -1 && y < n && x > -1 && x < n;
}
void dfs(int y, int x, int height) {
    for (int i = 0; i<4;i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (!check_range(ny,nx)) continue;
        if (grid[ny][nx] <= height) continue;
        if (visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        dfs(ny,nx,height);
    }
}
int main() {
    cin >> n;
    grid = vector<vector<int>>(n,vector<int>(n));
    int max_height = -1;
    for (int i = 0; i<n;i++) {
        for (int j = 0; j<n;j++) {
            cin >> grid[i][j];
            max_height = max(max_height,grid[i][j]);
        }
    }
    for (int i = 0; i<=max_height;i++) {
        int cnt = 0;
        for (int k = 0; k<n;k++) {
            for (int l = 0; l<n;l++) {
                if (grid[k][l] > i && !visited[k][l]) {
                    visited[k][l] = 1;
                    dfs(k,l,i);
                    cnt++;
                }
            }
        }
        res = max(res,cnt);
    }
    cout << res;

}