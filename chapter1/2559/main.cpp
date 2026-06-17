#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    vector<int> sum(n);
    for (int i = 0; i<n;i++) {
        cin >> v[i];
    }
    for (int i = 0; i<k;i++) {
        sum[i] += v[i];
    }
    for (int i = 1; i + (k -1) < n;i++) {
        sum[i] = sum[i-1] + v[i + k-1] - v[i-1];
    }
    int res = INT_MIN;
    for (int i = 1; i + (k-1) < n ;i++) {
        res = max(res,sum[i]);
    }
    cout << res;

}