#include <iostream>
#include <queue>

using namespace std;
pair<int,int> visited[100001];
int func(int pos, int type) {
    if (type == 0) return pos + 1;
    if (type == 1) return pos - 1;
    if (type == 2) return pos * 2;
}
bool check_range(int pos) {
    return pos >= 1 && pos <= 100000;
}
int main() {
    int n,k;
    cin >> n >> k;
    visited[n] = {1,1};
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int pos = q.front();
        q.pop();
        for (int i = 0; i<3;i++) {
            int npos = func(pos,i);
            if (!check_range(npos)) continue;
            if (visited[npos].first && visited[npos].first < visited[pos].first + 1) continue;
            if (visited[npos].first && visited[npos].first == visited[pos].first + 1) {
                visited[npos].second++;
                q.push(npos);
            }
            visited[npos] = {1,1};
            q.push(npos);
        }
    }
    cout << visited[k].first << endl << visited[k].second;

}