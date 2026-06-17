#include <iostream>
#include <vector>

using namespace std;
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};
int n,m,k;
vector<vector<int>> map;
vector<vector<int>> visited;
bool check_range(int y, int x){
    return y > -1 && y < n && x > -1 && x < m;
}
void dfs(int y, int x){
    for(int i = 0; i<4;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(!check_range(ny,nx) && map[ny][nx] == 1 && !visited[ny][nx]){
            visited[ny][nx] = 1;
            dfs(ny,nx);
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> m >> n >> k;
        map = vector<vector<int>>(n,vector<int>(m));
        visited = vector<vector<int>>(n,vector<int>(m));
        for(int i = 0 ;i<k;i++){
            int y, x;
            cin >> x >> y;
            map[y][x] = 1;
        }
        int cnt = 0;
        for(int i = 0; i<n;i++){
            for(int j =0 ;j<m;j++){
                if(!visited[i][j]){
                    cnt++;
                    visited[i][j] = 1;
                    dfs(i,j);
                }
            }   
        }
        cout << cnt << endl;
    }
}