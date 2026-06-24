#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int row, col;
vector<vector<char>> grid;
vector<vector<int>> visited;
bool check_range(int y, int x) {
    return y > -1 && y < row && x > -1 && x < col;
}
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};
pair<int,int> target;
queue<pair<int,int>> swan_q;
queue<pair<int,int>> next_swan_q;
queue<pair<int,int>> melt_q;
bool can_move() {
    visited = vector(row,vector<int>(col));
    while (!swan_q.empty()) {
        auto [y,x] = swan_q.front();
        swan_q.pop();
        for (int i = 0; i<4;i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!check_range(ny,nx)) continue;
            if (visited[ny][nx]) continue;
            if (ny == target.first && nx == target.second) return true;
            visited[ny][nx] = 1;
            if (grid[ny][nx] == 'X') next_swan_q.push({ny,nx});
            else swan_q.push({ny,nx});
        }
    }
    swan_q = next_swan_q;
    next_swan_q = queue<pair<int,int>>();
    return false;
}
void melt() {
    int size = melt_q.size();
    while (size--) {
        auto [y,x] = melt_q.front();
        melt_q.pop();
        for (int i = 0; i<4;i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!check_range(ny,nx)) continue;
            if (grid[ny][nx] == 'X') {
                grid[ny][nx] = '.';
                melt_q.push({ny,nx});
            }
        }
    }
}
int main() {
    cin >> row >> col;
    grid = vector(row,vector<char>(col));
    for (int i = 0; i<row;i++) {
        for (int j = 0; j<col;j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'L' && swan_q.empty()) {
                visited[i][j] = 1;
                swan_q.push({i,j});
            }
            if (grid[i][j] == 'L' && !swan_q.empty()) target = {i,j};
            if (grid[i][j] != 'X') melt_q.push({i,j});
        }
    }
    int day = 0;
    while (true) {
        if (can_move()) {
            cout << day;
            break;
        }
        melt();
        day++;
    }

}
