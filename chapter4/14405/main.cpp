#include <string>
#include <iostream>
using namespace std;
string str;
bool check_idx(int idx, int dis) {
    return idx + dis < str.length();
}
int main() {
    cin >> str;
    int idx = 0;
    bool flag = true;
    while (idx < str.length()) {
        if (str[idx] == 'p') {
            if (check_idx(idx,1)) {
                flag = false;
                break;
            }
            if (str[idx+1] != 'i') {
                flag = false;
                break;
            }
        }else if (str[idx] == 'k') {
            if (check_idx(idx,1)) {
                flag = false;
                break;
            }
            if (str[idx+1] != 'a') {
                flag = false;
                break;
            }
        }else if (str[idx] == 'c') {
            if (check_idx(idx,2)) {
                flag = false;
                break;
            }
            if (str[idx+1] != 'h' || str[idx+2] != 'u') {
                flag = false;
                break;
            }
        }else {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "YES";
    }else {
        cout << "NO";
    }
}