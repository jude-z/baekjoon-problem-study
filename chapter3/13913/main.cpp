#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int visited[100001];
int track[100001];
int func(int pos, int type) {
    if (type == 0) return pos - 1;
    else if (type == 1) return pos + 1;
    else if (type == 2) return pos * 2;
}
bool check_range(int pos) {
    return pos > 0 && pos <= 100000;
}
int main() {
    int n,k;
    cin >> n >> k;
    queue<int> q;
    visited[n] = 1;
    track[n] = -1;
    q.push(n);
    while (!q.empty()) {
        int pos = q.front();
        q.pop();
        for (int i = 0; i<3;i++) {
            int npos = func(pos,i);
            if (!check_range(npos)) continue;
            if (visited[npos]) continue;
            visited[npos] = visited[pos] + 1;
            track[npos] = pos;
            q.push(npos);
        }
    }
    cout << visited[k] - 1 << endl;
    vector<int> v;
    int cur = k;
    while (1) {
        if (cur == -1) break;
        v.push_back(cur);
        cur = track[cur];
    }
    reverse(v.begin(),v.end());
    for (auto val : v) {
        cout << val << " ";
    }
}
