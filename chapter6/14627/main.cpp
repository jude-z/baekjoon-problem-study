#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i<n;i++) {
        cin >> v[i];
    }
    int left = 1;
    int right = INT_MAX;
    for (int i = 0; i<n;i++) {
        right = min(right,v[i]);
    }
    int res;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cnt = 0;
        for (auto val : v) {
            cnt += val / mid;
        }
        if (cnt >= m) {
            left = mid + 1;
            res = mid;
        }else {
            right = mid - 1;
        }
    }
    cout << res;
}