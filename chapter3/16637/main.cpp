#include <iostream>
#include <vector>
using namespace std;
int n;
string str;
vector<char> v;
vector<int> visited;
int max_val = -1;
int cal(int num1, int num2, char oper) {
    switch (oper) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        default:
            exit(-1);
    }
}
int calculate() {
    vector<char> cp = v;
    for (int i = 0; i<n;i++) {
        if (visited[i]) {
            int value = cal(cp[i-1],cp[i+1],cp[i]);
            cp[i-1] = value;
            cp.erase(cp.begin() + i, cp.begin() + i + 2);
        }
    }
    int initial_value = v[0];
    for (int i = 0; i<cp.size();i++) {
        if (!isdigit(cp[i])) initial_value = cal(initial_value,cp[i+1],cp[i]);
    }
    return initial_value;
}
void dfs(int depth) {
    if (depth >= n -1) {
        int res = calculate();
        max_val = max(max_val,res);
        return;
    }
    visited[depth + 1] = 1;
    dfs(depth + 4);
    visited[depth + 1] = 0;
    dfs(depth + 2);

}
int main() {
    cin >> n >> str;
    for (int i = 0; i<n;i++) {
        v[i] = str[i];
    }
    visited = vector<int>(n);
    dfs(0);
    return 0;
}
