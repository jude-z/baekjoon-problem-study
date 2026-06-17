#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string str;
    cin >> str;
    string new_str;
    new_str = str;
    reverse(new_str.begin(),new_str.end());
    if (str == new_str) cout << 1;
    else cout << 0;
}