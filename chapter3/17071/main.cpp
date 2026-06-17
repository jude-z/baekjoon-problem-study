#include <iostream>
#include <queue>
int visited[500001];
using namespace std;
bool check_range(int pos) {
    return pos >= 1 && pos <= 500000;
}
int func(int pos, int type) {
    if (type == 0) return pos - 1;
    else if (type == 1) return pos + 1;
    else if (type == 2) return pos * 2;
}
int main() {
    int n, k;
    cin >> n >> k;
    int time = 0;
    visited[n] = 0;
    queue<int> q;
    q.push(n);
    while (1) {
        time++;
        k += (time)*(time+1)/2;
        if (!check_range(k)) break;
        queue<int> another_q;
        while (!q.empty()) {
            int pos = q.front();
            q.pop();
            for (int i = 0; i < 3;i++) {
                int npos = func(pos,i);
                if (!check_range(npos)) continue;
                if (visited[npos]) continue;
                visited[npos] = visited[pos] + 1;
                another_q.push(npos);
            }
        }
        q = another_q;
    }
    cout << visited[k] - 1;
}