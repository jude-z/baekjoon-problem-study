#include <iostream>
#include <stack>

using namespace std;
bool check(string str) {
    stack<char> s;
    for (auto ch : str) {
        if (ch == '(') s.push(ch);
        else if (ch == ')') {
            if (s.empty()) return false;
            s.pop();
        }
    }
    return s.empty();
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        if (check(str)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}