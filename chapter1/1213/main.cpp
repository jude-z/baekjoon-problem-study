#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string str;
    cin >> str;
    int cnt[26] = {0};
    for (char ch : str) {
        cnt[ch - 'A']++;
    }
    int odd_cnt = 0;
    for (int i = 0; i<26;i++) {
        if (cnt[i] % 2 == 1) odd_cnt++;
    }
    if (odd_cnt > 1) cout << "I'm Sorry Hansoo";
    else {
        string front = "";
        string rear;
        char odd_ch = 0;
        for (int i = 0; i<26;i++) {
            if (cnt[i] % 2 == 0) {
                front = front + string('A' + i,cnt[i] / 2);
            }else {
                odd_ch = 'A' + i;
            }
        }
        front = front + string(odd_ch,cnt[odd_ch- 'A']/2);
        rear = front;
        reverse(rear.begin(),rear.end());
        cout <<  (odd_ch == 0 ? front + rear : front + odd_ch + rear);
    }
}