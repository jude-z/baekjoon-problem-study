#include <iostream>
#include <vector>

using namespace std;
int n,l,r;
vector<vector<int>> grid;
vector<vector<int>> visited;
//TODO
int main() {
    cin >> n >> l >> r;
    grid = vector(n,vector<int>(n));
    for (int i = 0; i<n;i++) {
        for (int j = 0; j<n;j++) {
            cin >> grid[i][j];
        }
    }
    int time = 0;
    while (1) {
        time++;
        for (int i = 0; i<n;i++) {
            for (int j = 0; j<n;j++) {

            }
        }
    }
    cout << time -1;

}