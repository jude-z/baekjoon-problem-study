#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int get_idx(int val, vector<int>& target) {
    int left = 0;
    int right = target.size() - 1;
    int res = -1;
    while (left <= right) {
        int middle = (left + right)/2;
        if (val >= target[middle]) {
            left = middle + 1;
            res = middle;
        }else if (val < target[middle]) {
            right = middle - 1;
        }
    }
    return res;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int source_cnt,target_cnt;
        cin >> source_cnt >> target_cnt;
        vector<int> source(source_cnt);
        vector<int> target(target_cnt);
        for (int i = 0; i<source_cnt;i++) {
            cin >> source[i];
        }
        for (int i = 0; i<target_cnt;i++) {
            cin >> target[i];
        }
        sort(target.begin(),target.end());
        int res = 0;
        for (auto val : source) {
            res = get_idx(val,target) + 1;
        }
        cout << res << endl;
    }
}