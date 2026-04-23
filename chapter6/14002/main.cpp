#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int res[1001];
int track[1001];
int main() {
    int n;
    cin >> n;
    v = vector<int>(n);
    for (int i = 0; i<n;i++) {
        cin >> v[i];
    }
    fill(res,res + 1001,1);
    fill(track,track + 1001,-1);
    for (int i = 0; i<n;i++) {
        for (int j = 0; j<i;j++) {
            if (v[i] > v[j]) {
                if (res[j] + 1 > res[i]) {
                    res[i] = res[j] + 1;
                    track[i] = j;
                }
            }
        }
    }
    int max_val = -1;
    int max_idx;
    for (int i = 0; i<n;i++) {
        if (res[i] > max_val) {
            max_val = res[i];
            max_idx = i;
        }
    }
    vector<int> track_v;
    int cur = max_idx;
    while (cur != -1) {
        track_v.push_back(v[cur]);
        cur = track[cur];
    }
    reverse(track_v.begin(),track_v.end());
    cout << max_val << endl;
    for (auto val : track_v) {
        cout << val << " ";
    }
}