#include <iostream>
using namespace std;

int cnt[26];

int main() {
    string str;
    cin >> str;
    for (char ch : str) {
        cnt[ch-'a']++;
    }
    for (int val : cnt) {
        cout << val << " ";
    }
}