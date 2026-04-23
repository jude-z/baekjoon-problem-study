#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i<n;i++) {
        cin >> v[i];
    }
    ll left = -1;
    ll right = 0;
    for (int i = 0; i<n;i++) {
        right += v[i];
        if (v[i] > left) left = v[i];
    }
    ll res = 0;
    while (left <= right) {
        ll mid = (left + right) / 2;
        ll temp = 0;
        int cnt = 1;
        for (int i = 0; i<n;i++) {
            temp += v[i];
            if (temp > mid) {
                cnt++;
                temp = v[i];
            }
        }
        if (cnt > m) {
            left = mid + 1;
        }else if (cnt <= m) {
            right = mid -1;
            res = mid;
        }
    }
    cout << res;
}