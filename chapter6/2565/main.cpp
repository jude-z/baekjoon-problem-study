#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[501];

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for (int i = 0; i<n;i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(),v.end());
    fill(dp, dp + n,1);
    for (int i = 0; i<n;i++) {
        for (int j = 0; j<i;j++) {
            if (v[i].second > v[j].second) {
                dp[i] = max(dp[i],dp[j] + 1);
            }
        }
    }
    int res = 0;
    for (int i = 0; i<n;i++) {
        res = max(res,dp[i]);
    }

    cout << res;

}
