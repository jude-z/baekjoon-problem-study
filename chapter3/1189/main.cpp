#include <iostream>
#include <vector>
using namespace std;

int r,c,k,res;
vector<vector<char>> grid;
vector<vector<int>> visited;
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};
bool check_range(int y, int x) {
    return y > -1 && y < r && x > -1 && x < c;
}
void dfs(int y, int x,int cnt) {
    if (cnt == k) {
        if (y == 0 && x == c -1) res++;
    }
    for (int i = 0; i<4;i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (!check_range(ny,nx)) continue;
        if (grid[ny][nx] == 'T') continue;
        if (visited[ny][nx]) continue;

        visited[ny][nx] = 1;
        dfs(ny,nx,cnt+1);
        visited[ny][nx] = 0;
    }
}
int main() {
    cin >> r >> c >> k;
    grid = vector<vector<char>>(r,vector<char>(c));
    visited = vector<vector<int>>(r,vector<int>(c));
    for (int i = 0; i<r;i++) {
        for (int j= 0; j<c;j++) {
            cin >> grid[i][j];
        }
    }
    visited[r-1][0] = 1;
    dfs(r-1,0,0);
    cout << res;

}