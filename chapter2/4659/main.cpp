#include <iostream>
#include <format>
using namespace std;
bool check(string str) {
    bool has_vowel = false;
    int cnt = 0;
    char pre_char = 0;
    for (int i = 0; i<str.length();i++) {
        if (pre_char != str[i]) cnt = 1;
        else cnt++;
        if (cnt == 2) {
            if (str[i] == 'e' || str[i] == 'o') continue;
            return false;
        }else if (cnt >= 3) return false;
    }
    if (!has_vowel) return false;
}
int main() {
    string str;
    while (getline(cin,str)) {
        if (check(str)) {
            cout << "<" << str << ">" << " is acceptable." << endl;
        }else {
            cout << "<" << str << ">" << " is not acceptable." << endl;
        }
    }
}