#include <iostream>
#include <vector>

using namespace std;

int dp[100001];
vector<int> v;
int dfs(int num) {
    if (dp[num] > -1) return dp[num];
    int res = v[num];
    res = max(res, dfs(num-1) + v[num]);
    return dp[num] = res;
}
int main() {
    fill(dp, dp + 100001,-1);
    int n;
    cin >> n;
    v = vector<int>(n);
    for (int i = 0; i<n;i++) {
        cin >> v[i];
    }
    dfs(n-1);
    int res = -1;
    for (int i = 0;i<n;i++) {
        res = max(res,dp[i]);
    }
    cout << res;
}