#include <iostream>
#include <stack>

using namespace std;
bool check(string str) {
    stack<char> s;
    for (int i = 0; i<str.length();i++) {
        char ch = str[i];
        if (ch != '(' && ch != ')' && ch != '[' && ch != ']') continue;
        if (ch == '(') s.push(ch);
        else if (ch == '[') s.push(ch);
        else if (ch == ')') {
            if (s.empty()) return false;
            if (s.top() != '(') return false;
            s.pop();
        }
    }
    return s.empty();
}
int main() {
    string str;
    while (1) {
        cin >> str;
        if (str == ".") break;
        if (check(str)) {
            cout << "yes" << endl;
        }else cout << "no" << endl;
    }
}