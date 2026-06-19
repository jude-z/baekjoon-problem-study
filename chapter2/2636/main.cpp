#include <iostream>
#include <vector>
using namespace std;
int row, col;
vector<vector<int>> grid;
vector<vector<int>> visited;
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};
bool check_range(int y, int x) {
    return y > -1 && y < row && x > -1 && x < col;
}
int melt_cheese(int y, int x) {
    int cnt = 0;
    if (grid[y][x]) return 1;
    for (int i = 0;i<4;i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (!check_range(ny,nx)) continue;
        if (visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        cnt += melt_cheese(ny,nx);
    }
    return cnt;
}
bool check() {
    for (int i = 0;i<row;i++) {
        for (int j = 0;j<col;j++) {
            if (grid[i][j]) return false;
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> row >> col;
    grid = vector(row,vector<int>(col));
    int day = 0;
    int melt_cnt = 0;
    while (1) {
        day++;
        visited[0][0] = 1;
        melt_cnt = melt_cheese(0,0);
        if (check()) break;
    }
    cout << day;
    cout << melt_cnt;
    return 0;
}
