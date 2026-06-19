#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string a,b;
    cin >> a >> b;
    int a_idx = 1;
    int b_idx = 1;
    int a_len = a.length();
    int b_len = b.length();
    int carry = 0;
    vector<int> v;
    while (1) {
        if (a_len - a_idx >= 0 && b_len - b_idx >= 0) {
            carry = (a[a_len - a_idx] -'0' + b[b_len -b_idx] -'0' + carry) / 10;
            v.push_back((a[a_len - a_idx] -'0' + b[b_len -b_idx] - '0' + carry) % 10);
        }else if (a_len - a_idx >= 0 || b_len - b_idx >= 0){
            if (a_len - a_idx >= 0) {
                v.push_back(a[a_len - a_idx] -'0' + carry);
            }else if (b_len -b_idx >= 0) {
                v.push_back(b[b_len -b_idx] -'0' + carry);
            }
            if (carry != 0) carry = 0;
        }else {
            break;
        }
    }
    for (int i = v.size()-1;i>=0;i--) {
        cout<<v[i];
    }
}