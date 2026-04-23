#include <iostream>
#include <vector>
using namespace std;
double dp[10001];
vector<double> v;
double dfs(int num) {
    if (dp[num] > -1.0) return dp[num];
    if (num == 0) {
        return dp[num] = v[num];
    }
    return dp[num] = max(dfs(num-1) * v[num],v[num]);
}
int main() {
    int n;
    cin >> n;
    v = vector<double>(n);
    for (int i = 0; i<n;i++) {
        cin >> v[i];
    }
    fill(dp, dp + 10001,-1.0);
    dfs(v.size() -1);
    double res = 0.0;
    for (int i = 0; i<v.size();i++) {
        res = max(res,dp[i]);
    }
    cout << res;

}