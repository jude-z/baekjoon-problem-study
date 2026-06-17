#include <iostream>
using namespace std;
bool check(int num) {
    if (num % 2 == 0 || num % 5 == 0) return false;
    bool flag = true;
    while (num > 0) {
        if (num % 10 != 1) {
            flag = false;
            break;
        }
        num /= 10;
    }
    return flag;
}
int main() {
    int num;
    while (cin >> num) {
        for (int i = num;;i += num) {
            if (check(i)) {
                cout << i << endl;
                break;
            }
        }
    }
}