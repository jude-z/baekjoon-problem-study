#include <vector>
#include <iostream>
#include <cmath>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for (int i = 0; i<m;i++) {
        cin >> v[i];
    }
    int left = 1;
    int right = -1;
    for (int i = 0; i<m;i++) {
        right = max(right,v[i]);
    }
    int res = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cnt = 0;
        for (auto jewel : v) {
            cnt += ceil(jewel / mid);
        }
        if (cnt <= n) {
            right = mid -1;
            res = mid;
        }else {
            left = mid + 1;
        }

    }
    cout << res;

}