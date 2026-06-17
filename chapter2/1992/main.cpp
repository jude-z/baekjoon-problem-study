#include <vector>
#include <iostream>

using namespace std;
int n;
vector<vector<int>> grid;
string dfs(int y, int x,int size) {
    int value = grid[y][x];
    bool flag = false;
    for (int i = y;i<y + size;i++) {
        for (int j= x;j<x + size;j++) {
            if (value != grid[i][j]) {
                flag = false;
                break;
            }
        }
        if (!flag) break;
    }
    if (flag) return to_string(value);
    return "("
    + dfs(y,x,size/2)
    + dfs(y,x + size/2,size/2)
    + dfs(y+size/2,x,size/2)
    + dfs(y+size/2,x+size/2,size/2)
    + ")";
}
int main() {
    cin >> n;
    grid = vector<vector<int>>(n,vector<int>(n));
    for (int i = 0; i<n;i++) {
        for (int j= 0; j<n;j++) {
            cin >> grid[i][j];
        }
    }
    cout << dfs(n);

}