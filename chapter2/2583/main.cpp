#include <iostream>
#include <vector>
using namespace std;

int n,m,k;
vector<vector<int>> grid;
vector<vector<int>> visited;
bool check_range(int y, int x) {
    return y > -1 && y < n && x > -1 && x < m;
}
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};
int dfs(int y, int x) {
    int area = 1;
    for (int i = 0;i<4;i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (!check_range(ny,nx)) continue;
        if (visited[ny][nx]) continue;
        if (grid[ny][nx]) continue;
        visited[ny][nx] = 1;
        area += dfs(ny,nx);
    }
    return area;
}
int main() {
    cin >> n >> m >> k;
    grid = vector<vector<int>>(n,vector<int>(m));
    while (k--) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x2--;
        y2--;
        for (int i = y1;i<=y2;i++) {
            for (int j = x1;j<=x2;j++) {
                grid[i][j] = 1;
            }
        }
    }
    visited = vector<vector<int>>(n,vector<int>(m));
    int cnt = 0;
    vector<int> res;
    for (int i = 0; i<n;i++) {
        for (int j = 0 ;j<m;j++) {
            if (!grid[i][j]) {
                cnt++;
                visited[i][j] = 1;
                res.push_back(dfs(i,j));
            }
        }
    }

}
