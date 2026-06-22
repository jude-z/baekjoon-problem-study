#include <iostream>
#include <vector>

using namespace std;

int n,m,h;
int row,col;
vector<vector<int>> grid;
int res = INT_MAX;
bool able() {
    for (int i = 1;i<=n;i++) {
        int pos = i;
        for (int j = 1;j<=h;j++) {
            if (grid[j][pos-1]) {
                pos--;
            }else if (grid[j][pos+1]) {
                pos++;
            }
        }
        if (pos != i) return false;
    }
    return true;
}
void dfs(int cnt) {
    if (cnt > 3) return;
    if (able()) res = min(res,cnt);
    for (int i = 0;i<row;i++) {
        for (int j = 0; j<col;j++) {
            if (grid[i][j]) continue;
            if (grid[i-1][j] || grid[i+1][j]) continue;
            if (grid[i][j-1] || grid[i][j+1]) continue;
            grid[i][j] = 1;
            dfs(cnt+1);
            grid[i][j] = 0;
        }
    }
}
int main() {
    cin >> n >> m >> h;
    row = n + 1;
    col = h + 2;
    grid = vector(row,vector<int>(col));
    while (m--) {
        pair<int,int> p;
        cin >> p.first >> p.second;
        grid[p.first][p.second] = 1;
    }
    if (res == INT_MAX) cout << -1;
    else cout << res;
}


