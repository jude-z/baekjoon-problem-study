#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
int r,c;
vector<vector<char>> grid;
vector<vector<int>> visited;
pair<int,int> fire;
pair<int,int> people;
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};
bool check_range(int y, int x) {
    return y > -1 && y < r && x > -1 && x < c;
}
bool check_edge(int y, int x) {
    return y == 0 || y == r-1 || x == 0 || x == c-1;
}
int main() {
    cin >> r >> c;
    grid = vector(r,vector<char>(c));
    visited = vector(r,vector<int>(c));
    for (int i = 0; i<r;i++) {
        for (int j = 0; j<c;j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'F') fire = {i,j};
            if (grid[i][j] == 'J') people = {i,j};
        }
    }
    queue<pair<int,int>> fire_q;
    fire_q.push({fire.first,fire.second});
    visited[fire.first][fire.second] = 1;
    while (!fire_q.empty()) {
        pair<int,int> point = fire_q.front();
        fire_q.pop();
        int y = point.first;
        int x = point.second;
        for (int i = 0; i<4;i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!check_range(ny,nx)) continue;
            if (grid[ny][nx] == '#') continue;
            if (visited[ny][nx]) continue;
            visited[ny][nx] = 1;
            fire_q.push({ny,nx});
        }
    }
    vector<vector<int>> people_visited(r,vector<int>(c));
    queue<pair<int,int>> people_q;
    people_q.push({people.first,people.second});
    people_visited[people.first][people.second] = 1;
    while (!people_q.empty()) {
        pair<int,int> point = people_q.front();
        people_q.pop();
        int y = point.first;
        int x = point.second;
        for (int i = 0; i<4;i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!check_range(ny,nx)) continue;
            if (grid[ny][nx]) continue;;
            if (people_visited[ny][nx]) continue;
            if (people_visited[y][x] + 1 > visited[ny][nx]) continue;
            people_visited[ny][nx] = 1;
            people_q.push({ny,nx});
        }
    }
    int res = INT_MAX;
    for (int i = 0; i<r;i++) {
        for (int j = 0; j<c;j++) {
            if (check_edge(i,j)) res = min(res,people_visited[i][j]);
        }
    }
    cout << res;
}
