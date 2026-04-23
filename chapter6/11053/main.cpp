#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int res[1001];

int main() {
    int n;
    cin >> n;
    v = vector<int>(n);
    for (int i = 0; i<n;i++) {
        cin >> v[i];
    }
    fill(res,res + 1001,1);
    for (int i = 0; i<n;i++) {
        for (int j = 0; j<i;j++) {
            if (v[i] > v[j]) {
                res[i] = max(res[i],res[j] + 1);
            }
        }
    }
    int max_val = -1;
    for (int i = 0; i<n;i++) {
        max_val = max(max_val,res[i]);
    }
    cout << max_val;
}