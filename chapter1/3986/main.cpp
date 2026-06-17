#include <iostream>
#include <stack>
using namespace std;
bool check(string str) {
    stack<char> s;
    for (int i = 0; i<str.length();i++) {
        char ch = str[i];
        if (s.empty()) s.push(ch);
        else if (s.top() == ch) s.pop();
        else if (s.top() != ch) s.push(ch);
    }
    return s.empty();
}
int main() {
    int n;
    cin >> n;
    string str;
    for (int i = 0; i<n;i++) {
        cin >> str;
        if (str.length() % 2 == 1) {
            str.erase(str.begin() + str.length() / 2);
        }
        if (check(str)) {

        }
    }
}