#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int row,col;
vector<vector<int>> grid;
vector<vector<int>> visited;
vector<vector<int>> rooms;
vector<int> rooms_area;
int area_cnt;
int area_max;
int dy[] = {0,-1,0,1};
int dx[] = {-1,0,1,0};
int res;
bool check_range(int y, int x) {
    return y > -1 && y < row && x > -1 && x < col;
}
int dfs(int y, int x,int id) {
    for (int i = 0;i<4;i++) {
        if (!(grid[y][x] & (int)pow(2,i))) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!check_range(ny,nx)) continue;
            if (visited[ny][nx]) continue;
            visited[ny][nx] = 1;
            dfs(ny,nx,area+1,id);
        }
    }
}
int main() {
    cin >> col >> row;
    grid = vector(row,vector<int>(col));
    visited = vector(row,vector<int>(col));
    rooms = vector(row,vector<int>(col));
    rooms_area = vector<int>(row*col);
    for (int i = 0;i<row;i++) {
        for (int j = 0;j<col;j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0;i<row;i++) {
        for (int j = 0;j<col;j++) {
            visited[i][j] = 1;
            rooms[i][j] = area_cnt;
            int area = dfs(i,j,area_cnt);
            area_max = max(area_max,area);
            rooms_area[area_cnt] = area;
            area_cnt++;
        }
    }
    res = area_max;
    for (int i = 0;i<row;i++) {
        for (int j =0;j<col;j++) {
            for (int k = 0;k<4;k++) {
                if (grid[i][j] & (int)pow(2,k)) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if (rooms[i][j] != rooms[ny][nx]) {
                        res = max(res,rooms_area[rooms[i][j]] + rooms_area[rooms[ny][nx]]);
                    }
                }
            }
        }
    }
    cout << area_cnt << endl;
    cout << area_max << endl;
    cout << res;

}
