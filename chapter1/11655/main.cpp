#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;
    int len = str.length();
    string res;
    for (int i = 0; i<len;i++) {
        char ch = str[i];
        if (!isalpha(ch)) {
            res = res + ch;
        }
        else if (isupper(ch)) {
            ch += 13;
            int dis = ch -'A';
            ch = 'A' + dis % 26;
        }else if (islower(ch)) {
            ch += 13;
            int dis = ch - 'a';
            ch = 'a' + dis % 26;
        }
        res = res + ch;
    }
    cout << res;
}