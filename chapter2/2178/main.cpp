#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n,m;
vector<vector<int>> grid;
vector<vector<int>> visited;
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};
bool check_range(int y, int x){
    return y > -1 && y < n && x > -1 && x < m;
}
int main(){
    cin >> n >> m;    
    vector<vector<int>> grid = vector<vector<int>>(n,vector<int>(m));
    vector<vector<int>> visited = vector<vector<int>>(n,vector<int>(m));

    for(int i = 0; i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    visited[0][0] = 1;
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        pair<int,int> pos = q.front();
        q.pop();
        int py = pos.first;
        int px = pos.second;
        for(int i = 0; i<4;i++){
            int ny = py + dy[i];
            int nx = px + dx[i];
            if(!check_range(ny,nx)) continue;
            if(!grid[ny][nx]) continue;
            if(visited[ny][nx]) continue;

            visited[ny][nx] = visited[py][px] + 1;
            q.push({ny,nx});
        }
    }
    cout << grid[n-1][m-1] - 1;

}