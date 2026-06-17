#include <iostream>
#include <vector>

using namespace std;
void dfs(int depth,vector<int>& arr);
int k;
vector<vector<int>> res;
vector<char> opers;
int visited[10];
bool check(int num1, int num2, char oper);
int main() {
    cin >> k;
    opers = vector<char>(k);
    for (int i = 0; i<k;i++) {
        cin >> opers[i];
    }
    dfs(0);
    for (auto val : res[0]) {
        cout << val << " ";
    }
    cout << endl;
    for (auto val : res[res.size()-1]) {
        cout << val << " ";
    }
}
void dfs(int depth,vector<int>& arr) {
    if (depth == k) {
        vector<int> v(arr);
        res.push_back(v);
        return;
    }
    else if (depth == 0) {
        for (int i = 0; i<10;i++) {
            visited[i] = 1;
            arr.push_back(i);
            dfs(depth + 1, arr);
            arr.erase(arr.begin() + depth);
            visited[i] = 0;
        }
    }else{
        for (int i = 0; i<10;i++) {
            if (visited[i]) continue;
            if (!check(arr[depth-1],i,opers[i-1])) continue;
            visited[i] = 1;
            arr.push_back(i);
            dfs(depth+1,arr);
            arr.erase(arr.begin() + depth);
            visited[i] = 0;
        }
    }
}
bool check(int num1, int num2, char oper) {
    if (oper == '<') {
        return num1 < num2;
    }else if (oper == '>') {
        return num1 > num2;
    }
}