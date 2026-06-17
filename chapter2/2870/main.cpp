#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> res;
void check(string str) {
    int len = str.length();
    string num_str = "";
    for (int i = 0; i<len;i++) {
        char ch = str[i];
        if (isalpha(ch)) {
            if (num_str.length() > 0) res.push_back(stoi(num_str));
            num_str = "";
        }else {
            num_str = num_str + ch;
        }
    }
    if (num_str.length() > 0) res.push_back(stoi(num_str));
}
int main() {
    int n;
    string str;
    cin >> n;
    while (n--) {
        cin >> str;
        check(str);
    }
    sort(res.begin(),res.end());
    for (auto val : res) {
        cout << val << " ";
    }
}