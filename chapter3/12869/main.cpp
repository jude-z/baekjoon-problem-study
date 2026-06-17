#include <iostream>
#include <queue>
using namespace std;

int visited[61][61][61];
struct Node {
    int a;
    int b;
    int c;
};
int hp[3];
int attack[6][3] = {
    {9,3,1},
    {9,1,3},
    {3,1,9},
    {3,9,1},
    {1,3,9},
    {1,9,3},
};
int main() {
    int n;
    cin >> n;
    for (int i = 0; i<n;i++) {
        cin >> hp[i];
    }
    Node node{hp[0],hp[1],hp[2]};
    queue<Node> q;
    q.push(node);
    visited[node.a][node.b][node.c] = 1;
    while (!q.empty()) {
        auto [a,b,c] = q.front();
        q.pop();
        for (int i = 0; i<6;i++) {
            int na = max(0,a - attack[i][0]);
            int nb = max(0, b - attack[i][1]);
            int nc = max(0,c - attack[i][2]);
            if (visited[na][nb][nc]) continue;
            visited[na][nb][nc] = visited[a][b][c] + 1;
            q.push({na,nb,nc});
        }
    }
    cout << visited[0][0][0] - 1;
}

