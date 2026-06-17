#include <emmintrin.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i<n;i++) {
        cin >> v[i];
    }
    int cnt = 0;
    sort(v.begin(),v.end());
    int left = 0;
    int right = n-1;
    while (left < right) {
        int sum = v[left] + v[right];
        if (sum >= m) {
            cnt++;
            right--;
        }else {
            left++;
        }
    }
    cout << cnt;

}