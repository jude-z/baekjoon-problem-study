#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> graph;
vector<int> visited;
int dfs(int node,int break_node){
    if(node == break_node) return 0;
    if(graph[node].size() == 0) return 1;
    int cnt = 0;
    for(auto c_node : graph[node]){
        cnt += dfs(c_node,break_node);
    }
    return cnt;
}
int main(){
    int n;
    cin >> n;
    graph = vector<vector<int>>(n,vector<int>());
    visited = vector<int>(n);
    int root_node;
    for(int i = 0; i<n;i++){
        int p_node;
        cin >> p_node;
        if(p_node == -1){
            root_node = i;
            continue;
        }
        graph[p_node].push_back(i);
    }
    int break_node;
    cin >> break_node;
    visited[root_node] = 1;
    cout << dfs(root_node,break_node);
    

}