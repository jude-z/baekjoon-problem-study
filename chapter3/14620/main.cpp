#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<vector<int>> grid;
vector<vector<int>> visited;
int n;
bool check_range(int y, int x) {
    return !(y == 0 || y == n-1 || x == 0 || x == n-1);
}
bool check_available(int y, int x) {
    return !visited[y][x] && !visited[y-1][x] && !visited[y][x-1] && !visited[y+1][x] && !visited[y][x+1];
}
int res = INT_MAX;
void dfs(int depth) {
    if (depth == 3) {
        int sum = 0;
        for (int i = 0; i<n;i++) {
            for (int j= 0; j<n;j++) {
                if (visited[i][j]) sum += grid[i][j];
            }
        }
        res = min(res,sum);
        return;
    }
    for (int i = 0;i<n;i++) {
        for (int j = 0; j<n;j++) {
            if (!check_range(i,j)) continue;
            if (visited[i][j]) continue;
            if (!check_available(i,j)) continue;
            visited[i][j] = 1;
            visited[i-1][j] = 1;
            visited[i+1][j] = 1;
            visited[i][j-1] = 1;
            visited[i][j+1] = 1;
            dfs(depth + 1);
            visited[i][j] = 0;
            visited[i-1][j] = 0;
            visited[i+1][j] = 0;
            visited[i][j-1] = 0;
            visited[i][j+1] = 0;

        }
    }

}
int main() {
    cin >> n;
    grid = vector(n,vector<int>(n));
    for (int i = 0; i < n;i++) {
        for (int j = 0; j < n;j++) {
            cin >> grid[i][j];
        }
    }
    dfs(0);
}