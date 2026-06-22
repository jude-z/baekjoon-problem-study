#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<int>> grid;
vector<vector<int>> id_grid;
vector<vector<int>> visited;

int n,l,r;
bool check_range(int y, int x) {
    return y > -1 && y < n && x > -1 && x < n;
}
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};
pair<int,int> dfs(int y, int x, int id) {
    pair<int,int> cnt_area{1,grid[y][x]};
    for (int i = 0; i<4;i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (!check_range(ny,nx)) continue;
        if (visited[ny][nx]) continue;
        int sub = abs(grid[ny][nx] - grid[y][x]);
        if (sub < l || sub > r) continue;
        visited[ny][nx] = 1;
        id_grid[ny][nx] = id;
        cnt_area.first += dfs(ny,nx,id).first;
        cnt_area.second += dfs(ny,nx,id).second;
    }
    return cnt_area;
}
int main() {
    cin >> n >> l >> r;
    grid = vector(n,vector(n,0));
    for (int i = 0; i<n;i++) {
        for (int j = 0; j<n;j++) {
            cin >> grid[i][j];
        }
    }
    int day = 0;
    while (true) {
        day++;
        id_grid = vector(n,vector(n,0));
        visited = vector(n,vector(n,0));
        map<int,int> id_area_map;
        int id = 0;
        for (int i = 0; i<n;i++) {
            for (int j = 0; j<n;j++) {
                if (!visited[i][j]) {
                    id++;
                    visited[i][j] = 1;
                    id_grid[i][j] = id;
                    pair<int,int> cnt_area = dfs(i,j,id);
                    if (cnt_area.first > 1) {
                        id_area_map[id] = cnt_area.second / cnt_area.first;
                    }
                }

            }
        }
        if (id_area_map.empty()) break;
        for (int i = 0; i<n;i++) {
            for (int j = 0; j<n;j++) {
                int id = id_grid[i][j];
                if (id_area_map[id] > 0) grid[i][j] = id_area_map[id];
            }
        }

    }

    cout << day;


}