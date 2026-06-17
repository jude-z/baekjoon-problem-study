#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    string str;
    int cnt[26] = {0};
    while (n--) {
        cin >> str;
        cnt[str[0] - 'a']++;
    }
    string res = "";
    for (int i = 0; i<26;i++) {
        if (cnt[i] >= 5) {
            char ch = 'a' + i;
            res = res + ch;
        }
    }
    if (res.length() == 0) cout << "PREJAJA";
    else cout << res;
}