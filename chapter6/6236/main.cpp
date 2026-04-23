#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i<n;i++) {
        cin >> v[i];
    }
    int left = 1;
    int right = 0;
    for (int i = 0; i<n;i++) {
        right = max(right,v[i]);
    }
    int res;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cnt = 1;
        int current = 0;
        for (auto money : v) {
            if (current + money > mid) {
                cnt++;
                current = money;
            }else {
                current += money;
            }
        }
        if (cnt <= m) {
            right = mid - 1;
            res = mid;
        }else {
            left = mid + 1;
        }
    }
    cout << res;
}