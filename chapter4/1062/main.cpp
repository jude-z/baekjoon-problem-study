#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> v;
vector<int> visited;
int res;
void check() {
    int cnt = 0;
    for (auto str : v) {
        bool flag = true;
        for (char ch : str) {
            if (!visited[ch-'a']) {
                flag = false;
                break;
            }
        }
        if (flag) cnt++;
    }
    res = max(res,cnt);
}
void dfs(int depth, int k) {
    if (k < 5) {
        cout << 0;
        return;
    }
    if (depth == k - 5) {
        check();
    }
    for (int i = 0;i<26;i++) {
        if (!visited[i]) {
            visited[i] = 1;
            dfs(depth + 1,k);
            visited[i] = 0;
        }
    }
}
int main() {
    int n,k;
    cin >> n >> k;
    visited = vector<int>(26);
    visited['a' - 'a'] = 1;
    visited['n' - 'a'] = 1;
    visited['t' - 'a'] = 1;
    visited['i' - 'a'] = 1;
    visited['c' - 'a'] = 1;
    dfs(0,k);

    return 0;
}
