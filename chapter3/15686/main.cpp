#include <iostream>
#include <vector>
using namespace std;
int n,m;
int res = INT_MAX;
vector<vector<int>> grid;
vector<pair<int,int>> pizzas;
vector<pair<int,int>> homes;
vector<int> visited;
void dfs(int cnt) {
    if (cnt == pizzas.size() - m) {
        calculate();
        return;
    }
    for (int i = 0; i<visited.size();i++) {
        if (visited[i]) continue;
        visited[i] = 1;
        dfs(cnt + 1);
        visited[i] = 0;
    }

}
int dis(pair<int,int> p1, pair<int,int> p2) {
    return abs(p1.first-p2.first) + abs(p1.second - p2.second);
}
void calculate() {
    vector<pair<int,int>> new_pizzas;
    for (int i = 0; i<visited.size();i++) {
        if (!visited[i]) new_pizzas.push_back(pizzas[i]);
    }
    int val = 0;
    for (auto home : homes) {
        int sub_val = INT_MAX;
        for (int i = 0; i<new_pizzas.size();i++) {
            sub_val = min(sub_val,dis(new_pizzas[i],home));
        }
        val += sub_val;
    }
    res = min(res,val);
}
int main() {
    cin >> n >> m;
    grid = vector(n,vector<int>(m));
    for (int i = 0; i<n;i++) {
        for (int j = 0; j<m;j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) homes.push_back({i,j});
            if (grid[i][j] == 2) pizzas.push_back({i,j});
        }
    }
    visited = vector<int>(pizzas.size());
    dfs(0);
    cout << res;
}
