#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
vector<int> v;
int k;
map<int,vector<int>> res;
void dfs(int left_idx, int right_idx,int depth) {
    if (depth == k) return;
    int mid_idx = (left_idx + right_idx) / 2;
    res[depth].push_back(v[mid_idx]);
    dfs(left_idx, mid_idx -1,depth + 1);
    dfs(mid_idx+1,right_idx,depth + 1);
}
int main() {
    cin >> k;
    int size = pow(2,k) -1;
    v = vector(size,0);
    for (int i = 0; i<size;i++) {
        cin >> v[i];
    }
    int left_idx = 0;
    int right_idx = v.size() - 1;
    dfs(0,right_idx,0);
    for (auto entry : res) {
        for (auto value : entry.second) {
            cout << value << " ";
        }
        cout << endl;
    }
}