#include <iostream>
#include <algorithm>
using namespace std;

bool check(string str,string regex, int idx) {
    if (str.length() < regex.length() -1) return false;
    for (int i = 0; i<idx;i++) {
        if (str[i] != regex[i]) return false;
    }
    int str_idx = str.length() -1;
    int reg_idx = regex.length() -1;
    while (reg_idx > idx) {
        if (str[str_idx] != regex[reg_idx]) return false;
        str_idx--;
        reg_idx--;
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    string regex;
    cin >> regex;
    auto it = find(regex.begin(),regex.end(),'*');
    int idx = it - regex.begin();
    for (int i = 0; i<n;i++) {
        string input;
        if (check(input,regex,idx)) cout << "NE";
        else cout << "DA";
    }
}