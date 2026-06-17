#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
int res = -1;
vector<int> visited;
vector<vector<int>> graph;
int dfs(int node){
    int cnt = 0;
    for(auto next_node : graph[node]){
        if(visited[next_node]) continue;
        visited[next_node] = 1;
        cnt += dfs(next_node);
    }
    return 1 + cnt;
}
int main(){
    cin >> n >> m;
    graph = vector<vector<int>>(n,vector<int>());
    for(int i = 0; i<m;i++){
        int from, to;
        cin >> from >> to;
        graph[to-1].push_back(from-1);
    }
    vector<int> res_v;
    for(int i = 0; i<n;i++){
        
        visited = vector<int>(n);
        if(dfs(i) > res){
            res_v.clear();
            res = dfs(i);
            res_v.push_back(i);
        }else if(dfs(i) == res){
            res_v.push_back(i);
        }
        sort(res_v.begin(),res_v.end());
        for(auto node : res_v){
            cout << node << " ";
        }
    }
    


}