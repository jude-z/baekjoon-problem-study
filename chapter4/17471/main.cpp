#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int n;
vector<vector<int>> grid;
vector<int> pops;
vector<int> visited;
vector<int> check_list;
void dfs_node(int idx, vector<int>& v, int type) {
    for (auto node : grid[idx]) {
        if (check_list[node]) continue;
        if (find(v.begin(),v.end(),node) == v.end()) continue;
        check_list[node] = type;
        dfs_node(node,v,type);
    }
}
bool check() {
    vector<int> reds;
    vector<int> blues;
    for (int i = 0;i<n;i++) {
        if (visited[i]) reds.push_back(i);
        else blues.push_back(i);
    }
    if (reds.empty() || blues.empty()) return false;
    check_list = vector<int>(n);
    int start_red_idx = reds[0];
    int start_blue_idx = blues[0];

    check_list[start_red_idx] = 1;
    check_list[start_blue_idx] = 1;

    dfs_node(start_red_idx,reds,1);
    dfs_node(start_blue_idx,blues,2);

    bool flag = true;
    for (auto red : reds) {
        if (!check_list[red]) {
            flag = false;
            break;
        }
    }
    for (auto blue : blues) {
        if (!check_list[blue]) {
            flag = false;
            break;
        }
    }
    return flag;
}
int res = INT_MAX;
void dfs(int depth) {
    if (depth == n) {
        if (check()) {
            int red = 0;
            int blue = 0;
            for (int i = 0;i<n;i++) {
                if (visited[i]) red += pops[i];
                else blue += pops[i];
            }
            res = min(res,abs(red-blue));
        }
        return;
    }
    visited[depth] = 0;
    dfs(depth + 1);
    visited[depth + 1] = 1;
    dfs(depth + 1);

}
int main() {
    grid = vector(n,vector<int>());
    pops = vector<int>(n);
    for (int i = 0;i<n;i++) {
        cin >> pops[i];
    }
    for (int i = 0; i<n;i++) {
        int cnt;
        cin >> cnt;
        for (int j = 0;j<cnt;j++) {
            int temp;
            cin >> temp;
            grid[i].push_back(temp-1);
        }
    }
    dfs(0);
    return 0;
}
