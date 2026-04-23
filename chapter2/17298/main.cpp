#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    stack<int> s;
    for (int i = v.size() -1;i>=0;i--) {
        if (s.empty()) {
            cout << -1 << " ";
            s.push(v[i]);
        }else {

        }
    }


}